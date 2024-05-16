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