namespace HealthFacility_ISP
{
    public class Payment
    {
        public int PaymentID { get; set; }
        public Patient Patient { get; set; }
        public int Amount { get; set; }

        public Payment(int paymentID, Patient patient, int amount)
        {
            PaymentID = paymentID;
            Patient = patient;
            Amount = amount;
        }
    }
}