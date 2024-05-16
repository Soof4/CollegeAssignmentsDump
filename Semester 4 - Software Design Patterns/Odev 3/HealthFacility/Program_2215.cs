using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class Program
    {
        public static DatabaseManager dbManager = new DatabaseManager("DataSource=./HealthFacility.db;Version=3;");

        public static void Main(string[] args)
        {
            Console.WriteLine("\n\n-----------------------------------------\nFactory Method:\n");
            TestFactoryMethod();

            Console.WriteLine("\n\n-----------------------------------------\nAbstract Factory:\n");
            TestAbstractFactory();

            Console.WriteLine("\n\n-----------------------------------------\nBuilder:\n");
            TestBuilder();

            Console.WriteLine("\n\n-----------------------------------------\nDependency Injection:\n");
            TestDependecyInjection();
        }

        public static void TestFactoryMethod()
        {
            IDoctorFactory factory = new CardiologistFactory();
            IDoctor dr1 = factory.CreateDoctor("Ali", "Yaş", 35000);

            factory = new NeurologistFactory();
            IDoctor dr2 = factory.CreateDoctor("Veli", "Kaş", 30000);

            factory = new PsychiatristFactory();
            IDoctor dr3 = factory.CreateDoctor("Fatma", "Taş", 45000);

            List<IDoctor> drList = new List<IDoctor>() {
                dr1,
                dr2,
                dr3
            };

            Utils.PrintListAsTable(drList);
        }

        public static void TestAbstractFactory()
        {
            OverTheCounterMedicineFactory otcFactory = new OverTheCounterMedicineFactory();
            IPill? pill = otcFactory.CreatePill(1);
            ICream? cream = otcFactory.CreateCream(2);
            ISyrup? syrup = otcFactory.CreateSyrup(3);

            Patient? patient = dbManager.GetPatient(1);

            pill?.Swallow(patient!);
            cream?.Apply(patient!);
            syrup?.Ingest(patient!);

            pill?.SellTo(patient!);
            cream?.SellTo(patient!);
            syrup?.SellTo(patient!);
        }

        public static void TestBuilder()
        {
            ModernClinicBuilder builder = new ModernClinicBuilder();
            ClinicDirector director = new ClinicDirector(builder);

            IDoctor? doctor = dbManager.GetDoctor(1);
            director.BuildAdvancedClinic(doctor!, 5, 6, 0);

            ModernClinic clinic = builder.GetResult();
            clinic.ShowInfo();
        }

        public static void TestDependecyInjection()
        {
            IDoctor? doctor = dbManager.GetDoctor(5);
            Patient? patient = dbManager.GetPatient(5);

            IReport report = new Report(doctor!, patient!);

            report.PrintToConsole();
            report.PrintAsFile();
        }
    }
}
