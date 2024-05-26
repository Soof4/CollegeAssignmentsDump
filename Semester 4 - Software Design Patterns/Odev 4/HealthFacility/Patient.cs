namespace HealthFacility
{
    public class Patient
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public List<IAppointment> Appointments { get; set; } = new List<IAppointment>();
        
        public Patient(int id, string name, string surname)
        {
            ID = id;
            Name = name;
            Surname = surname;
        }
    }
}