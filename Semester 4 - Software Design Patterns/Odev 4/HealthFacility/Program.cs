namespace HealthFacility
{
    public class Program
    {
        public static DatabaseManager dbManager = new DatabaseManager();
        public static void Main(string[] args)
        {
            Console.WriteLine("\n\n\n");
            Console.WriteLine("---- Facade ----");
            TestFacade();

            Console.WriteLine("\n\n\n");
            Console.WriteLine("---- Composite ----");
            TestComposite();

            Console.WriteLine("\n\n\n");
            Console.WriteLine("---- Strategy ----");
            TestStrategy();

            Console.WriteLine("\n\n\n");
            Console.WriteLine("---- Command ----");
            TestCommand();
        }

        public static void TestFacade()
        {
            HealthFacility facility = new HealthFacility();
            facility.Initialize();
        }

        public static void TestComposite()
        {
            Polyclinic clinic = (Polyclinic)dbManager.GetAllPolyclinics()[0];

            IDepartment dep1 = dbManager.GetDepartment(1)!;
            IDepartment dep2 = dbManager.GetDepartment(2)!;
            IDepartment dep3 = dbManager.GetDepartment(3)!;
            IDepartment dep4 = dbManager.GetDepartment(4)!;

            clinic.AddDepartment(dep1);
            clinic.AddDepartment(dep2);
            clinic.AddDepartment(dep3);
            clinic.AddDepartment(dep4);

            clinic.Open();

            clinic.ShowInfo();

            clinic.Close();
        }

        public static void TestStrategy()
        {
            PaymentContext payCon = new PaymentContext();

            Doctor dr = dbManager.GetDoctor(1)!;
            Nurse nr = dbManager.GetNurse(1)!;
            Surgeon sr = dbManager.GetSurgeon(1)!;

            payCon.PaySalary(dr, 5);
            payCon.PaySalary(nr, 5);
            payCon.PaySalary(sr, 5);

            payCon.PayBonus(dr, 1000);
            payCon.PayBonus(nr, 5000);
            payCon.PayBonus(sr, 15000);
        }

        public static void TestCommand()
        {
            Patient patient = dbManager.GetPatient(1)!;
            Doctor dr = dbManager.GetDoctor(1)!;

            IAppointment app = new Create();
            app.SetPatient(patient);
            app.SetDoctor(dr);
            app.SetDateTime(DateTime.Today);
            
            app.Execute();
            app.Undo();
            app.Redo();
        }
    }
}