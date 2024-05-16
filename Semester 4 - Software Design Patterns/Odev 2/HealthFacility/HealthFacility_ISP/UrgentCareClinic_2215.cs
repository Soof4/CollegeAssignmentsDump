namespace HealthFacility_ISP
{
    public class UrgentCareClinic : IClinic
    {
        private static List<Patient> RegisteredPatients = new List<Patient>();
        private static int CurrentNumber = 0;
        private static List<Payment> RecordedPayments = new List<Payment>();
        private static int CurrentPaymentID = 0;

        public void ScheduleAppointment(Patient patient, DateTime time) { }
        public void CancelAppointment(Patient patient) { }

        public void PerformTreatment(Patient patient)
        {
            Console.WriteLine($"Treatment performed for {patient.Name} {patient.Surname}.");
        }

        public void RecordPayment(Patient patient, int amount)
        {
            CurrentPaymentID++;
            Payment payment = new Payment(CurrentPaymentID, patient, amount);
            RecordedPayments.Add(payment);
            Console.WriteLine("Payment has been recorded.");
        }

        public void RegisterPatient(Patient patient)
        {
            foreach (Patient p in RegisteredPatients)
            {
                if (p.PatientID == patient.PatientID)
                {
                    Console.WriteLine("Couldn't register the patient. There already is a registered patient with same ID");
                    return;
                }
            }

            RegisteredPatients.Add(patient);
        }
        public void UnregisterPatient(Patient patient)
        {
            foreach (Patient p in RegisteredPatients)
            {
                if (p.PatientID == patient.PatientID)
                {
                    RegisteredPatients.Remove(p);
                    return;
                }
            }

            Console.WriteLine("Couldn't unregister the patient. There is no patient that fits the information provided.");
        }
        public void TakeANumber()
        {
            CurrentNumber++;
            Console.WriteLine($"Number: {CurrentNumber}");
        }
    }
}