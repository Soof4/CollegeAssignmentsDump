// IDepartment.cs

namespace HealthFacility
{
    public interface IDepartment
    {
        public void ShowInfo();
        public void Open();
        public void Close();
    }
}


// ICompositeDepartment.cs

namespace HealthFacility
{
    public interface ICompositeDepartment
    {
        public void AddDepartment(IDepartment department);
        public void AddDepartments(IEnumerable<IDepartment> departments);
        public void RemoveDepartment(IDepartment department);
        public void RemoveDepartment(int index);
        public IEnumerable<IDepartment> GetDepartments();
        public void ListDeparments();
    }
}


// AbstractDepartment.cs

namespace HealthFacility
{
    public abstract class AbstractDepartment : IDepartment
    {
        protected int ID { get; set; }
        protected string Name { get; set; }
        protected bool IsOpen { get; set; }

        public AbstractDepartment(string name, int id, bool isOpen)
        {
            ID = id;
            Name = name;
            IsOpen = isOpen;
        }

        public void Close()
        {
            IsOpen = false;
            Console.WriteLine($"{Name} has been closed.");
        }

        public void Open()
        {
            IsOpen = true;
            Console.WriteLine($"{Name} has been opened.");

        }

        public abstract void ShowInfo();

        public override string ToString()
        {
            return $"ID: {ID} - Name: {Name}";
        }
    }
}


// Polyclinic.cs


namespace HealthFacility
{
    public class Polyclinic : AbstractDepartment, ICompositeDepartment
    {
        protected List<IDepartment> Departments { get; set; } = new List<IDepartment>();
        protected List<Doctor> Doctors { get; set; } = new List<Doctor>();
        protected List<Nurse> Nurses { get; set; } = new List<Nurse>();

        public Polyclinic(string name, int id, bool isOpen) : base(name, id, isOpen) { }


        public void AddDepartment(IDepartment department)
        {
            Departments.Add(department);
        }

        public void AddDepartments(IEnumerable<IDepartment> departments)
        {
            Departments = Departments.Concat(departments).ToList();
        }

        public IEnumerable<IDepartment> GetDepartments()
        {
            return Departments;
        }

        public void ListDeparments()
        {
            Departments.ForEach(d => Console.WriteLine(d));
        }

        public void RemoveDepartment(IDepartment department)
        {
            Departments.Remove(department);
        }

        public void RemoveDepartment(int index)
        {
            Departments.RemoveAt(index);
        }

        public override void ShowInfo()
        {
            List<string?> result = new List<string?>() {
                ToString(),
                $"Department count: {Departments.Count}",
                "List of departments:"
            };

            Departments.ForEach(d => result.Add(d.ToString()));

            Utils.PrintAsBox(result);
        }

        public void AddDoctor(Doctor doctor)
        {
            Doctors.Add(doctor);
        }

        public void AddNurse(Nurse nurse)
        {
            Nurses.Add(nurse);
        }
    }
}


// Laboratory.cs

namespace HealthFacility
{
    public class Laboratory : AbstractDepartment
    {
        private int EquipmentCount { get; set; }

        public Laboratory(string name, int id, bool isOpen, int equipmentCount) : base(name, id, isOpen)
        {
            EquipmentCount = equipmentCount;
        }

        public override void ShowInfo()
        {
            List<string> result = new List<string>() {
                ToString(),
                $"Equipment count: {EquipmentCount}"
            };

            Utils.PrintAsBox(result);
        }
    }
}


// PatientRoom.cs

namespace HealthFacility
{
    public class PatientRoom : AbstractDepartment
    {
        private int BedCount { get; set; }

        public PatientRoom(string name, int id, bool isOpen, int bedCount) : base(name, id, isOpen)
        {
            BedCount = bedCount;
        }

        public override void ShowInfo()
        {
            List<string> result = new List<string>() {
                ToString(),
                $"Bed count: {BedCount}"
            };

            Utils.PrintAsBox(result);
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
