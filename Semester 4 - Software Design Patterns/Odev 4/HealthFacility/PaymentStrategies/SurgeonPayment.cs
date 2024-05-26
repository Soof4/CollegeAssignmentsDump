namespace HealthFacility
{
    public class SurgeonPayment : IPayment
    {
        public void PayBonus(IEmployee employee, double amount)
        {
            Console.WriteLine($"{employee.Name} {employee.Surname} has received {amount}.");
        }

        public void PaySalary(IEmployee employee, double extraHours)
        {
            double hourlyRate = employee.Salary / 160;
            double extraHourPayment = (2 * hourlyRate) * extraHours;
            Console.WriteLine($"{employee.Name} {employee.Salary} has received {employee.Salary + extraHourPayment}.");
        }
    }
}