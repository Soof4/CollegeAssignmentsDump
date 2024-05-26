// IAppointment.cs

namespace HealthFacility
{
    public interface IAppointment
    {
        public void Execute();
        public void Undo();
        public void Redo();
        public List<IAppointment> GetAppointments();
        public void SetPatient(Patient patient);
        public void SetDoctor(Doctor doctor);
        public void SetDateTime(DateTime dateTime);
    }
}


// AbstractAppointment.cs

namespace HealthFacility
{
    public abstract class AbstractAppointment : IAppointment
    {
        protected int ID;
        protected Patient? _patient;
        protected Doctor? _doctor;
        protected DateTime _dateTime;

        public abstract void Execute();

        public List<IAppointment> GetAppointments()
        {
            return _patient?.Appointments ?? new List<IAppointment>();  // return an empty list if _patient is null
        }

        public void Redo()
        {
            Execute();
        }

        public void SetDoctor(Doctor doctor)
        {
            _doctor = doctor;
        }

        public void SetPatient(Patient patient)
        {
            _patient = patient;
        }

        public void SetDateTime(DateTime dateTime)
        {
            _dateTime = dateTime;
        }

        public abstract void Undo();
    }
}


// Create.cs

namespace HealthFacility
{
    public class Create : AbstractAppointment
    {
        public override void Execute()
        {
            if (_patient == null || _doctor == null) return;
            
            DatabaseManager db = new DatabaseManager();
            db.InsertAppointment(_patient.ID, _doctor.ID, _dateTime.ToString());

            Console.WriteLine("Appointment has been created.");
        }

        public override void Undo()
        {
            if (_patient == null || _doctor == null) return;

            DatabaseManager db = new DatabaseManager();
            AppointmentInfo? info = db.GetAppointmentInfo(_patient.ID, _doctor.ID, _dateTime);

            if (info == null) return;
            
            db.DeleteAppointment(info.ID);

            Console.WriteLine("Appointment creation has been undone.");
        }
    }
}


// ChangeTime.cs

namespace HealthFacility
{
    public class ChangeTime : AbstractAppointment
    {
        private DateTime prevDateTime;
        public override void Execute()
        {
            if (_patient == null || _doctor == null) return;

            prevDateTime = _dateTime;
            DatabaseManager db = new DatabaseManager();
            db.UpdateAppointment(ID, _patient.ID, _doctor.ID, _dateTime.ToString());

            Console.WriteLine("Appointment time has been changed.");

        }

        public override void Undo()
        {
            if (_patient == null || _doctor == null) return;

            DatabaseManager db = new DatabaseManager();
            db.UpdateAppointment(ID, _patient.ID, _doctor.ID, prevDateTime.ToString());

            Console.WriteLine("Appointment time change has been undone.");
        }

        public void SetTime(DateTime dateTime)
        {
            _dateTime = dateTime;
        }
    }
}


// Cancel.cs

namespace HealthFacility
{
    public class Cancel : AbstractAppointment
    {
        public override void Execute()
        {
            if (_patient == null || _doctor == null) return;

            DatabaseManager db = new DatabaseManager();
            db.DeleteAppointment(ID);

            Console.WriteLine("Appointment has been cancelled.");
        }

        public override void Undo()
        {
            if (_patient == null || _doctor == null) return;

            DatabaseManager db = new DatabaseManager();
            db.InsertAppointment(_patient.ID, _doctor.ID, _dateTime.ToString());

            AppointmentInfo? info = db.GetAppointmentInfo(_patient.ID, _doctor.ID, _dateTime);

            if (info == null) return;
            
            ID = info.ID;

            Console.WriteLine("Appointment cancellation has been undone.");
        }
    }
}


// Program.cs

﻿namespace HealthFacility
{
    public class Program
    {
        public static DatabaseManager dbManager = new DatabaseManager();
        public static void Main(string[] args)
        {
            Console.WriteLine("\n\n\n");
            Console.WriteLine("---- Facade ----");
            TestFacade();

            Console.WriteLine("\n\n\n");
            Console.WriteLine("---- Composite ----");
            TestComposite();

            Console.WriteLine("\n\n\n");
            Console.WriteLine("---- Strategy ----");
            TestStrategy();

            Console.WriteLine("\n\n\n");
            Console.WriteLine("---- Command ----");
            TestCommand();
        }

        public static void TestFacade()
        {
            HealthFacility facility = new HealthFacility();
            facility.Initialize();
        }

        public static void TestComposite()
        {
            Polyclinic clinic = (Polyclinic)dbManager.GetAllPolyclinics()[0];

            IDepartment dep1 = dbManager.GetDepartment(1)!;
            IDepartment dep2 = dbManager.GetDepartment(2)!;
            IDepartment dep3 = dbManager.GetDepartment(3)!;
            IDepartment dep4 = dbManager.GetDepartment(4)!;

            clinic.AddDepartment(dep1);
            clinic.AddDepartment(dep2);
            clinic.AddDepartment(dep3);
            clinic.AddDepartment(dep4);

            clinic.Open();

            clinic.ShowInfo();

            clinic.Close();
        }

        public static void TestStrategy()
        {
            PaymentContext payCon = new PaymentContext();

            Doctor dr = dbManager.GetDoctor(1)!;
            Nurse nr = dbManager.GetNurse(1)!;
            Surgeon sr = dbManager.GetSurgeon(1)!;

            payCon.PaySalary(dr, 5);
            payCon.PaySalary(nr, 5);
            payCon.PaySalary(sr, 5);

            payCon.PayBonus(dr, 1000);
            payCon.PayBonus(nr, 5000);
            payCon.PayBonus(sr, 15000);
        }

        public static void TestCommand()
        {
            Patient patient = dbManager.GetPatient(1)!;
            Doctor dr = dbManager.GetDoctor(1)!;

            IAppointment app = new Create();
            app.SetPatient(patient);
            app.SetDoctor(dr);
            app.SetDateTime(DateTime.Today);
            
            app.Execute();
            app.Undo();
            app.Redo();
        }
    }
}
