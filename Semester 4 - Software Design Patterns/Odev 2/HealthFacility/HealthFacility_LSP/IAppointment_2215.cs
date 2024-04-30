namespace HealthFacility_LSP
{
    public interface IAppointment
    {
        public void Create();
        public void Cancel();
        public void ChangeTime(DateTime newTime);
    }
}