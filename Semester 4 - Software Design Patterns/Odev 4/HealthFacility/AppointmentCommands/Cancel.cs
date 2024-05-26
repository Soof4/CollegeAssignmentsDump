namespace HealthFacility
{
    public class Cancel : AbstractAppointment
    {
        public override void Execute()
        {
            if (_patient == null || _doctor == null) return;

            DatabaseManager db = new DatabaseManager();
            db.DeleteAppointment(ID);

            Console.WriteLine("Appointment has been cancelled.");
        }

        public override void Undo()
        {
            if (_patient == null || _doctor == null) return;

            DatabaseManager db = new DatabaseManager();
            db.InsertAppointment(_patient.ID, _doctor.ID, _dateTime.ToString());

            AppointmentInfo? info = db.GetAppointmentInfo(_patient.ID, _doctor.ID, _dateTime);

            if (info == null) return;
            
            ID = info.ID;

            Console.WriteLine("Appointment cancellation has been undone.");
        }
    }
}