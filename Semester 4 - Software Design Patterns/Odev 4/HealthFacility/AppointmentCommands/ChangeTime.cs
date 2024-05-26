namespace HealthFacility
{
    public class ChangeTime : AbstractAppointment
    {
        private DateTime prevDateTime;
        public override void Execute()
        {
            if (_patient == null || _doctor == null) return;

            prevDateTime = _dateTime;
            DatabaseManager db = new DatabaseManager();
            db.UpdateAppointment(ID, _patient.ID, _doctor.ID, _dateTime.ToString());

            Console.WriteLine("Appointment time has been changed.");

        }

        public override void Undo()
        {
            if (_patient == null || _doctor == null) return;

            DatabaseManager db = new DatabaseManager();
            db.UpdateAppointment(ID, _patient.ID, _doctor.ID, prevDateTime.ToString());

            Console.WriteLine("Appointment time change has been undone.");
        }

        public void SetTime(DateTime dateTime)
        {
            _dateTime = dateTime;
        }
    }
}