namespace HealthFacility_ISP
{
    public class SpecialtyClinic : IClinic
    {
        private static List<Patient> RegisteredPatients = new List<Patient>();
        private static List<Payment> RecordedPayments = new List<Payment>();
        private static int CurrentPaymentID = 0;
        private static Dictionary<Patient, DateTime> appointments = new Dictionary<Patient, DateTime>();

        public void ScheduleAppointment(Patient patient, DateTime time)
        {
            foreach (var kvp in appointments)
            {
                if (kvp.Key.PatientID == patient.PatientID)
                {
                    appointments[kvp.Key] = time;
                    Console.WriteLine("This patient already has an appointment. So, the appointment time has changed.");
                    return;
                }
            }

            appointments.Add(patient, time);
            Console.WriteLine("Scheduled a new appointment.");
        }
        public void CancelAppointment(Patient patient)
        {
            Patient? target = null;
            foreach (var kvp in appointments)
            {
                if (kvp.Key.PatientID == patient.PatientID)
                {
                    target = kvp.Key;
                    break;
                }
            }

            if (target == null)
            {
                Console.WriteLine("Patient was not found.");
            }
            else
            {
                appointments.Remove(target);
                Console.WriteLine("Appointment has been cancelled.");
            }
        }

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
        public void TakeANumber() { }
    }
}