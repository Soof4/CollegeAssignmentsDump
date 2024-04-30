namespace HealthFacility_OCP
{
    public class Doctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public SpecialtyType Specialty { get; set; }
        public double Salary { get; set; }

        public Doctor(int doctorID, string name, string surname, SpecialtyType specialty, double salary)
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

        public void AssessPatient(Patient patient)
        {
            switch (Specialty)
            {
                case SpecialtyType.Cardiology:
                    Console.WriteLine("Cadiologic patient assessment done.");
                    break;
                case SpecialtyType.Dermatology:
                    Console.WriteLine("Dermatologic patient assessment done.");
                    break;
                case SpecialtyType.Endocrinology:
                    Console.WriteLine("Endocrinologic patient assessment done.");
                    break;
                case SpecialtyType.Gastroenterology:
                    Console.WriteLine("Gastroenterologic patient assessment done.");
                    break;
                case SpecialtyType.Hematology:
                    Console.WriteLine("Hematologic patient assessment done.");
                    break;
                case SpecialtyType.InfectiousDisease:
                    Console.WriteLine("Infectious disease patient assessment done.");
                    break;
                case SpecialtyType.Nephrology:
                    Console.WriteLine("Nephrologic patient assessment done.");
                    break;
                case SpecialtyType.Neurology:
                    Console.WriteLine("Neurologic patient assessment done.");
                    break;
                case SpecialtyType.ObstetricsAndGynecology:
                    Console.WriteLine("Obstetrics and gynecologic patient assessment done.");
                    break;
                case SpecialtyType.Oncology:
                    Console.WriteLine("Oncologic patient assessment done.");
                    break;
            }
        }
    }
}