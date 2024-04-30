namespace HealthFacility_SRP
{
    public class Doctor_SRP
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public SpecialtyType Specialty { get; set; }
        public double Salary { get; set; }

        public Doctor_SRP(int doctorID, string name, string surname, SpecialtyType specialty, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Specialty = specialty;
            Salary = salary;
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