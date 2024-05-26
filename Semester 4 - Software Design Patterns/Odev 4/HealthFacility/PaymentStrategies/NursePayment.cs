namespace HealthFacility
{
    public class NursePayment : IPayment
    {
        public void PayBonus(IEmployee employee, double amount)
        {
            Console.WriteLine($"{employee.Name} {employee.Surname} has received {amount}.");
        }

        public void PaySalary(IEmployee employee, double extraHours)
        {
            double hourlyRate = employee.Salary / 160;
            double extraHourPayment = (1.2 * hourlyRate) * extraHours;
            Console.WriteLine($"{employee.Name} {employee.Salary} has received {employee.Salary + extraHourPayment}.");
        }
    }
}