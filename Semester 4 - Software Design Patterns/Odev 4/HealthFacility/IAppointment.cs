namespace HealthFacility
{
    public interface IAppointment
    {
        public void Execute();
        public void Undo();
        public void Redo();
        public List<IAppointment> GetAppointments();
        public void SetPatient(Patient patient);
        public void SetDoctor(Doctor doctor);
        public void SetDateTime(DateTime dateTime);
    }
}