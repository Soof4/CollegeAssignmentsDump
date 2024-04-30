
namespace HealthFacility_ISP 
{
    public class FamilyClinic_ISP : IClinic_ISP, IClinicNumberSystem_ISP
    {
    private static List<Patient> registeredPatients = new List<Patient>();
        private static int currentNumber = 0;

        public void PerformTreatment(Patient patient)
        {
            Console.WriteLine($"Treatment performed for {patient.Name} {patient.Surname}.");
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

        public static implicit operator FamilyClinic_ISP(FamilyClinic v)
        {
            throw new NotImplementedException();
        }
    }
}