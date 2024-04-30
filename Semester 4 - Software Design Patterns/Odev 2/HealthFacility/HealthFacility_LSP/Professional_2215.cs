namespace HealthFacility_LSP
{
    public class Professional
    {
        public int ProfessionalID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }

        public Professional(int professionalId, string name, string surname)
        {
            ProfessionalID = professionalId;
            Name = name;
            Surname = surname;
        }

        public bool IsAvailable(DateTime time) {
            List<Appointment> apts = Database.GetAllAppointmentsOfProf(ProfessionalID);

            foreach (Appointment apt in apts) {
                if (Math.Abs((apt.Time - time).TotalMinutes) < 30) {
                    return false;
                }
            }

            return true;
        }
    }
}