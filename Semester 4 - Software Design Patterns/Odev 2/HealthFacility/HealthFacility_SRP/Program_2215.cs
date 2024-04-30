namespace HealthFacility_SRP
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("\n-------------------- NOSRP --------------------\n");
            TestDoctor_NOSRP();
            Console.WriteLine("\n\n\n--------------------- SRP ---------------------\n");
            TestDoctor_SRP();
        }

        private static void TestDoctor_NOSRP() {
            Doctor dr = new Doctor(512, "Ali", "Yas", SpecialtyType.Cardiology, 25000);
            Patient pt = new Patient(10547, "Veli", "Kas");

            dr.Examine(pt);
            dr.Prescribe(pt);
            dr.SaveDoctorToDatabase();
            dr.PayDoctor();
        }

        private static void TestDoctor_SRP() {
            Doctor_SRP dr = new Doctor_SRP(512, "Ali", "Yas", SpecialtyType.Cardiology, 25000);
            Patient pt = new Patient(10547, "Veli", "Kas");

            dr.Examine(pt);
            dr.Prescribe(pt);
            DatabaseManager_SRP.Connect();
            DatabaseManager_SRP.InsertDoctor(dr);
            SalaryManager_SRP.PayDoctor(dr);
            DatabaseManager_SRP.Disconnect();
        }
    }
}