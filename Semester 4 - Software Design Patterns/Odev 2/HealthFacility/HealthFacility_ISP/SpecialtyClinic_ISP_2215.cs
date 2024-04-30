namespace HealthFacility_ISP 
{
    public class SpecialtyClinic_ISP : IClinic_ISP, IClinicAppointment_ISP, IClinicPayment_ISP 
    {
        private static List<Patient> registeredPatients = new List<Patient>();
        private static int currentNumber = 0;
        private static List<Payment> recordedPayments = new List<Payment>();
        private static int currentPaymentID = 0;
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
    }
}