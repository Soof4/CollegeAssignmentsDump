namespace HealthFacility_OCP
{
    public class InfectiousDiseaseSpecialist : IDoctor_OCP
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }

        public InfectiousDiseaseSpecialist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void AssessPatient(Patient patient)
        {
            Console.WriteLine("Infectious disease patient assessment done.");
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"Dr. {Name} {Surname} has examined {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"Dr. {Name} {Surname} has written a prescription for {patient.Name} {patient.Surname}.");

        }
    }
}