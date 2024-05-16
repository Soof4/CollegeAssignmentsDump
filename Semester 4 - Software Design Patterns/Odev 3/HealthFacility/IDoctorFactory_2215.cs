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