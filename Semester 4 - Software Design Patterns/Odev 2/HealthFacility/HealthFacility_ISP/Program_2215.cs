namespace HealthFacility_ISP
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("\n-------------------- NOISP --------------------\n");
            TestClinic_NOLSP();
            Console.WriteLine("\n\n\n--------------------- ISP ---------------------\n");
            TestClinic_LSP();
        }

        private static void TestClinic_NOLSP()
        {
            FamilyClinic famClinic = new FamilyClinic();
            SpecialtyClinic speClinic = new SpecialtyClinic();
            UrgentCareClinic urgClinic = new UrgentCareClinic();

            Patient patient = new Patient(1, "Ali", "Yas");

            Console.WriteLine("\nFamilyClinic's All Methods:");
            famClinic.RegisterPatient(patient);
            famClinic.UnregisterPatient(patient);
            famClinic.ScheduleAppointment(patient, DateTime.UtcNow);
            famClinic.CancelAppointment(patient);
            famClinic.TakeANumber();
            famClinic.PerformTreatment(patient);
            famClinic.RecordPayment(patient, 2000);

            Console.WriteLine("\nSpecialtyClinic's All Methods");
            speClinic.RegisterPatient(patient);
            speClinic.UnregisterPatient(patient);
            speClinic.ScheduleAppointment(patient, DateTime.UtcNow);
            speClinic.CancelAppointment(patient);
            speClinic.TakeANumber();
            speClinic.PerformTreatment(patient);
            speClinic.RecordPayment(patient, 2000);

            Console.WriteLine("\nUrgentCareClinic's All Methods");
            urgClinic.RegisterPatient(patient);
            urgClinic.UnregisterPatient(patient);
            urgClinic.ScheduleAppointment(patient, DateTime.UtcNow);
            urgClinic.CancelAppointment(patient);
            urgClinic.TakeANumber();
            urgClinic.PerformTreatment(patient);
            urgClinic.RecordPayment(patient, 2000);
        }

        private static void TestClinic_LSP()
        {
            FamilyClinic_ISP famClinic = new FamilyClinic_ISP();
            SpecialtyClinic_ISP speClinic = new SpecialtyClinic_ISP();
            UrgentCareClinic_ISP urgClinic = new UrgentCareClinic_ISP();

            Patient patient = new Patient(1, "Ali", "Yas");

            Console.WriteLine("\nFamilyClinic_ISP's All Methods:");
            famClinic.RegisterPatient(patient);
            famClinic.UnregisterPatient(patient);
            famClinic.TakeANumber();
            famClinic.PerformTreatment(patient);

            Console.WriteLine("\nSpecialtyClinic_ISP's All Methods");
            speClinic.RegisterPatient(patient);
            speClinic.UnregisterPatient(patient);
            speClinic.ScheduleAppointment(patient, DateTime.UtcNow);
            speClinic.CancelAppointment(patient);
            speClinic.PerformTreatment(patient);
            speClinic.RecordPayment(patient, 2000);

            Console.WriteLine("\nUrgentCareClinic_ISP's All Methods");
            urgClinic.RegisterPatient(patient);
            urgClinic.UnregisterPatient(patient);
            urgClinic.ScheduleAppointment(patient, DateTime.UtcNow);
            urgClinic.CancelAppointment(patient);
            urgClinic.TakeANumber();
            urgClinic.PerformTreatment(patient);
            urgClinic.RecordPayment(patient, 2000);
        }
    }
}