namespace HealthFacility_SRP
{
    public static class SalaryManager_SRP
    {
        public static void PayDoctor(Doctor_SRP doctor)
        {
            Console.WriteLine($"Dr. {doctor.Name} {doctor.Surname} has been paid ${doctor.Salary}.");
        }

        public static void ModifySalary(Doctor_SRP doctor, int amount) {
            doctor.Salary += amount;
            Console.WriteLine($"Dr. {doctor.Name} {doctor.Surname}'s salary has been increased by {amount}.");
        }
    }
}