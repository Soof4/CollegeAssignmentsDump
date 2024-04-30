namespace HealthFacility_LSP
{
    public class DoctorAppointment : Appointment
    {
        public override int AppointmentID { get; set; }
        public override Patient Patient { get; set; }
        public override Professional Professional { get; set; }
        public override DateTime Time { get; set; }

        public DoctorAppointment(int appointmentId,
            Patient patient,
            Professional professional,
            DateTime time) : base(appointmentId, patient, professional, time)
        {
            Patient = patient;
            Professional = professional;
            Time = time;
        }

        public override void Create()
        {
            if (Professional.IsAvailable(Time))
            {
                Database.InsertAppointment(this);
                Console.WriteLine("Appointment has been created.");
            }
            else
            {
                Console.WriteLine("Couldn't create the appointment.");
            }
        }

        public override void Cancel()
        {
            base.Cancel();
        }

        public override void ChangeTime(DateTime newTime)
        {
            base.ChangeTime(newTime);
        }
    }
}