// Utils_2215.cs

using System.Reflection;
using System.Globalization;

namespace HealthFacility
{
    public static class Utils
    {
        public static string NormalizeName(string name)
        {
            CultureInfo culture = new CultureInfo("tr-TR", false);
            name = name.ToLower(culture);
            name = name.Substring(0, 1).ToUpper(culture) + name.Substring(1);
            return name;
        }

        public static void PrintListAsTable<T>(List<T> list)
        {
            if (list.Count == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }

            PropertyInfo[] properties = typeof(T).GetProperties();

            // Get the max length for each column
            int[] maxLengths = new int[properties.Length];

            for (int i = 0; i < properties.Length; i++)
            {
                maxLengths[i] = properties[i].Name.Length;
            }

            for (int i = 0; i < properties.Length; i++)
            {
                foreach (T item in list)
                {
                    int length = Convert.ToString(properties[i].GetValue(item))?.Length ?? 0;
                    if (length > maxLengths[i])
                    {
                        maxLengths[i] = length;
                    }
                }
            }

            // Print headers
            Console.WriteLine();

            for (int i = 0; i < properties.Length; i++)
            {
                Console.Write(properties[i].Name.PadRight(maxLengths[i] + 2));
            }

            // Print the header line
            Console.WriteLine();
            
            string headerLine = "";
            int sumLength = maxLengths.Sum() + maxLengths.Length * 2 - 2;
            for (int i = 0; i < sumLength; i++) headerLine += "-";
            
            Console.Write(headerLine);

            // Print elements
            Console.WriteLine();

            foreach (var obj in list)
            {
                for (int i = 0; i < properties.Length; i++)
                {
                    string value = Convert.ToString(properties[i].GetValue(obj)) ?? "";
                    Console.Write(value.PadRight(maxLengths[i] + 2));
                }
                Console.WriteLine();
            }
        }
    }
}

// IMedicineFactory_2215.cs

namespace HealthFacility
{
    public interface IMedicineFactory
    {
        public ICream? CreateCream(int id);
        public IPill? CreatePill(int id);
        public ISyrup? CreateSyrup(int id);
        public ICream? CreateCream(int id, string name, int stock, double price);
        public IPill? CreatePill(int id, string name, int stock, double price);
        public ISyrup? CreateSyrup(int id, string name, int stock, double price);
    }
}

// IReport_2215.cs

namespace HealthFacility
{
    public interface IReport
    {
        public int ReportID { get; set; }
        IDoctor Doctor { get; set; }
        Patient Patient { get; set; }
        public void PrintToConsole();
        public void PrintAsFile();
    }
}

// Patient_2215.cs

namespace HealthFacility
{
    public class Patient
    {
        public int PatientID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }

        public Patient(int patientID, string name, string surname)
        {
            PatientID = patientID;
            Name = name;
            Surname = surname;
        }

        public Patient(string name, string surname)
        {
            Program.dbManager.InsertPatient(name, surname);
            List<Patient> patients = Program.dbManager.GetPatients(name, surname);
            Patient pt = patients[^1];

            PatientID = pt.PatientID;
            Name = pt.Name;
            Surname = pt.Surname;
        }
    }
}

// IClinicBuilder_2215.cs

namespace HealthFacility
{
    public interface IClinicBuilder
    {
        public void AddDoctor(IDoctor doctor);
        public void AddPatientRoom(int number);
        public void AddNurse(int number);
        public void AddReceptionDesk();
        public void AddLaboratory(int number);
        public void Reset();
    }
}

// IDoctor_2215.cs

namespace HealthFacility {
    public interface IDoctor {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }

        public void Examine(Patient patient);
        public void Prescribe(Patient patient);
        public void ReferPatientToDoctor(Patient patient, IDoctor doctor);
        public void ReceiveSalary();
    }
}

// ClinicDirector_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class ClinicDirector
    {
        private IClinicBuilder _builder;

        public ClinicDirector(IClinicBuilder builder)
        {
            _builder = builder;
        }

        public void BuildMinimalClinic(IDoctor doctor)
        {
            _builder.AddDoctor(doctor);
        }

        public void BuildStandardClinic(IDoctor doctor)
        {
            _builder.AddDoctor(doctor);
            _builder.AddNurse(1);
            _builder.AddReceptionDesk();
        }

        public void BuildAdvancedClinic(IDoctor doctor, int patientRoomCount, int nurseCount, int labCount)
        {
            _builder.AddDoctor(doctor);
            _builder.AddPatientRoom(patientRoomCount);
            _builder.AddNurse(nurseCount);
            _builder.AddReceptionDesk();
            _builder.AddLaboratory(labCount);
        }
    }
}

// Report_2215.cs

namespace HealthFacility
{
    public class Report : IReport
    {
        public int ReportID { get; set; }
        public IDoctor Doctor { get; set; }
        public Patient Patient { get; set; }

        public Report(IDoctor doctor, Patient patient)
        {
            Doctor = doctor;
            Patient = patient;
        }

        public void PrintToConsole()
        {
            Console.WriteLine($"This report was written by Dr. {Doctor.Name} {Doctor.Surname} for {Patient.Name} {Patient.Surname}.");
        }

        public void PrintAsFile()
        {
            FileStream fs = new FileStream($"Report_{ReportID}.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);
            sw.Write($"This report was written by Dr. {Doctor.Name} {Doctor.Surname} for {Patient.Name} {Patient.Surname}.\n\nReportID: {ReportID}");
            sw.Close();
        }
    }
}

// Program_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class Program
    {
        public static DatabaseManager dbManager = new DatabaseManager("DataSource=./HealthFacility.db;Version=3;");

        public static void Main(string[] args)
        {
            Console.WriteLine("\n\n-----------------------------------------\nFactory Method:\n");
            TestFactoryMethod();

            Console.WriteLine("\n\n-----------------------------------------\nAbstract Factory:\n");
            TestAbstractFactory();

            Console.WriteLine("\n\n-----------------------------------------\nBuilder:\n");
            TestBuilder();

            Console.WriteLine("\n\n-----------------------------------------\nDependency Injection:\n");
            TestDependecyInjection();
        }

        public static void TestFactoryMethod()
        {
            IDoctorFactory factory = new CardiologistFactory();
            IDoctor dr1 = factory.CreateDoctor("Ali", "Yaş", 35000);

            factory = new NeurologistFactory();
            IDoctor dr2 = factory.CreateDoctor("Veli", "Kaş", 30000);

            factory = new PsychiatristFactory();
            IDoctor dr3 = factory.CreateDoctor("Fatma", "Taş", 45000);

            List<IDoctor> drList = new List<IDoctor>() {
                dr1,
                dr2,
                dr3
            };

            Utils.PrintListAsTable(drList);
        }

        public static void TestAbstractFactory()
        {
            OverTheCounterMedicineFactory otcFactory = new OverTheCounterMedicineFactory();
            IPill? pill = otcFactory.CreatePill(1);
            ICream? cream = otcFactory.CreateCream(2);
            ISyrup? syrup = otcFactory.CreateSyrup(3);

            Patient? patient = dbManager.GetPatient(1);

            pill?.Swallow(patient!);
            cream?.Apply(patient!);
            syrup?.Ingest(patient!);

            pill?.SellTo(patient!);
            cream?.SellTo(patient!);
            syrup?.SellTo(patient!);
        }

        public static void TestBuilder()
        {
            ModernClinicBuilder builder = new ModernClinicBuilder();
            ClinicDirector director = new ClinicDirector(builder);

            IDoctor? doctor = dbManager.GetDoctor(1);
            director.BuildAdvancedClinic(doctor!, 5, 6, 0);

            ModernClinic clinic = builder.GetResult();
            clinic.ShowInfo();
        }

        public static void TestDependecyInjection()
        {
            IDoctor? doctor = dbManager.GetDoctor(5);
            Patient? patient = dbManager.GetPatient(5);

            IReport report = new Report(doctor!, patient!);

            report.PrintToConsole();
            report.PrintAsFile();
        }
    }
}


// IDoctorFactory_2215.cs

using System.Data.SQLite;

namespace HealthFacility
{
    public interface IDoctorFactory
    {
        IDoctor CreateDoctor(int doctorID, string name, string surname, double salary);
        IDoctor CreateDoctor(string name, string surname, double salary);
        IDoctor CreateDoctor(SQLiteDataReader reader);
    }
}

// Hematologist_2215.cs

namespace HealthFacility
{
    public class Hematologist : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Hematologist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}

// Dermatologist_2215.cs

namespace HealthFacility
{
    public class Dermatologist : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Dermatologist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}

// Neurologist_2215.cs

namespace HealthFacility
{
    public class Neurologist : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Neurologist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}

// Nephrologist_2215.cs

namespace HealthFacility
{
    public class Nephrologist : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Nephrologist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}

// Orthopedist_2215.cs

namespace HealthFacility
{
    public class Orthopedist : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Orthopedist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}

// Psychiatrist_2215.cs

namespace HealthFacility
{
    public class Psychiatrist : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Psychiatrist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}

// Urologist_2215.cs

namespace HealthFacility
{
    public class Urologist : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Urologist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}

// Cardiologist_2215.cs

namespace HealthFacility
{
    public class Cardiologist : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Cardiologist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}

// Oncologist_2215.cs

namespace HealthFacility
{
    public class Oncologist : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Oncologist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}

// Pediatrician_2215.cs

namespace HealthFacility
{
    public class Pediatrician : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Pediatrician(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}

// TraditionalClinicBuilder_2215.cs

namespace HealthFacility
{
    public class TraditionalClinicBuilder : IClinicBuilder
    {
        private TraditionalClinic _clinic = new TraditionalClinic();


        public void AddDoctor(IDoctor doctor)
        {
            _clinic.Doctors.Add(doctor);
        }

        public void AddLaboratory(int number)
        {
            _clinic.NumberOfLaboratories += number;
        }

        public void AddNurse(int number)
        {
            _clinic.NumberOfNurses += number;
        }

        public void AddPatientRoom(int number)
        {
            _clinic.NumberOfPatientRooms += number;
        }

        public void AddReceptionDesk()
        {
            _clinic.HasReceptionDesk = true;
        }

        public void Reset()
        {
            _clinic = new TraditionalClinic();
        }

        public TraditionalClinic GetResult()
        {
            return _clinic;
        }
    }
}

// ModernClinicBuilder_2215.cs

namespace HealthFacility
{
    public class ModernClinicBuilder : IClinicBuilder
    {
        private ModernClinic _clinic = new ModernClinic();


        public void AddDoctor(IDoctor doctor)
        {
            _clinic.Doctors.Add(doctor);
        }

        public void AddLaboratory(int number)
        {
            _clinic.NumberOfLaboratories += number;
        }

        public void AddNurse(int number)
        {
            _clinic.NumberOfNurses += number;
        }

        public void AddPatientRoom(int number)
        {
            _clinic.NumberOfPatientRooms += number;
        }

        public void AddReceptionDesk()
        {
            _clinic.HasReceptionDesk = true;
        }

        public void Reset()
        {
            _clinic = new ModernClinic();
        }

        public ModernClinic GetResult() {
            return _clinic;
        }
    }
}

// ModernClinic_2215.cs

namespace HealthFacility
{
    public class ModernClinic
    {
        public int ModernClinicID { get; set; }
        public List<IDoctor> Doctors { get; set; } = new List<IDoctor>();
        public int NumberOfNurses { get; set; }
        public int NumberOfLaboratories { get; set; }
        public int NumberOfPatientRooms { get; set; }
        public bool HasReceptionDesk { get; set; }

        public void ListDoctors()
        {
            Console.WriteLine("List of doctors:");
            Utils.PrintListAsTable(Doctors);
        }

        public void ShowInfo()
        {
            Console.WriteLine("Clinic Info:\n" +
                              $"Number of doctors: {Doctors.Count}\n" + 
                              $"Number of nurses: {NumberOfNurses}\n" +
                              $"Number of laboratories: {NumberOfLaboratories}\n" +
                              $"Number of patient rooms: {NumberOfPatientRooms}\n" +
                              $"Has a reception desk: {HasReceptionDesk}");
        }
    }
}

// TraditionalClinic_2215.cs

namespace HealthFacility
{
    public class TraditionalClinic
    {
        public List<IDoctor> Doctors { get; set; } = new List<IDoctor>();
        public int NumberOfNurses { get; set; }
        public int NumberOfLaboratories { get; set; }
        public int NumberOfPatientRooms { get; set; }
        public bool HasReceptionDesk { get; set; }

        public void ListDoctors()
        {
            Console.WriteLine("List of doctors:");
            Utils.PrintListAsTable(Doctors);
        }

        public void ShowInfo()
        {
            Console.WriteLine("Clinic Info:\n" +
                              $"Number of doctors: {Doctors.Count}\n" + 
                              $"Number of nurses: {NumberOfNurses}\n" +
                              $"Number of laboratories: {NumberOfLaboratories}\n" +
                              $"Number of patient rooms: {NumberOfPatientRooms}\n" +
                              $"Has a reception desk: {HasReceptionDesk}");
        }
    }
}

// MedicineType_2215.cs

namespace HealthFacility
{
    public enum MedicineType
    {
        Cream,
        Pill,
        Syrup
    }
}

// SpecialtyType_2215.cs

namespace HealthFacility
{
    public enum SpecialtyType
    {
        Cardiology,
        Dermatology,
        Hematology,
        Nephrology,
        Neurology,
        Oncology,
        Orthopedics,
        Pediatrics,
        Psychiatry,
        Urology
    }
}

// PsychiatristFactory_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class PsychiatristFactory : IDoctorFactory
    {
        public IDoctor CreateDoctor(int doctorID, string name, string surname, double salary)
        {
            return new Psychiatrist(doctorID, name, surname, salary);
        }

        public IDoctor CreateDoctor(string name, string surname, double salary)
        {
            Program.dbManager.InsertDoctor(name, surname, SpecialtyType.Psychiatry, salary);
            List<IDoctor> doctors = Program.dbManager.GetDoctors(name, surname, SpecialtyType.Psychiatry);
            Psychiatrist dr = (Psychiatrist)doctors[^1];
            return dr;
        }

        public IDoctor CreateDoctor(SQLiteDataReader reader)
        {
            return new Psychiatrist((int)reader.GetInt64("DoctorID"),
                                    reader.GetString("Name"),
                                    reader.GetString("Surname"),
                                    reader.GetDouble("Salary")
                                    );
        }
    }
}

// PediatricianFactory_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class PediatricianFactory : IDoctorFactory
    {
        public IDoctor CreateDoctor(int doctorID, string name, string surname, double salary)
        {
            return new Pediatrician(doctorID, name, surname, salary);
        }

        public IDoctor CreateDoctor(string name, string surname, double salary)
        {
            Program.dbManager.InsertDoctor(name, surname, SpecialtyType.Pediatrics, salary);
            List<IDoctor> doctors = Program.dbManager.GetDoctors(name, surname, SpecialtyType.Pediatrics);
            Pediatrician dr = (Pediatrician)doctors[^1];
            return dr;
        }

        public IDoctor CreateDoctor(SQLiteDataReader reader)
        {
            return new Pediatrician((int)reader.GetInt64("DoctorID"),
                                    reader.GetString("Name"),
                                    reader.GetString("Surname"),
                                    reader.GetDouble("Salary")
                                    );
        }
    }
}

// OncologistFactory_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class OncologistFactory : IDoctorFactory
    {
        public IDoctor CreateDoctor(int doctorID, string name, string surname, double salary)
        {
            return new Oncologist(doctorID, name, surname, salary);
        }

        public IDoctor CreateDoctor(string name, string surname, double salary)
        {
            Program.dbManager.InsertDoctor(name, surname, SpecialtyType.Oncology, salary);
            List<IDoctor> doctors = Program.dbManager.GetDoctors(name, surname, SpecialtyType.Oncology);
            Oncologist dr = (Oncologist)doctors[^1];
            return dr;
        }

        public IDoctor CreateDoctor(SQLiteDataReader reader)
        {
            return new Oncologist((int)reader.GetInt64("DoctorID"),
                                    reader.GetString("Name"),
                                    reader.GetString("Surname"),
                                    reader.GetDouble("Salary")
                                    );
        }
    }
}

// HematologistFactory_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class HematologistFactory : IDoctorFactory
    {
        public IDoctor CreateDoctor(int doctorID, string name, string surname, double salary)
        {
            return new Hematologist(doctorID, name, surname, salary);
        }

        public IDoctor CreateDoctor(string name, string surname, double salary)
        {
            Program.dbManager.InsertDoctor(name, surname, SpecialtyType.Hematology, salary);
            List<IDoctor> doctors = Program.dbManager.GetDoctors(name, surname, SpecialtyType.Hematology);
            Hematologist dr = (Hematologist)doctors[^1];
            return dr;
        }

        public IDoctor CreateDoctor(SQLiteDataReader reader)
        {
            return new Hematologist((int)reader.GetInt64("DoctorID"),
                                    reader.GetString("Name"),
                                    reader.GetString("Surname"),
                                    reader.GetDouble("Salary")
                                    );
        }
    }
}

// UrologistFactory_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class UrologistFactory : IDoctorFactory
    {
        public IDoctor CreateDoctor(int doctorID, string name, string surname, double salary)
        {
            return new Urologist(doctorID, name, surname, salary);
        }

        public IDoctor CreateDoctor(string name, string surname, double salary)
        {
            Program.dbManager.InsertDoctor(name, surname, SpecialtyType.Urology, salary);
            List<IDoctor> doctors = Program.dbManager.GetDoctors(name, surname, SpecialtyType.Urology);
            Urologist dr = (Urologist)doctors[^1];
            return dr;
        }

        public IDoctor CreateDoctor(SQLiteDataReader reader)
        {
            return new Urologist((int)reader.GetInt64("DoctorID"),
                                    reader.GetString("Name"),
                                    reader.GetString("Surname"),
                                    reader.GetDouble("Salary")
                                    );
        }
    }
}

// CardiologistFactory_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class CardiologistFactory : IDoctorFactory
    {
        public IDoctor CreateDoctor(int doctorID, string name, string surname, double salary)
        {
            return new Cardiologist(doctorID, name, surname, salary);
        }

        public IDoctor CreateDoctor(string name, string surname, double salary)
        {
            Program.dbManager.InsertDoctor(name, surname, SpecialtyType.Cardiology, salary);
            List<IDoctor> doctors = Program.dbManager.GetDoctors(name, surname, SpecialtyType.Cardiology);
            Cardiologist dr = (Cardiologist)doctors[^1];
            return dr;
        }

        public IDoctor CreateDoctor(SQLiteDataReader reader)
        {
            return new Cardiologist((int)reader.GetInt64("DoctorID"),
                                    reader.GetString("Name"),
                                    reader.GetString("Surname"),
                                    reader.GetDouble("Salary")
                                    );
        }
    }
}

// NeurologistFactory_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class NeurologistFactory : IDoctorFactory
    {
        public IDoctor CreateDoctor(int doctorID, string name, string surname, double salary)
        {
            return new Neurologist(doctorID, name, surname, salary);
        }

        public IDoctor CreateDoctor(string name, string surname, double salary)
        {
            Program.dbManager.InsertDoctor(name, surname, SpecialtyType.Neurology, salary);
            List<IDoctor> doctors = Program.dbManager.GetDoctors(name, surname, SpecialtyType.Neurology);
            Neurologist dr = (Neurologist)doctors[^1];
            return dr;
        }

        public IDoctor CreateDoctor(SQLiteDataReader reader)
        {
            return new Neurologist((int)reader.GetInt64("DoctorID"),
                                    reader.GetString("Name"),
                                    reader.GetString("Surname"),
                                    reader.GetDouble("Salary")
                                    );
        }
    }
}

// DermatologistFactory_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class DermatologistFactory : IDoctorFactory
    {
        public IDoctor CreateDoctor(int doctorID, string name, string surname, double salary)
        {
            return new Dermatologist(doctorID, name, surname, salary);
        }

        public IDoctor CreateDoctor(string name, string surname, double salary)
        {
            Program.dbManager.InsertDoctor(name, surname, SpecialtyType.Dermatology, salary);
            List<IDoctor> doctors = Program.dbManager.GetDoctors(name, surname, SpecialtyType.Dermatology);
            Dermatologist dr = (Dermatologist)doctors[^1];
            return dr;
        }

        public IDoctor CreateDoctor(SQLiteDataReader reader)
        {
            return new Dermatologist((int)reader.GetInt64("DoctorID"),
                                    reader.GetString("Name"),
                                    reader.GetString("Surname"),
                                    reader.GetDouble("Salary")
                                    );
        }
    }
}

// OrthopedistFactory_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class OrthopedistFactory : IDoctorFactory
    {
        public IDoctor CreateDoctor(int doctorID, string name, string surname, double salary)
        {
            return new Orthopedist(doctorID, name, surname, salary);
        }

        public IDoctor CreateDoctor(string name, string surname, double salary)
        {
            Program.dbManager.InsertDoctor(name, surname, SpecialtyType.Orthopedics, salary);
            List<IDoctor> doctors = Program.dbManager.GetDoctors(name, surname, SpecialtyType.Orthopedics);
            Orthopedist dr = (Orthopedist)doctors[^1];
            return dr;
        }

        public IDoctor CreateDoctor(SQLiteDataReader reader)
        {
            return new Orthopedist((int)reader.GetInt64("DoctorID"),
                                    reader.GetString("Name"),
                                    reader.GetString("Surname"),
                                    reader.GetDouble("Salary")
                                    );
        }
    }
}

// NephrologistFactory_2215.cs

using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class NephrologistFactory : IDoctorFactory
    {
        public IDoctor CreateDoctor(int doctorID, string name, string surname, double salary)
        {
            return new Nephrologist(doctorID, name, surname, salary);
        }

        public IDoctor CreateDoctor(string name, string surname, double salary)
        {
            Program.dbManager.InsertDoctor(name, surname, SpecialtyType.Nephrology, salary);
            List<IDoctor> doctors = Program.dbManager.GetDoctors(name, surname, SpecialtyType.Nephrology);
            Nephrologist dr = (Nephrologist)doctors[^1];
            return dr;
        }

        public IDoctor CreateDoctor(SQLiteDataReader reader)
        {
            return new Nephrologist((int)reader.GetInt64("DoctorID"),
                                    reader.GetString("Name"),
                                    reader.GetString("Surname"),
                                    reader.GetDouble("Salary")
                                    );
        }
    }
}

// IPill_2215.cs

namespace HealthFacility
{
    public interface IPill
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }


        public void SellTo(Patient patient);
        public void Swallow(Patient patient);
    }
}

// PrescriptionCream_2215.cs

namespace HealthFacility
{
    public class PrescriptionCream : ICream
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }


        public PrescriptionCream(int id, string name, int stock, double price)
        {
            MedicineID = id;
            Name = name;
            Stock = stock;
            Price = price;
        }


        public void Apply(Patient patient)
        {
            Console.WriteLine($"Applying {Name} to {patient.Name} {patient.Surname}.");
        }

        public void SellTo(Patient patient)
        {
            Stock--;
            Console.WriteLine($"Sold 1 {Name} for {Price} TRY to {patient.Name} {patient.Surname}.");
        }
    }
}

// PrescriptionPill_2215.cs

namespace HealthFacility
{
    public class PrescriptionPill : IPill
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }


        public PrescriptionPill(int id, string name, int stock, double price)
        {
            MedicineID = id;
            Name = name;
            Stock = stock;
            Price = price;
        }


        public void Swallow(Patient patient)
        {
            Console.WriteLine($"{patient.Name} {patient.Surname} is swallowing {Name}.");
        }

        public void SellTo(Patient patient)
        {
            Stock--;
            Console.WriteLine($"Sold 1 {Name} for {Price} TRY to {patient.Name} {patient.Surname}.");
        }
    }
}

// ICream_2215.cs

namespace HealthFacility
{
    public interface ICream
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }
        
        
        public void SellTo(Patient patient);
        public void Apply(Patient patient);
    }
}

// OverTheCounterSyrup_2215.cs

namespace HealthFacility
{
    public class OverTheCounterSyrup : ISyrup
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }
        public double Tax { get; set; }


        public OverTheCounterSyrup(int id, string name, int stock, double price, double tax = 0.20)
        {
            MedicineID = id;
            Name = name;
            Stock = stock;
            Price = price;
            Tax = tax;
        }


        public void Ingest(Patient patient)
        {
            Console.WriteLine($"{patient.Name} {patient.Surname} is ingesting {Name}.");
        }

        public void SellTo(Patient patient)
        {
            Stock--;
            Console.WriteLine($"Sold 1 {Name} for {Price * (1 + Tax)} TRY to {patient.Name} {patient.Surname}.");
        }
    }
}

// OverTheCounterCream_2215.cs

namespace HealthFacility
{
    public class OverTheCounterCream : ICream
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }
        public double Tax { get; set; }


        internal OverTheCounterCream(int id, string name, int stock, double price, double tax = 0.20)
        {
            MedicineID = id;
            Name = name;
            Stock = stock;
            Price = price;
            Tax = tax;
        }


        public void Apply(Patient patient)
        {
            Console.WriteLine($"Applying {Name} to {patient.Name} {patient.Surname}.");
        }

        public void SellTo(Patient patient)
        {
            Stock--;
            Console.WriteLine($"Sold 1 {Name} for {Price * (1 + Tax)} TRY to {patient.Name} {patient.Surname}.");
        }
    }
}

// ISyrup_2215.cs

namespace HealthFacility
{
    public interface ISyrup
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }


        public void SellTo(Patient patient);
        public void Ingest(Patient patient);
    }
}

// PrescriptionSyrup_2215.cs

namespace HealthFacility
{
    public class PrescriptionSyrup : ISyrup
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }


        public PrescriptionSyrup(int id, string name, int stock, double price)
        {
            MedicineID = id;
            Name = name;
            Stock = stock;

            Price = price;
        }


        public void Ingest(Patient patient)
        {
            Console.WriteLine($"{patient.Name} {patient.Surname} is ingesting {Name}.");
        }

        public void SellTo(Patient patient)
        {
            Stock--;
            Console.WriteLine($"Sold 1 {Name} for {Price} TRY to {patient.Name} {patient.Surname}.");
        }
    }
}

// OverTheCounterPill_2215.cs

namespace HealthFacility
{
    public class OverTheCounterPill : IPill
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }
        public double Tax { get; set; }


        internal OverTheCounterPill(int id, string name, int stock, double price, double tax = 0.20)
        {
            MedicineID = id;
            Name = name;
            Stock = stock;
            Price = price;
            Tax = tax;
        }


        public void Swallow(Patient patient)
        {
            Console.WriteLine($"{patient.Name} {patient.Surname} is swallowing {Name}.");
        }

        public void SellTo(Patient patient)
        {
            Stock--;
            Console.WriteLine($"Sold 1 {Name} for {Price * (1 + Tax)} TRY to {patient.Name} {patient.Surname}.");
        }
    }
}

// OverTheCounterMedicineFactory_2215.cs

namespace HealthFacility
{
    public class OverTheCounterMedicineFactory : IMedicineFactory
    {
        public ICream? CreateCream(int id, string name, int stock, double price)
        {
            if (stock < 0)
            {
                Console.WriteLine("Invalid stock amount.");
                return null;
            }

            if (price < 0)
            {
                Console.WriteLine("Invalid price value.");
                return null;
            }

            return new OverTheCounterCream(id, name, stock, price);
        }

        public ICream? CreateCream(int id)
        {
            return Program.dbManager.GetOverTheCounterCream(id);
        }

        public IPill? CreatePill(int id, string name, int stock, double price)
        {
            if (stock < 0)
            {
                Console.WriteLine("Invalid stock amount.");
                return null;
            }

            if (price < 0)
            {
                Console.WriteLine("Invalid price value.");
                return null;
            }

            return new OverTheCounterPill(id, name, stock, price);
        }

        public IPill? CreatePill(int id)
        {
            return Program.dbManager.GetOverTheCounterPill(id);
        }

        public ISyrup? CreateSyrup(int id, string name, int stock, double price)
        {
            if (stock < 0)
            {
                Console.WriteLine("Invalid stock amount.");
                return null;
            }

            if (price < 0)
            {
                Console.WriteLine("Invalid price value.");
                return null;
            }

            return new OverTheCounterSyrup(id, name, stock, price);
        }

        public ISyrup? CreateSyrup(int id)
        {
            return Program.dbManager.GetOverTheCounterSyrup(id);
        }
    }
}

// PrescriptionMedicineFactory_2215.cs

namespace HealthFacility
{
    public class PrescriptionMedicineFactory : IMedicineFactory
    {
        public ICream? CreateCream(int id, string name, int stock, double price)
        {
            if (stock < 0)
            {
                Console.WriteLine("Invalid stock amount.");
                return null;
            }

            if (price < 0)
            {
                Console.WriteLine("Invalid price value.");
                return null;
            }

            return new PrescriptionCream(id, name, stock, price);
        }

        public ICream? CreateCream(int id)
        {
            return Program.dbManager.GetPrescriptionCream(id);
        }

        public IPill? CreatePill(int id, string name, int stock, double price)
        {
            if (stock < 0)
            {
                Console.WriteLine("Invalid stock amount.");
                return null;
            }

            if (price < 0)
            {
                Console.WriteLine("Invalid price value.");
                return null;
            }

            return new PrescriptionPill(id, name, stock, price);
        }

        public IPill? CreatePill(int id)
        {
            return Program.dbManager.GetPrescriptionPill(id);
        }

        public ISyrup? CreateSyrup(int id, string name, int stock, double price)
        {
            if (stock < 0)
            {
                Console.WriteLine("Invalid stock amount.");
                return null;
            }

            if (price < 0)
            {
                Console.WriteLine("Invalid price value.");
                return null;
            }

            return new PrescriptionSyrup(id, name, stock, price);
        }

        public ISyrup? CreateSyrup(int id)
        {
            return Program.dbManager.GetPrescriptionSyrup(id);
        }
    }
}

// DatabaseManager_2215.cs

using System.ComponentModel.DataAnnotations.Schema;
using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class DatabaseManager
    {
        private SQLiteConnection _db;

        public DatabaseManager(string connectionString)
        {
            _db = new SQLiteConnection(connectionString);
            _db.Open();

            // Try creating the tables
            TryExecuteScalarCommand("CREATE TABLE Doctors (" +
                                    "DoctorID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Name TEXT NOT NULL, " +
                                    "Surname TEXT NOT NULL, " +
                                    "SpecialtyType INTEGER NOT NULL, " +
                                    "Salary REAL DEFAULT 0)");

            TryExecuteScalarCommand("CREATE TABLE Patients (" +
                                    "PatientID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Name TEXT NOT NULL, " +
                                    "Surname TEXT NOT NULL)");

            TryExecuteScalarCommand("CREATE TABLE PMedicines (" +
                                    "PMedicineID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Name TEXT NOT NULL, " +
                                    "Stock INTEGER NOT NULL DEFAULT 0, " +
                                    "Price REAL NOT NULL DEFAULT 0, " +
                                    "MedicineType INTEGER NOT NULL)");

            TryExecuteScalarCommand("CREATE TABLE OTCMedicines (" +
                                    "OTCMedicineID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Name TEXT NOT NULL, " +
                                    "Stock INTEGER NOT NULL DEFAULT 0, " +
                                    "Price REAL NOT NULL DEFAULT 0, " +
                                    "Tax REAL NOT NULL DEFAULT 0, " +
                                    "MedicineType INTEGER NOT NULL)");

            TryExecuteScalarCommand("CREATE TABLE ModernClinics (" +
                                    "ModernClinicID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Doctors TEXT NOT NULL DEFAULT '', " +
                                    "NumberOfNurses INTEGER NOT NULL DEFAULT 0, " +
                                    "NumberOfLaboratories INTEGER NOT NULL DEFAULT 0, " +
                                    "NumberOfPatientRooms INTEGER NOT NULL DEFAULT 0, " +
                                    "HasReceptionDesk INTEGER NOT NULL DEFAULT 0)");

            TryExecuteScalarCommand("CREATE TABLE TraditionalClinics (" +
                                    "TraditionalClinicID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "Doctors TEXT NOT NULL DEFAULT '', " +
                                    "NumberOfNurses INTEGER NOT NULL DEFAULT 0, " +
                                    "NumberOfLaboratories INTEGER NOT NULL DEFAULT 0, " +
                                    "NumberOfPatientRooms INTEGER NOT NULL DEFAULT 0, " +
                                    "HasReceptionDesk INTEGER NOT NULL DEFAULT 0)");

            TryExecuteScalarCommand("CREATE TABLE Reports (" +
                                    "ReportID INTEGER PRIMARY KEY AUTOINCREMENT, " +
                                    "DoctorID INTEGER NOT NULL, " +
                                    "PatientID INTEGER NOT NULL, " +
                                    "CONSTRAINT DoctorConstraint FOREIGN KEY (DoctorID) REFERENCES Doctors (DoctorID) " +
                                    "ON DELETE CASCADE ON UPDATE CASCADE, " +
                                    "CONSTRAINT PatientConstraint FOREIGN KEY (PatientID) REFERENCES Patients (PatientID) " +
                                    "ON DELETE CASCADE ON UPDATE CASCADE)");
        }


        #region Doctor Management

        public void InsertDoctor(string name, string surname, SpecialtyType specialtyType, double salary)
        {
            name = Utils.NormalizeName(name);
            surname = Utils.NormalizeName(surname);

            ExecuteScalarCommand("INSERT INTO Doctors (Name, Surname, SpecialtyType, Salary) VALUES (@0, @1, @2, @3)", name, surname, specialtyType, salary);
        }

        public void DeleteDoctor(int doctorID)
        {
            ExecuteScalarCommand("DELETE FROM Doctors WHERE DoctorID = @0", doctorID);
        }

        public void UpdateDoctor(int doctorID, string name, string surname, SpecialtyType specialtyType, double salary)
        {
            ExecuteReaderCommand("UPDATE Doctors SET Name = @0, Surname = @1, SpecialtyType = @2, Salary = @3 WHERE DoctorID = @4", name, surname, specialtyType, salary, doctorID);
        }

        public IDoctor? GetDoctor(int doctorID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM Doctors WHERE DoctorID = @0", doctorID))
            {
                IDoctorFactory? factory = null;

                if (reader.Read())
                {
                    switch ((SpecialtyType)reader.GetInt64("SpecialtyType"))
                    {
                        case SpecialtyType.Cardiology:
                            factory = new CardiologistFactory();
                            break;

                        case SpecialtyType.Dermatology:
                            factory = new DermatologistFactory();
                            break;

                        case SpecialtyType.Hematology:
                            factory = new HematologistFactory();
                            break;

                        case SpecialtyType.Nephrology:
                            factory = new NephrologistFactory();
                            break;

                        case SpecialtyType.Neurology:
                            factory = new NeurologistFactory();
                            break;

                        case SpecialtyType.Oncology:
                            factory = new OncologistFactory();
                            break;

                        case SpecialtyType.Orthopedics:
                            factory = new OrthopedistFactory();
                            break;

                        case SpecialtyType.Pediatrics:
                            factory = new PediatricianFactory();
                            break;

                        case SpecialtyType.Psychiatry:
                            factory = new PsychiatristFactory();
                            break;

                        case SpecialtyType.Urology:
                            factory = new UrologistFactory();
                            break;
                    }
                }

                IDoctor? doctor = factory?.CreateDoctor(reader);
                return doctor;
            }
        }

        public List<IDoctor> GetDoctors(string name, string surname, SpecialtyType specialtyType)
        {
            name = Utils.NormalizeName(name);
            surname = Utils.NormalizeName(surname);

            List<IDoctor> ls = new List<IDoctor>();

            using (var reader = ExecuteReaderCommand("SELECT * FROM Doctors WHERE Name = @0 AND Surname = @1 AND SpecialtyType = @2", name, surname, specialtyType))
            {
                IDoctorFactory? factory = null;

                while (reader.Read())
                {
                    switch ((SpecialtyType)reader.GetInt64("SpecialtyType"))
                    {
                        case SpecialtyType.Cardiology:
                            factory = new CardiologistFactory();
                            break;

                        case SpecialtyType.Dermatology:
                            factory = new DermatologistFactory();
                            break;

                        case SpecialtyType.Hematology:
                            factory = new HematologistFactory();
                            break;

                        case SpecialtyType.Nephrology:
                            factory = new NephrologistFactory();
                            break;

                        case SpecialtyType.Neurology:
                            factory = new NeurologistFactory();
                            break;

                        case SpecialtyType.Oncology:
                            factory = new OncologistFactory();
                            break;

                        case SpecialtyType.Orthopedics:
                            factory = new OrthopedistFactory();
                            break;

                        case SpecialtyType.Pediatrics:
                            factory = new PediatricianFactory();
                            break;

                        case SpecialtyType.Psychiatry:
                            factory = new PsychiatristFactory();
                            break;

                        case SpecialtyType.Urology:
                            factory = new UrologistFactory();
                            break;
                    }

                    IDoctor? doctor = factory?.CreateDoctor(reader);
                    if (doctor != null) ls.Add(doctor);
                }
            }

            return ls;
        }

        #endregion


        #region Patient Management

        public void InsertPatient(string name, string surname)
        {
            name = Utils.NormalizeName(name);
            surname = Utils.NormalizeName(surname);

            ExecuteScalarCommand("INSERT INTO Patients (Name, Surname) VALUES (@0, @1)", name, surname);
        }

        public void DeletePatient(int patientID)
        {
            ExecuteScalarCommand("DELETE FROM Patients WHERE PatientID = @0", patientID);
        }

        public void UpdatePatient(int patientID, string name, string surname)
        {
            ExecuteReaderCommand("UPDATE Patients SET Name = @0, Surname = @1 WHERE PatientID = @2", name, surname, patientID);
        }

        public Patient? GetPatient(int patientID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM Patients WHERE PatientID = @0", patientID))
            {
                if (reader.Read())
                {
                    return new Patient((int)reader.GetInt64("PatientID"),
                                       reader.GetString("Name"),
                                       reader.GetString("Surname")
                                       );
                }

                return null;
            }
        }

        public List<Patient> GetPatients(string name, string surname)
        {
            name = Utils.NormalizeName(name);
            surname = Utils.NormalizeName(surname);

            List<Patient> ls = new List<Patient>();
            using (var reader = ExecuteReaderCommand("SELECT * FROM Patients WHERE Name = @0 AND Surname = @1", name, surname))
            {
                while (reader.Read())
                {
                    ls.Add(new Patient((int)reader.GetInt64("PatientID"),
                                       reader.GetString("Name"),
                                       reader.GetString("Surname")
                                       ));
                }
            }

            return ls;
        }

        #endregion


        #region PrescriptionMedicine Management

        public void InsertPrescriptionMedicine(string name, int stock, double price, MedicineType medicineType)
        {
            name = Utils.NormalizeName(name);

            ExecuteScalarCommand("INSERT INTO PMedicines (Name, Stock, Price, MedicineType) VALUES (@0, @1, @2, @3)", name, stock, price, medicineType);
        }

        public void DeletePrescriptionMedicine(int medicineID)
        {
            ExecuteScalarCommand("DELETE FROM PMedicines WHERE PMedicineID = @0", medicineID);
        }

        public void UpdatePrescriptionMedicine(int medicineID, string name, int stock, double price, MedicineType medicineType)
        {
            ExecuteReaderCommand("UPDATE PMedicines SET Name = @0, Stock = @1, Price = @2, MedicineType = @3 WHERE PMedicineID = @4", name, stock, price, medicineType, medicineID);
        }

        public IPill? GetPrescriptionPill(int medicineID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM PMedicines WHERE PMedicineID = @0 AND MedicineType = @1", medicineID, MedicineType.Pill))
            {
                if (reader.Read())
                {
                    return new PrescriptionPill((int)reader.GetInt64("PMedicineID"),
                                                reader.GetString("Name"),
                                                (int)reader.GetInt64("Stock"),
                                                reader.GetDouble("Price")
                                                );
                }
            }

            return null;
        }

        public ISyrup? GetPrescriptionSyrup(int medicineID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM PMedicines WHERE PMedicineID = @0 AND MedicineType = @1", medicineID, MedicineType.Syrup))
            {
                if (reader.Read())
                {
                    return new PrescriptionSyrup((int)reader.GetInt64("PMedicineID"),
                                                reader.GetString("Name"),
                                                (int)reader.GetInt64("Stock"),
                                                reader.GetDouble("Price")
                                                );
                }
            }

            return null;
        }

        public ICream? GetPrescriptionCream(int medicineID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM PMedicines WHERE PMedicineID = @0 AND MedicineType = @1", medicineID, MedicineType.Cream))
            {
                if (reader.Read())
                {
                    return new PrescriptionCream((int)reader.GetInt64("PMedicineID"),
                                                reader.GetString("Name"),
                                                (int)reader.GetInt64("Stock"),
                                                reader.GetDouble("Price")
                                                );
                }
            }

            return null;
        }

        #endregion


        #region OverTheCounterMedicine Management

        public void InsertOverTheCounterMedicine(string name, int stock, double price, MedicineType medicineType)
        {
            name = Utils.NormalizeName(name);

            ExecuteScalarCommand("INSERT INTO OTCMedicines (Name, Stock, Price, MedicineType) VALUES (@0, @1, @2, @3)", name, stock, price, medicineType);
        }

        public void DeleteOverTheCounterMedicine(int medicineID)
        {
            ExecuteScalarCommand("DELETE FROM OTCMedicines WHERE OTCMedicineID = @0", medicineID);
        }

        public void UpdateOverTheCounterMedicine(int medicineID, string name, int stock, double price, MedicineType medicineType)
        {
            ExecuteReaderCommand("UPDATE OTCMedicines SET Name = @0, Stock = @1, Price = @2, MedicineType = @3 WHERE OTCMedicineID = @4", name, stock, price, medicineType, medicineID);
        }

        public IPill? GetOverTheCounterPill(int medicineID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM OTCMedicines WHERE OTCMedicineID = @0 AND MedicineType = @1", medicineID, MedicineType.Pill))
            {
                if (reader.Read())
                {
                    return new OverTheCounterPill((int)reader.GetInt64("OTCMedicineID"),
                                                reader.GetString("Name"),
                                                (int)reader.GetInt64("Stock"),
                                                reader.GetDouble("Price"),
                                                reader.GetDouble("Tax")
                                                );
                }
            }

            return null;
        }

        public ISyrup? GetOverTheCounterSyrup(int medicineID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM OTCMedicines WHERE OTCMedicineID = @0 AND MedicineType = @1", medicineID, MedicineType.Syrup))
            {
                if (reader.Read())
                {
                    return new OverTheCounterSyrup((int)reader.GetInt64("OTCMedicineID"),
                                                reader.GetString("Name"),
                                                (int)reader.GetInt64("Stock"),
                                                reader.GetDouble("Price"),
                                                reader.GetDouble("Tax")
                                                );
                }
            }

            return null;
        }

        public ICream? GetOverTheCounterCream(int medicineID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM OTCMedicines WHERE OTCMedicineID = @0 AND MedicineType = @1", medicineID, MedicineType.Cream))
            {
                if (reader.Read())
                {
                    return new OverTheCounterCream((int)reader.GetInt64("OTCMedicineID"),
                                                reader.GetString("Name"),
                                                (int)reader.GetInt64("Stock"),
                                                reader.GetDouble("Price"),
                                                reader.GetDouble("Tax")
                                                );
                }
            }

            return null;
        }



        #endregion


        #region ModernClinic Management

        public void InsertModernClinic(List<IDoctor> doctors, int nurseCount, int labCount, int patientRoomCount, bool hasReceptionDesk)
        {
            string doctorIDs = string.Join(":", doctors.Select(d => d.DoctorID));
            ExecuteScalarCommand("INSERT INTO ModernClinics (Doctors, NumberOfNurses, NumberOfLaboratories, NumberOfPatientRooms, HasReceptionDesk) " +
                                 "VALUES (@0, @1, @2, @3, @4)", doctorIDs, nurseCount, labCount, patientRoomCount, hasReceptionDesk ? 1 : 0);
        }

        public void DeleteModernClinic(int modernClinicID)
        {
            ExecuteScalarCommand("DELETE FROM ModernClinics WHERE ModernClinicID = @0", modernClinicID);
        }

        public void UpdateModernClinic(int modernClinicID, List<IDoctor> doctors, int nurseCount, int labCount, int patientRoomCount, bool hasReceptionDesk)
        {
            string doctorIDs = string.Join(":", doctors.Select(d => d.DoctorID));
            ExecuteReaderCommand("UPDATE ModernClinics SET Doctors = @0, NumberOfNurses = @1, NumberOfLaboratories = @2, NumberOfPatientRooms = @3, HasReceptionDesk = @4 WHERE ModernClinicID = @5",
                                 doctorIDs, nurseCount, labCount, patientRoomCount, hasReceptionDesk ? 1 : 0, modernClinicID);
        }

        public ModernClinic? GetModernClinic(int modernClinicID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM ModernClinics WHERE ModernClinicID = @0", modernClinicID))
            {
                ModernClinicBuilder builder = new ModernClinicBuilder();

                if (reader.Read())
                {
                    int[] doctorIDs = reader.GetString("Doctors").Split(":").Select(str => int.Parse(str)).ToArray();    // Read DoctorIDs

                    foreach (int id in doctorIDs)
                    {
                        IDoctor? dr = GetDoctor(id);

                        if (dr != null) builder.AddDoctor(dr);
                    }

                    builder.AddNurse((int)reader.GetInt64("NumberOfNurses"));
                    builder.AddLaboratory((int)reader.GetInt64("NumberOfLaboratories"));
                    builder.AddPatientRoom((int)reader.GetInt64("NumberOfPatientRooms"));
                    if (reader.GetInt64("HasReceptionDesk") == 1) builder.AddReceptionDesk();
                    return builder.GetResult();
                }

                return null;
            }
        }

        #endregion


        #region TraditionalClinic Management

        public void InsertTraditionalClinic(List<IDoctor> doctors, int nurseCount, int labCount, int patientRoomCount, bool hasReceptionDesk)
        {
            string doctorIDs = string.Join(":", doctors.Select(d => d.DoctorID));
            ExecuteScalarCommand("INSERT INTO TraditionalClinics (Doctors, NumberOfNurses, NumberOfLaboratories, NumberOfPatientRooms, HasReceptionDesk) " +
            "VALUES (@0, @1, @2, @3, @4)", doctorIDs, nurseCount, labCount, patientRoomCount, hasReceptionDesk ? 1 : 0);
        }

        public void DeleteTraditionalClinic(int traditionalClinicID)
        {
            ExecuteScalarCommand("DELETE FROM TraditionalClinics WHERE TraditionalClinicID = @0", traditionalClinicID);
        }

        public void UpdateTraditionalClinic(int traditionalClinicID, List<IDoctor> doctors, int nurseCount, int labCount, int patientRoomCount, bool hasReceptionDesk)
        {
            string doctorIDs = string.Join(":", doctors.Select(d => d.DoctorID));
            ExecuteReaderCommand("UPDATE TraditionalClinics SET Doctors = @0, NumberOfNurses = @1, NumberOfLaboratories = @2, NumberOfPatientRooms = @3, HasReceptionDesk = @4 WHERE TraditionalClinicID = @5",
                                 doctorIDs, nurseCount, labCount, patientRoomCount, hasReceptionDesk ? 1 : 0, traditionalClinicID);
        }

        public TraditionalClinic? GetTraditionalClinic(int traditionalClinicID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM TraditionalClinics WHERE TraditionalClinicID = @0", traditionalClinicID))
            {
                TraditionalClinicBuilder builder = new TraditionalClinicBuilder();

                if (reader.Read())
                {
                    int[] doctorIDs = reader.GetString("Doctors").Split(":").Select(str => int.Parse(str)).ToArray();    // Read DoctorIDs

                    foreach (int id in doctorIDs)
                    {
                        IDoctor? dr = GetDoctor(id);

                        if (dr != null) builder.AddDoctor(dr);
                    }

                    builder.AddNurse((int)reader.GetInt64("NumberOfNurses"));
                    builder.AddLaboratory((int)reader.GetInt64("NumberOfLaboratories"));
                    builder.AddPatientRoom((int)reader.GetInt64("NumberOfPatientRooms"));
                    if (reader.GetInt64("HasReceptionDesk") == 1) builder.AddReceptionDesk();
                    return builder.GetResult();
                }

                return null;
            }
        }

        #endregion


        #region Report Management

        public void InsertReport(IDoctor doctor, Patient patient)
        {
            ExecuteScalarCommand("INSERT INTO Reports (DoctorID, PatientName, PatientSurname) VALUES (@0, @1, @2)", doctor.DoctorID, patient.Name, patient.Surname);
        }

        public void DeleteReport(int reportID)
        {
            ExecuteScalarCommand("DELETE FROM Reports WHERE ReportID = @0", reportID);
        }

        public void UpdateReport(int reportID, IDoctor doctor, Patient patient)
        {
            ExecuteReaderCommand("UPDATE Reports SET DoctorID = @0, PatientName = @1, PatientSurname = @2 WHERE ReportID = @3", doctor.DoctorID, patient.Name, patient.Surname, reportID);
        }

        public IReport? GetReport(int reportID)
        {
            using (var reader = ExecuteReaderCommand("SELECT * FROM Reports WHERE ReportID = @0", reportID))
            {
                if (reader.Read())
                {
                    IDoctor? dr = GetDoctor((int)reader.GetInt64("DoctorID"));
                    Patient? pt = GetPatient((int)reader.GetInt64("PatientID"));

                    if (dr != null && pt != null) return new Report(dr, pt);
                }

                return null;
            }
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

