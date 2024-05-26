namespace HealthFacility
{
    public class AppointmentInfo
    {
        public int ID { get; set; }
        public Patient? Patient { get; set; }
        public Doctor? Doctor { get; set; }
        public DateTime DateTime { get; set; }

        public AppointmentInfo(int id, Patient patient, Doctor doctor, DateTime dateTime)
        {
            ID = id;
            Patient = patient;
            Doctor = doctor;
            DateTime = dateTime;
        }
    }
}