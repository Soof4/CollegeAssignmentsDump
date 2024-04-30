namespace HealthFacility_LSP
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("\n-------------------- NOLSP --------------------\n");
            TestAppointment_NOLSP();
            Console.WriteLine("\n\n\n--------------------- LSP ---------------------\n");
            TestAppointment_LSP();
        }

        private static void TestAppointment_NOLSP()
        {
            List<Appointment> apts;
            Professional pro = new Professional(1, "Ali", "Kas");
            Patient patient = new Patient(1, "Veli", "Yas");

            // Appointment Class
            Console.WriteLine("Creating 10 appointments with Appointment class:");
            for (int i = 1; i <= 10; i++)
            {
                DateTime time = DateTime.Parse($"2024-04-15 {12 + i / 2}:{30 * (i % 2)}:00");
                Appointment apt = new Appointment(i, patient, pro, time);
                apt.Create();
            }
            apts = Database.GetAllAppointmentsOfProf(pro.ProfessionalID);
            Console.WriteLine("\nCancelling the appointments:");
            apts.ForEach(a => a.Cancel());

            // DoctorAppointment Class
            Console.WriteLine("\nCreating 10 appointments with DoctorAppointment class:");
            for (int i = 1; i <= 10; i++)
            {
                DateTime time = DateTime.Parse($"2024-04-15 {12 + i / 2}:{30 * (i % 2)}:00");
                DoctorAppointment apt = new DoctorAppointment(i, patient, pro, time);
                apt.Create();
            }
            apts = Database.GetAllAppointmentsOfProf(pro.ProfessionalID);
            Console.WriteLine("\nCancelling the appointments:");
            apts.ForEach(a => a.Cancel());

            // DiagnosticAppointment Class
            Console.WriteLine("\nCreating 10 appointments with DiagnosticAppointment class:");
            for (int i = 1; i <= 10; i++)
            {
                Device device = new Device(i, (DeviceType)i, i % 2 == 0);    // false -> true -> false -> true...
                Database.InsertDevice(device);
                DateTime time = DateTime.Parse($"2024-04-15 {12 + i / 2}:{30 * (i % 2)}:00");
                DiagnosticAppointment apt = new DiagnosticAppointment(i, patient, pro, time, device);
                apt.Create();
            }
        }

        private static void TestAppointment_LSP()
        {
            List<DoctorAppointment_LSP> docApts;

            Professional_LSP pro = new Professional_LSP(1, "Ali", "Kas");
            Patient patient = new Patient(1, "Veli", "Yas");

            // DoctorAppointment_LSP Class
            Console.WriteLine("\nCreating 10 appointments with DoctorAppointment_LSP class:");
            for (int i = 1; i <= 10; i++)
            {
                DateTime time = DateTime.Parse($"2024-04-15 {12 + i / 2}:{30 * (i % 2)}:00");
                DoctorAppointment_LSP apt = new DoctorAppointment_LSP(i, patient, pro, time);
                apt.Create();
            }

            docApts = Database_LSP.GetAllDoctorAppointmentsOfProf(pro.ProfessionalID);
            Console.WriteLine("\nCancelling the appointments:");
            docApts.ForEach(a => a.Cancel());

            // DiagnosticAppointment Class
            Console.WriteLine("\nCreating 10 appointments with DiagnosticAppointment_LSP class:");
            for (int i = 1; i <= 10; i++)
            {
                Device device = new Device(i, (DeviceType)i, i % 2 == 0);    // false -> true -> false -> true...
                Database_LSP.InsertDevice(device);
                DateTime time = DateTime.Parse($"2024-04-15 {12 + i / 2}:{30 * (i % 2)}:00");
                DiagnosticAppointment_LSP apt = new DiagnosticAppointment_LSP(i, patient, pro, time, device);
                apt.Create();
            }

        }
    }
}