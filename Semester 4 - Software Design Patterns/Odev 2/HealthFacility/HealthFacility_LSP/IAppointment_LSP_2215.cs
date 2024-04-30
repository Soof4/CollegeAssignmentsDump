namespace HealthFacility_LSP
{
    public interface IAppointment_LSP
    {
        public void Create();
        public void Cancel();
        public void ChangeTime(DateTime time);
    }
}