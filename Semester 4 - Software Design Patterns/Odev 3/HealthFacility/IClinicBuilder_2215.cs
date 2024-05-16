namespace HealthFacility
{
    public interface IClinicBuilder
    {
        public void AddDoctor(IDoctor doctor);
        public void AddPatientRoom(int number);
        public void AddNurse(int number);
        public void AddReceptionDesk();
        public void AddLaboratory(int number);
        public void Reset();
    }
}