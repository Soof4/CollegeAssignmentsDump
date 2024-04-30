namespace HealthFacility_LSP
{
    public class DiagnosticAppointment : Appointment
    {
        public override int AppointmentID { get; set; }
        public override Patient Patient { get; set; }
        public override Professional Professional { get; set; }
        public override DateTime Time { get; set; }
        public Device Device { get; set; }

        public DiagnosticAppointment(int appointmentId,
            Patient patient,
            Professional professional,
            DateTime time,
            Device device) : base(appointmentId, patient, professional, time)
        {
            AppointmentID = appointmentId;
            Patient = patient;
            Professional = professional;
            Time = time;
            Device = device;
        }

        public override void Create()
        {
            if (Professional.IsAvailable(Time) && Device.IsAvailable())
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