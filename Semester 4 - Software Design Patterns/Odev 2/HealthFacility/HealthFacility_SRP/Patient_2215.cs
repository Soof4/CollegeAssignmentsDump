namespace HealthFacility_SRP
{
    public class Patient
    {
        public int PatientID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }

        public Patient(int patientID, string name, string surname)
        {
            PatientID = patientID;
            Name = name;
            Surname = surname;
        }
    }
}