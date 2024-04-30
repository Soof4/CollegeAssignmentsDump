namespace HealthFacility_OCP
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("\n-------------------- NOOCP --------------------\n");
            TestDoctor_NOOCP();
            Console.WriteLine("\n\n\n--------------------- OCP ---------------------\n");
            TestDoctor_OCP();
        }

        private static void TestDoctor_NOOCP() {
            Doctor dr = new Doctor(512, "Ali", "Yas", SpecialtyType.Cardiology, 25000);
            Patient pt = new Patient(10547, "Veli", "Kas");

            dr.Examine(pt);
            dr.Prescribe(pt);
            dr.AssessPatient(pt);
        }

        private static void TestDoctor_OCP() {
            IDoctor_OCP dr = new Cardiologist(512, "Ali", "Yas", 25000);
            Patient pt = new Patient(10547, "Veli", "Kas");

            dr.Examine(pt);
            dr.Prescribe(pt);
            dr.AssessPatient(pt);
        }

    }
}