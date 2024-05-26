namespace HealthFacility
{
    public class DoctorPayment : IPayment
    {
        public void PayBonus(IEmployee employee, double amount)
        {
            Console.WriteLine($"{employee.Name} {employee.Surname} has received {amount}.");
        }

        public void PaySalary(IEmployee employee, double extraHours)
        {
            double hourlyRate = employee.Salary / 160;
            double extraHourPayment = (1.5 * hourlyRate) * extraHours;
            Console.WriteLine($"{employee.Name} {employee.Salary} has received {employee.Salary + extraHourPayment}.");
        }
    }
}