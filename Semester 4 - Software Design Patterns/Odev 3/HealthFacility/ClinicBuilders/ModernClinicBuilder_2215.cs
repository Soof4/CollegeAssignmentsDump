namespace HealthFacility
{
    public class ModernClinicBuilder : IClinicBuilder
    {
        private ModernClinic _clinic = new ModernClinic();


        public void AddDoctor(IDoctor doctor)
        {
            _clinic.Doctors.Add(doctor);
        }

        public void AddLaboratory(int number)
        {
            _clinic.NumberOfLaboratories += number;
        }

        public void AddNurse(int number)
        {
            _clinic.NumberOfNurses += number;
        }

        public void AddPatientRoom(int number)
        {
            _clinic.NumberOfPatientRooms += number;
        }

        public void AddReceptionDesk()
        {
            _clinic.HasReceptionDesk = true;
        }

        public void Reset()
        {
            _clinic = new ModernClinic();
        }

        public ModernClinic GetResult() {
            return _clinic;
        }
    }
}