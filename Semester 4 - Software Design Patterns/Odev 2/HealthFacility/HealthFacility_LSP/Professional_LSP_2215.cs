namespace HealthFacility_LSP
{
    public class Professional_LSP
    {
        public int ProfessionalID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }

        public Professional_LSP(int professionalId, string name, string surname)
        {
            ProfessionalID = professionalId;
            Name = name;
            Surname = surname;
        }

        public bool IsAvailable(DateTime time) {
            List<DoctorAppointment_LSP> apts = Database_LSP.GetAllDoctorAppointmentsOfProf(ProfessionalID);

            foreach (DoctorAppointment_LSP apt in apts) {
                if (Math.Abs((apt.Time - time).TotalMinutes) < 30) {
                    return false;
                }
            }

            List<DiagnosticAppointment_LSP> apts2 = Database_LSP.GetAllDiagnosticAppointmentsOfProf(ProfessionalID);

            foreach (DoctorAppointment_LSP apt in apts) {
                if (Math.Abs((apt.Time - time).TotalMinutes) < 30) {
                    return false;
                }
            }

            return true;
        }
    }
}