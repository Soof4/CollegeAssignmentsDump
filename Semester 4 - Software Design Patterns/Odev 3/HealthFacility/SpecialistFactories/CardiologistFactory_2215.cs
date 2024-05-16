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