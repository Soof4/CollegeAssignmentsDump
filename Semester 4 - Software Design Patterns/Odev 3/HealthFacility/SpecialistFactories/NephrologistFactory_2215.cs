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