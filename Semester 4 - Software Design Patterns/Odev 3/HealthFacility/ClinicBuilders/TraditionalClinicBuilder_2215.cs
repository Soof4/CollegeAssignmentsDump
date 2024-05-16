namespace HealthFacility
{
    public class TraditionalClinicBuilder : IClinicBuilder
    {
        private TraditionalClinic _clinic = new TraditionalClinic();


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
            _clinic = new TraditionalClinic();
        }

        public TraditionalClinic GetResult()
        {
            return _clinic;
        }
    }
}