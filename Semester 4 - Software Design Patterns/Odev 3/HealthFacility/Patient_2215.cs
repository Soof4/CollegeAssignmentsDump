namespace HealthFacility
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

        public Patient(string name, string surname)
        {
            Program.dbManager.InsertPatient(name, surname);
            List<Patient> patients = Program.dbManager.GetPatients(name, surname);
            Patient pt = patients[^1];

            PatientID = pt.PatientID;
            Name = pt.Name;
            Surname = pt.Surname;
        }
    }
}