namespace HealthFacility
{
    public class Create : AbstractAppointment
    {
        public override void Execute()
        {
            if (_patient == null || _doctor == null) return;
            
            DatabaseManager db = new DatabaseManager();
            db.InsertAppointment(_patient.ID, _doctor.ID, _dateTime.ToString());

            Console.WriteLine("Appointment has been created.");
        }

        public override void Undo()
        {
            if (_patient == null || _doctor == null) return;

            DatabaseManager db = new DatabaseManager();
            AppointmentInfo? info = db.GetAppointmentInfo(_patient.ID, _doctor.ID, _dateTime);

            if (info == null) return;
            
            db.DeleteAppointment(info.ID);

            Console.WriteLine("Appointment creation has been undone.");
        }
    }
}