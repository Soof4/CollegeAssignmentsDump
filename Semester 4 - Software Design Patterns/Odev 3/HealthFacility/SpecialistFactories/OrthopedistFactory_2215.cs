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