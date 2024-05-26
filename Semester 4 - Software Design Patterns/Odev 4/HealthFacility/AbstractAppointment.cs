
namespace HealthFacility
{
    public abstract class AbstractAppointment : IAppointment
    {
        protected int ID;
        protected Patient? _patient;
        protected Doctor? _doctor;
        protected DateTime _dateTime;

        public abstract void Execute();

        public List<IAppointment> GetAppointments()
        {
            return _patient?.Appointments ?? new List<IAppointment>();  // return an empty list if _patient is null
        }

        public void Redo()
        {
            Execute();
        }

        public void SetDoctor(Doctor doctor)
        {
            _doctor = doctor;
        }

        public void SetPatient(Patient patient)
        {
            _patient = patient;
        }

        public void SetDateTime(DateTime dateTime)
        {
            _dateTime = dateTime;
        }

        public abstract void Undo();
    }
}