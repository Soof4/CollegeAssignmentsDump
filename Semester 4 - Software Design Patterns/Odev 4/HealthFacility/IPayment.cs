namespace HealthFacility
{
    public interface IPayment
    {
        public void PaySalary(IEmployee employee, double extraHours);
        public void PayBonus(IEmployee employee, double amount);
    }
}