namespace HealthFacility
{
    public class Hematologist : IDoctor
    {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }


        public Hematologist(int doctorID, string name, string surname, double salary)
        {
            DoctorID = doctorID;
            Name = name;
            Surname = surname;
            Salary = salary;
        }

        public void Examine(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is examining {patient.Name} {patient.Surname}.");
        }

        public void Prescribe(Patient patient)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is presribing {patient.Name} {patient.Surname}.");
        }

        public void ReceiveSalary()
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is recieving their payment.");
        }

        public void ReferPatientToDoctor(Patient patient, IDoctor doctor)
        {
            Console.WriteLine($"{GetType().Name} {Name} {Surname} is referring {patient.Name} {patient.Surname} to Dr. {doctor.Name} {doctor.Surname}");
        }
    }
}