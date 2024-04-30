namespace HealthFacility_DIP
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("\n-------------------- NODIP --------------------\n");
            TestMedicineSys_NODIP();
            Console.WriteLine("\n\n\n--------------------- DIP ---------------------\n");
            TestMedicineSys_DIP();
        }
        private static void TestMedicineSys_NODIP()
        {
            MedicineSystem medSys = new MedicineSystem();

            for (int i = 0; i < 3; i++)
            {
                Cream m = new Cream(i);
                medSys.RegisterCream(m, 10);
            }

            for (int i = 0; i < 3; i++)
            {
                Drug m = new Drug(i);
                medSys.RegisterDrug(m, 10);
            }

            for (int i = 0; i < 3; i++)
            {
                Syrup m = new Syrup(i);
                medSys.RegisterSyrup(m, 10);
            }

            for (int i = 0; i < 3; i++)
            {
                Vaccine m = new Vaccine(i);
                medSys.RegisterVaccine(m, 10);
            }

            medSys.TestAllMedicine();
        }

        private static void TestMedicineSys_DIP()
        {
            MedicineSystem_DIP medSys = new MedicineSystem_DIP();
            int i = 0;

            for (i = 0; i < 3; i++)
            {
                Cream_DIP m = new Cream_DIP(i);
                medSys.RegisterMedicine(m, 10);
            }

            for (; i < 6; i++)
            {
                Drug_DIP m = new Drug_DIP(i);
                medSys.RegisterMedicine(m, 10);
            }

            for (; i < 9; i++)
            {
                Syrup_DIP m = new Syrup_DIP(i);
                medSys.RegisterMedicine(m, 10);
            }

            for (; i < 12; i++)
            {
                Vaccine_DIP m = new Vaccine_DIP(i);
                medSys.RegisterMedicine(m, 10);
            }

            medSys.TestAllMedicine();
        }
    }
}