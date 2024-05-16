namespace HealthFacility {
    public interface IDoctor {
        public int DoctorID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }

        public void Examine(Patient patient);
        public void Prescribe(Patient patient);
        public void ReferPatientToDoctor(Patient patient, IDoctor doctor);
        public void ReceiveSalary();
    }
}