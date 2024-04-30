namespace HealthFacility_ISP 
{
    public class UrgentCareClinic_ISP : IClinic, IClinicNumberSystem_ISP, IClinicPayment_ISP 
    {
        private static List<Patient> registeredPatients = new List<Patient>();
        private static int currentNumber = 0;
        private static List<Payment> recordedPayments = new List<Payment>();
        private static int currentPaymentID = 0;

        public void ScheduleAppointment(Patient patient, DateTime time) { }
        public void CancelAppointment(Patient patient) { }

        public void PerformTreatment(Patient patient)
        {
            Console.WriteLine($"Treatment performed for {patient.Name} {patient.Surname}.");
        }

        public void RecordPayment(Patient patient, int amount)
        {
            currentPaymentID++;
            Payment payment = new Payment(currentPaymentID, patient, amount);
            recordedPayments.Add(payment);
            Console.WriteLine("Payment has been recorded.");
        }

        public void RegisterPatient(Patient patient)
        {
            foreach (Patient p in registeredPatients)
            {
                if (p.PatientID == patient.PatientID)
                {
                    Console.WriteLine("Couldn't register the patient. There already is a registered patient with same ID");
                    return;
                }
            }

            registeredPatients.Add(patient);
        }
        public void UnregisterPatient(Patient patient)
        {
            foreach (Patient p in registeredPatients)
            {
                if (p.PatientID == patient.PatientID)
                {
                    registeredPatients.Remove(p);
                    return;
                }
            }

            Console.WriteLine("Couldn't unregister the patient. There is no patient that fits the information provided.");
        }
        public void TakeANumber()
        {
            currentNumber++;
            Console.WriteLine($"Number: {currentNumber}");
        }
    }
}