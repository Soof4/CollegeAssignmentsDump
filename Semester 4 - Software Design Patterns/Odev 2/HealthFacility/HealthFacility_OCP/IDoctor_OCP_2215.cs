namespace HealthFacility_OCP
{
    public interface IDoctor_OCP
    {
        public void Examine(Patient patient);
        public void Prescribe(Patient patient);
        public void AssessPatient(Patient patient);
    }
}