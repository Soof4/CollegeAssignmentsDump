namespace HealthFacility_ISP 
{
    public interface IClinicPayment_ISP 
    {
        public void RecordPayment(Patient patient, int amount);
    }
}