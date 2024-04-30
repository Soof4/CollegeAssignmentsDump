namespace HealthFacility_ISP
{
    public interface IClinic
    {
        public void RegisterPatient(Patient patient);
        public void UnregisterPatient(Patient patient);
        public void ScheduleAppointment(Patient patient, DateTime time);
        public void CancelAppointment(Patient patient);
        public void TakeANumber();
        public void PerformTreatment(Patient patient);
        public void RecordPayment(Patient patient, int amount);
    }
}