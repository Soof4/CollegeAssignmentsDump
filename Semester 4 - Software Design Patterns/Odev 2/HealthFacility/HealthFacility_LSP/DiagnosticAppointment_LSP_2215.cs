namespace HealthFacility_LSP
{
    public class DiagnosticAppointment_LSP : IAppointment_LSP
    {
        public int AppointmentID { get; set; }
        public Patient Patient { get; set; }
        public Professional_LSP Professional { get; set; }
        public DateTime Time { get; set; }
        public Device Device { get; set; }

        public DiagnosticAppointment_LSP(int appointmentId,
            Patient patient,
            Professional_LSP professional,
            DateTime time,
            Device device)
        {
            AppointmentID = appointmentId;
            Patient = patient;
            Professional = professional;
            Time = time;
            Device = device;
        }

        public void Create()
        {
            if (Professional.IsAvailable(Time) && Device.IsAvailable())
            {
                Database_LSP.InsertDiagnosticAppointment(this);
                Console.WriteLine("Appointment has been created.");
            }
            else
            {
                Console.WriteLine("Couldn't create the appointment.");
            }
        }

        public void Cancel()
        {
            if (Database_LSP.DeleteDiagnosticAppointment(AppointmentID))
            {
                Console.WriteLine("Appointment has been cancelled.");
            }
            else
            {
                Console.WriteLine("Couldn't find the appointment.");
            }
        }

        public void ChangeTime(DateTime newTime)
        {
            DiagnosticAppointment_LSP? apt = Database_LSP.GetDiagnosticAppointment(AppointmentID);

            if (apt == null)
            {
                Console.WriteLine("Couldn't find the appointment.");
            }
            else
            {
                if (apt.Professional.IsAvailable(newTime))
                {
                    apt.Time = newTime;
                }
                else
                {
                    Console.WriteLine("This time is not available. Couldn't change the time.");
                }
            }
        }
    }
}