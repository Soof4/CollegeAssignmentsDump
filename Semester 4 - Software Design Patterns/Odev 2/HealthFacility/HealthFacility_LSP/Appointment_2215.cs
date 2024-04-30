namespace HealthFacility_LSP
{
    public class Appointment : IAppointment
    {
        public virtual int AppointmentID { get; set; }
        public virtual Patient Patient { get; set; }
        public virtual Professional Professional { get; set; }
        public virtual DateTime Time { get; set; }

        public Appointment(int appointmentId, Patient patient, Professional professional, DateTime time)
        {
            Patient = patient;
            Professional = professional;
            Time = time;
        }

        public virtual void Create()
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

        public virtual void Cancel()
        {
            if (Database.DeleteAppointment(AppointmentID))
            {
                Console.WriteLine("Appointment has been cancelled.");
            }
            else
            {
                Console.WriteLine("Couldn't find the appointment.");
            }
        }

        public virtual void ChangeTime(DateTime newTime)
        {
            Appointment? apt = Database.GetAppointment(AppointmentID);

            if (apt == null)
            {
                Console.WriteLine("Couldn't find the appointment.");
            }
            else
            {
                if (apt.Professional.IsAvailable(newTime)) {
                    apt.Time = newTime;
                }
                else {
                    Console.WriteLine("This time is not available. Couldn't change the time.");
                }
            }
        }
    }
}