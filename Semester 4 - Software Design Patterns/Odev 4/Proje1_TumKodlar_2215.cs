// HealthFacility.cs

namespace HealthFacility
{
    public class HealthFacility
    {
        private List<IDepartment> Departments { get; set; }
        private List<SurgeryRoom> SurgeryRooms { get; set; }
        private DatabaseManager DBManager { get; set; }
        private PaymentContext PaymentContext { get; set; }

        public HealthFacility()
        {
            Departments = new List<IDepartment>();
            SurgeryRooms = new List<SurgeryRoom>();
            DBManager = new DatabaseManager();
            PaymentContext = new PaymentContext();
        }
        public void Initialize()
        {
            Departments = DBManager.GetAllPolyclinics();

            foreach (var dep in Departments)
            {
                dep.Open();
            }

            Console.WriteLine("All departments are now open.");

            SurgeryRooms = DBManager.GetAllSurgeryRooms();

            foreach (var sr in SurgeryRooms)
            {
                sr.IsClean = true;
                DBManager.UpdateSurgeryRoom(sr.ID, sr.Name, sr.IsClean ? 1 : 0);
            }

            Console.WriteLine("All surgery rooms are now clean.");

            PaymentContext = new PaymentContext();
            
            Console.WriteLine("Payment system is now active.");
        }
    }
}


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


// SurgeryRoom.cs

namespace HealthFacility
{
    public class SurgeryRoom
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public bool IsClean { get; set; }
        public SurgeryRoom(int id, string name, bool isClean)
        {
            ID = id;
            Name = name;
            IsClean = isClean;
        }

        public void ShowInfo()
        {
            List<string> result = new List<string>() {
                ToString()
            };

            Utils.PrintAsBox(result);
        }

        public override string ToString()
        {
            return $"ID: {ID} - Name: {Name}";
        }
    }
}


// DatabaseManager.cs

using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class DatabaseManager
    {
        private static SQLiteConnection _db = new SQLiteConnection("DataSource=./HealthFacility.db;Version=3;");

        public DatabaseManager()
        {
            try
            {
                _db.Open();
            }
            catch { }

            TryExecuteScalarCommand("CREATE TABLE Doctors (" +
                                    "DoctorID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Name TEXT NOT NULL, " +
                                    "Surname TEXT NOT NULL, " +
                                    "Salary REAL DEFAULT 0" +
                                    ")");

            TryExecuteScalarCommand("CREATE TABLE Surgeons (" +
                                    "SurgeonID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Name TEXT NOT NULL, " +
                                    "Surname TEXT NOT NULL, " +
                                    "Salary REAL DEFAULT 0" +
                                    ")");

            TryExecuteScalarCommand("CREATE TABLE Nurses (" +
                                    "NurseID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Name TEXT NOT NULL, " +
                                    "Surname TEXT NOT NULL, " +
                                    "Salary REAL DEFAULT 0" +
                                    ")");

            TryExecuteScalarCommand("CREATE TABLE Departments (" +
                                    "DepartmentID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Name TEXT NOT NULL, " +
                                    "IsOpen INTEGER NOT NULL DEFAULT 0, " +
                                    "DepartmentType INTEGER NOT NULL, " +
                                    "ExtraInfo TEXT" +
                                    ")");

            TryExecuteScalarCommand("CREATE TABLE SurgeryRooms (" +
                                    "SurgeryRoomID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Name TEXT NOT NULL, " +
                                    "IsClean INTEGER NOT NULL DEFAULT 0" +
                                    ")");

            TryExecuteScalarCommand("CREATE TABLE Patients (" +
                                    "PatientID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Name TEXT NOT NULL, " +
                                    "Surname TEXT NOT NULL" +
                                    ")");

            TryExecuteScalarCommand("CREATE TABLE Appointments (" +
                                    "AppointmentID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "PatientID INTEGER NOT NULL, " +
                                    "DoctorID INTEGER NOT NULL, " +
                                    "DateTime TEXT NOT NULL, " +
                                    "CONSTRAINT PatientConstraint FOREIGN KEY (PatientID) REFERENCES Patients (PatientID) " +
                                    "ON DELETE CASCADE ON UPDATE CASCADE, " +
                                    "CONSTRAINT DoctorConstraint FOREIGN KEY (DoctorID) REFERENCES Doctors (DoctorID) " +
                                    "ON DELETE CASCADE ON UPDATE CASCADE" +
                                    ")");
        }

        #region Doctor Management 
        public void InsertDoctor(string name, string surname, double salary)
        {
            ExecuteScalarCommand("INSERT INTO Doctors (Name, Surname, Salary) VALUES (@0, @1, @2)",
                                 name, surname, salary);
        }

        public void DeleteDoctor(int id)
        {
            ExecuteScalarCommand("DELETE FROM Doctors WHERE DoctorID = @0", id);
        }

        public void UpdateDoctor(int id, string name, string surname, double salary)
        {
            ExecuteScalarCommand("UPDATE Doctors SET Name = @0, Surname = @1, Salary = @2 WHERE DoctorID = @3",
                                 name, surname, salary);
        }

        public Doctor? GetDoctor(int id)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM Doctors WHERE DoctorID = @0", id))
            {
                while (reader.Read())
                {
                    return new Doctor((int)reader.GetInt64("DoctorID"),
                                      reader.GetString("Name"),
                                      reader.GetString("Surname"),
                                      reader.GetDouble("Salary")
                                      );
                }
            }
            return null;
        }

        public List<Doctor> GetAllDoctors()
        {
            List<Doctor> list = new List<Doctor>();

            using (var reader = ExecuteReaderCommand("SELECT * FROM Doctors"))
            {
                while (reader.Read())
                {
                    list.Add(new Doctor((int)reader.GetInt64("DoctorID"),
                                      reader.GetString("Name"),
                                      reader.GetString("Surname"),
                                      reader.GetDouble("Salary")
                                      ));
                }
            }

            return list;
        }
        #endregion

        #region Surgeon Management
        public void InsertSurgeon(string name, string surname, double salary)
        {
            ExecuteScalarCommand("INSERT INTO Surgeons (Name, Surname, Salary) VALUES (@0, @1, @2)",
                                 name, surname, salary);
        }

        public void DeleteSurgeon(int id)
        {
            ExecuteScalarCommand("DELETE FROM Surgeons WHERE SurgeonID = @0", id);
        }

        public void UpdateSurgeon(int id, string name, string surname, double salary)
        {
            ExecuteScalarCommand("UPDATE Surgeons SET Name = @0, Surname = @1, Salary = @2 WHERE SurgeonID = @3",
                                 name, surname, salary);
        }

        public Surgeon? GetSurgeon(int id)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM Surgeons WHERE SurgeonID = @0", id))
            {
                while (reader.Read())
                {
                    return new Surgeon((int)reader.GetInt64("SurgeonID"),
                                      reader.GetString("Name"),
                                      reader.GetString("Surname"),
                                      reader.GetDouble("Salary")
                                      );
                }
            }
            return null;
        }

        public List<Surgeon> GetAllSurgeons()
        {
            List<Surgeon> list = new List<Surgeon>();

            using (var reader = ExecuteReaderCommand("SELECT * FROM Surgeons"))
            {
                while (reader.Read())
                {
                    list.Add(new Surgeon((int)reader.GetInt64("SurgeonID"),
                                      reader.GetString("Name"),
                                      reader.GetString("Surname"),
                                      reader.GetDouble("Salary")
                                      ));
                }
            }

            return list;
        }
        #endregion

        #region Nurse Management
        public void InsertNurse(string name, string surname, double salary)
        {
            ExecuteScalarCommand("INSERT INTO Nurses (Name, Surname, Salary) VALUES (@0, @1, @2)",
                                 name, surname, salary);
        }

        public void DeleteNurse(int id)
        {
            ExecuteScalarCommand("DELETE FROM Nurses WHERE NurseID = @0", id);
        }

        public void UpdateNurse(int id, string name, string surname, double salary)
        {
            ExecuteScalarCommand("UPDATE Nurses SET Name = @0, Surname = @1, Salary = @2 WHERE NurseID = @3",
                                 name, surname, salary);
        }

        public Nurse? GetNurse(int id)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM Nurses WHERE NurseID = @0", id))
            {
                while (reader.Read())
                {
                    return new Nurse((int)reader.GetInt64("NurseID"),
                                      reader.GetString("Name"),
                                      reader.GetString("Surname"),
                                      reader.GetDouble("Salary")
                                      );
                }
            }
            return null;
        }

        public List<Nurse> GetAllNurses()
        {
            List<Nurse> list = new List<Nurse>();

            using (var reader = ExecuteReaderCommand("SELECT * FROM Nurses"))
            {
                while (reader.Read())
                {
                    list.Add(new Nurse((int)reader.GetInt64("NurseID"),
                                      reader.GetString("Name"),
                                      reader.GetString("Surname"),
                                      reader.GetDouble("Salary")
                                      ));
                }
            }

            return list;
        }
        #endregion

        #region SurgeryRoom Management
        public void InsertSurgeryRoom(string name, int isClean)
        {
            ExecuteScalarCommand("INSERT INTO SurgeryRooms (Name, IsClean) VALUES (@0, @1)",
                                 name, isClean);
        }

        public void DeleteSurgeryRoom(int id)
        {
            ExecuteScalarCommand("DELETE FROM SurgeryRooms WHERE SurgeryRoomID = @0", id);
        }

        public void UpdateSurgeryRoom(int id, string name, int isClean)
        {
            ExecuteScalarCommand("UPDATE SurgeryRooms SET Name = @0, IsClean = @1 WHERE SurgeryRoomID = @2",
                                 name, isClean, id);
        }

        public SurgeryRoom? GetSurgeryRoom(int id)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM SurgeryRooms WHERE SurgeryRoomID = @0", id))
            {
                while (reader.Read())
                {
                    return new SurgeryRoom((int)reader.GetInt64("SurgeryRoomID"),
                                           reader.GetString("Name"),
                                           reader.GetInt64("IsClean") == 1);
                }
            }
            return null;
        }

        public List<SurgeryRoom> GetAllSurgeryRooms()
        {
            List<SurgeryRoom> list = new List<SurgeryRoom>();

            using (var reader = ExecuteReaderCommand("SELECT * FROM SurgeryRooms"))
            {
                while (reader.Read())
                {
                    list.Add(new SurgeryRoom((int)reader.GetInt64("SurgeryRoomID"),
                                             reader.GetString("Name"),
                                             reader.GetInt64("IsClean") == 1));
                }
            }

            return list;
        }
        #endregion

        #region Department Management
        public void InsertDepartment(string name, int isOpen, int departmentType, string extraInfo)
        {
            ExecuteScalarCommand("INSERT INTO Departments (Name, IsOpen, DepartmentType, ExtraInfo) VALUES (@0, @1, @2, @3)",
                                 name, isOpen, departmentType, extraInfo);
        }

        public void DeleteDepartment(int id)
        {
            ExecuteScalarCommand("DELETE FROM Departments WHERE DepartmentID = @0", id);
        }

        public void UpdateDepartment(int id, string name, int isOpen, int departmentType, string extraInfo)
        {
            ExecuteScalarCommand("UPDATE Departments SET Name = @0, IsOpen = @1, DepartmentType = @2, ExtraInfo = @3 WHERE DepartmentID = @4",
                                 name, isOpen, departmentType, extraInfo, id);
        }

        public IDepartment? GetDepartment(int id)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM Departments WHERE DepartmentID = @0", id))
            {
                while (reader.Read())
                {
                    switch ((DepartmentType)reader.GetInt64("DepartmentType"))
                    {
                        case DepartmentType.Polyclinic:
                            {
                                Polyclinic clinic = new Polyclinic(reader.GetString("Name"),
                                                                   (int)reader.GetInt64("DepartmentID"),
                                                                   reader.GetInt64("IsOpen") == 1
                                                                   );
                                string[] extraInfos = reader.GetString("ExtraInfo").Split(":");
                                int[] depIds = extraInfos[0].Split(",").Select(str => int.Parse(str)).ToArray();

                                foreach (int i in depIds)
                                {
                                    IDepartment? dep = GetDepartment(i);
                                    if (dep != null) clinic.AddDepartment(dep);
                                }

                                int[] docIds = extraInfos[1].Split(",").Select(str => int.Parse(str)).ToArray();

                                foreach (int i in docIds)
                                {
                                    Doctor? doc = GetDoctor(i);
                                    if (doc != null) clinic.AddDoctor(doc);
                                }

                                int[] nurIds = extraInfos[2].Split(",").Select(str => int.Parse(str)).ToArray();

                                foreach (int i in depIds)
                                {
                                    Nurse? nur = GetNurse(i);
                                    if (nur != null) clinic.AddNurse(nur);
                                }

                                return clinic;
                            }
                        case DepartmentType.Laboratory:
                            {
                                return new Laboratory(reader.GetString("Name"),
                                                      (int)reader.GetInt64("DepartmentID"),
                                                      reader.GetInt64("IsOpen") == 1,
                                                      int.Parse(reader.GetString("ExtraInfo")
                                                      ));
                            }
                        case DepartmentType.PatientRoom:
                            {
                                return new Laboratory(reader.GetString("Name"),
                                                      (int)reader.GetInt64("DepartmentID"),
                                                      reader.GetInt64("IsOpen") == 1,
                                                      int.Parse(reader.GetString("ExtraInfo")
                                                      ));
                            }
                    }
                }
            }
            return null;
        }


        public List<IDepartment> GetAllPolyclinics()
        {
            List<IDepartment> list = new List<IDepartment>();
            using (var reader = ExecuteReaderCommand("SELECT * FROM Departments"))
            {
                while (reader.Read())
                {
                    if ((DepartmentType)reader.GetInt64("DepartmentType") == DepartmentType.Polyclinic)
                    {

                        Polyclinic clinic = new Polyclinic(reader.GetString("Name"),
                                                                   (int)reader.GetInt64("DepartmentID"),
                                                                   reader.GetInt64("IsOpen") == 1
                                                                   );
                        string[] extraInfos = reader.GetString("ExtraInfo").Split(":");
                        int[] depIds = extraInfos[0].Split(",").Select(str => int.Parse(str)).ToArray();

                        foreach (int i in depIds)
                        {
                            IDepartment? dep = GetDepartment(i);
                            if (dep != null) clinic.AddDepartment(dep);
                        }

                        int[] docIds = extraInfos[1].Split(",").Select(str => int.Parse(str)).ToArray();

                        foreach (int i in docIds)
                        {
                            Doctor? doc = GetDoctor(i);
                            if (doc != null) clinic.AddDoctor(doc);
                        }

                        int[] nurIds = extraInfos[2].Split(",").Select(str => int.Parse(str)).ToArray();

                        foreach (int i in depIds)
                        {
                            Nurse? nur = GetNurse(i);
                            if (nur != null) clinic.AddNurse(nur);
                        }

                        list.Add(clinic);
                    }
                }
            }

            return list;
        }
        #endregion

        #region Patient Management
        public void InsertPatient(string name, string surname)
        {
            ExecuteScalarCommand("INSERT INTO Patients (Name, Surname) VALUES (@0, @1)",
                                 name, surname);
        }

        public void DeletePatient(int id)
        {
            ExecuteScalarCommand("DELETE FROM Patients WHERE PatientID = @0", id);
        }

        public void UpdatePatient(int id, string name, string surname)
        {
            ExecuteScalarCommand("UPDATE Patients SET Name = @0, Surname = @1 WHERE PatientID = @2",
                                 name, surname, id);
        }

        public Patient? GetPatient(int id)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM Patients WHERE PatientID = @0", id))
            {
                while (reader.Read())
                {
                    return new Patient((int)reader.GetInt64("PatientID"),
                                      reader.GetString("Name"),
                                      reader.GetString("Surname")
                                      );
                }
            }
            return null;
        }

        public List<Patient> GetAllPatients()
        {
            List<Patient> list = new List<Patient>();

            using (var reader = ExecuteReaderCommand("SELECT * FROM Patients"))
            {
                while (reader.Read())
                {
                    list.Add(new Patient((int)reader.GetInt64("PatientID"),
                                      reader.GetString("Name"),
                                      reader.GetString("Surname")
                                      ));
                }
            }

            return list;
        }
        #endregion

        #region Appointment Management
        public void InsertAppointment(int patientId, int doctorId, string dateTime)
        {
            ExecuteScalarCommand("INSERT INTO Appointments (PatientID, DoctorID, DateTime) VALUES (@0, @1, @2)",
                                 patientId, doctorId, dateTime);
        }

        public void DeleteAppointment(int id)
        {
            ExecuteScalarCommand("DELETE FROM Appointments WHERE AppointmentID = @0", id);
        }

        public void UpdateAppointment(int id, int patientId, int doctorId, string dateTime)
        {
            ExecuteScalarCommand("UPDATE Appointments SET PatientID = @0, DoctorID = @1, DateTime = @2 WHERE AppointmentID = @3",
                                 patientId, doctorId, dateTime, id);
        }

        public AppointmentInfo? GetAppointmentInfo(int id)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM Appointments WHERE AppointmentID = @0", id))
            {
                while (reader.Read())
                {
                    DateTime.TryParse(reader.GetString("DateTime"), out DateTime time);
                    Patient? patient = GetPatient((int)reader.GetInt64("PatientID"));
                    Doctor? doctor = GetDoctor((int)reader.GetInt64("DoctorID"));

                    if (patient == null || doctor == null) return null;

                    return new AppointmentInfo((int)reader.GetInt64("AppointmentID"),
                                               patient,
                                               doctor,
                                               time
                                               );
                }
            }
            return null;
        }

        public AppointmentInfo? GetAppointmentInfo(int patientId, int doctorId, DateTime dateTime)
        {
            AppointmentInfo? info = null;

            using (var reader = ExecuteReaderCommand("SELECT * FROM Appointments WHERE PatientID = @0 AND DoctorID = @1 AND DateTime = @2",
                                                     patientId, doctorId, dateTime.ToString()))
            {
                while (reader.Read())
                {
                    DateTime.TryParse(reader.GetString("DateTime"), out DateTime time);
                    Patient? patient = GetPatient((int)reader.GetInt64("PatientID"));
                    Doctor? doctor = GetDoctor((int)reader.GetInt64("DoctorID"));

                    if (patient == null || doctor == null) return null;

                    info = new AppointmentInfo((int)reader.GetInt64("AppointmentID"),
                                               patient,
                                               doctor,
                                               time
                                               );
                }
            }

            return info;
        }

        public List<AppointmentInfo> GetAllAppointments()
        {
            List<AppointmentInfo> list = new List<AppointmentInfo>();

            using (var reader = ExecuteReaderCommand("SELECT * FROM Appointments"))
            {
                while (reader.Read())
                {
                    DateTime.TryParse(reader.GetString("DateTime"), out DateTime time);
                    Patient? patient = GetPatient((int)reader.GetInt64("PatientID"));
                    Doctor? doctor = GetDoctor((int)reader.GetInt64("DoctorID"));

                    if (patient == null || doctor == null) continue;

                    list.Add(new AppointmentInfo((int)reader.GetInt64("AppointmentID"),
                                                 patient,
                                                 doctor,
                                                 time
                                                 ));
                }
            }

            return list;
        }

        #endregion

        #region Command Wrappers

        private void ExecuteScalarCommand(string command, params object[] args)
        {
            SQLiteCommand cmd = _db.CreateCommand();
            cmd.CommandText = command;

            for (int i = 0; i < args.Length; i++)
            {
                cmd.Parameters.AddWithValue("@" + i, args[i]);
            }

            cmd.ExecuteScalar();
        }

        private SQLiteDataReader ExecuteReaderCommand(string command, params object[] args)
        {
            SQLiteCommand cmd = _db.CreateCommand();
            cmd.CommandText = command;

            for (int i = 0; i < args.Length; i++)
            {
                cmd.Parameters.AddWithValue("@" + i, args[i]);
            }

            SQLiteDataReader result = cmd.ExecuteReader();
            return result;
        }

        private bool TryExecuteScalarCommand(string command, params object[] args)
        {
            try
            {
                ExecuteScalarCommand(command, args);
                return true;
            }
            catch
            {
                return false;
            }
        }

        #endregion
    }
}


// PaymentContext.cs

namespace HealthFacility
{
    public class PaymentContext
    {
        private DoctorPayment doctorPayment = new DoctorPayment();
        private NursePayment nursePayment = new NursePayment();
        private SurgeonPayment surgeonPayment = new SurgeonPayment();

        public void PaySalary(IEmployee employee, double extraHours)
        {
            if (employee is Doctor) {
                doctorPayment.PaySalary(employee, extraHours);
            }
            else if (employee is Nurse) {
                nursePayment.PaySalary(employee, extraHours);
            }
            else if (employee is Surgeon) {
                surgeonPayment.PaySalary(employee, extraHours);
            }
        }
        public void PayBonus(IEmployee employee, double amount)
        {
            if (employee is Doctor) {
                doctorPayment.PayBonus(employee, amount);
            }
            else if (employee is Nurse) {
                nursePayment.PayBonus(employee, amount);
            }
            else if (employee is Surgeon) {
                surgeonPayment.PayBonus(employee, amount);
            }
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
