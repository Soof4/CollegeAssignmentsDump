namespace HealthFacility_ISP 
{
    public interface IClinicAppointment_ISP 
    {
        public void ScheduleAppointment(Patient patient, DateTime time);
        public void CancelAppointment(Patient patient);
    }
}