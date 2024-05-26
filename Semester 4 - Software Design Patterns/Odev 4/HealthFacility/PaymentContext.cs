namespace HealthFacility
{
    public class PaymentContext
    {
        private DoctorPayment doctorPayment = new DoctorPayment();
        private NursePayment nursePayment = new NursePayment();
        private SurgeonPayment surgeonPayment = new SurgeonPayment();

        public void PaySalary(IEmployee employee, double extraHours)
        {
            if (employee is Doctor) {
                doctorPayment.PaySalary(employee, extraHours);
            }
            else if (employee is Nurse) {
                nursePayment.PaySalary(employee, extraHours);
            }
            else if (employee is Surgeon) {
                surgeonPayment.PaySalary(employee, extraHours);
            }
        }
        public void PayBonus(IEmployee employee, double amount)
        {
            if (employee is Doctor) {
                doctorPayment.PayBonus(employee, amount);
            }
            else if (employee is Nurse) {
                nursePayment.PayBonus(employee, amount);
            }
            else if (employee is Surgeon) {
                surgeonPayment.PayBonus(employee, amount);
            }
        }
    }
}