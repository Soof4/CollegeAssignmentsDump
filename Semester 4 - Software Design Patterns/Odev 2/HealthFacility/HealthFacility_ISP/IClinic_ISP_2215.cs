namespace HealthFacility_ISP
{
    public interface IClinic_ISP
    {
        public void RegisterPatient(Patient patient);
        public void UnregisterPatient(Patient patient);
        public void PerformTreatment(Patient patient);
    }
}