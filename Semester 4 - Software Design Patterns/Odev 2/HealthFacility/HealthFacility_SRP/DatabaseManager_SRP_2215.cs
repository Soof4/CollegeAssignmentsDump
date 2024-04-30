namespace HealthFacility_SRP
{
    public class DatabaseManager_SRP
    {
        public static void Connect()
        {
            Console.WriteLine("Connected to the database.");
        }

        public static void Disconnect()
        {
            Console.WriteLine("Disconnected from the database.");
        }

        public static void InsertDoctor(Doctor_SRP doctor)
        {
            Console.WriteLine($"Dr. {doctor.Name} {doctor.Surname} has been inserted to the database.");
        }

        public static void DeleteDoctor(Doctor_SRP doctor)
        {
            Console.WriteLine($"Dr. {doctor.Name} {doctor.Surname} has been deleted from the database.");
        }

        public static void UpdateDoctor(Doctor_SRP doctor)
        {
            Console.WriteLine($"Dr. {doctor.Name} {doctor.Surname} has been updated.");
        }
    }
}