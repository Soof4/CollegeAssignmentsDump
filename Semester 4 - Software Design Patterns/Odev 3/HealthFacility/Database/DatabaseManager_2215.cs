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