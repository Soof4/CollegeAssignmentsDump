
namespace HealthFacility
{
    public class Polyclinic : AbstractDepartment, ICompositeDepartment
    {
        protected List<IDepartment> Departments { get; set; } = new List<IDepartment>();
        protected List<Doctor> Doctors { get; set; } = new List<Doctor>();
        protected List<Nurse> Nurses { get; set; } = new List<Nurse>();

        public Polyclinic(string name, int id, bool isOpen) : base(name, id, isOpen) { }


        public void AddDepartment(IDepartment department)
        {
            Departments.Add(department);
        }

        public void AddDepartments(IEnumerable<IDepartment> departments)
        {
            Departments = Departments.Concat(departments).ToList();
        }

        public IEnumerable<IDepartment> GetDepartments()
        {
            return Departments;
        }

        public void ListDeparments()
        {
            Departments.ForEach(d => Console.WriteLine(d));
        }

        public void RemoveDepartment(IDepartment department)
        {
            Departments.Remove(department);
        }

        public void RemoveDepartment(int index)
        {
            Departments.RemoveAt(index);
        }

        public override void ShowInfo()
        {
            List<string?> result = new List<string?>() {
                ToString(),
                $"Department count: {Departments.Count}",
                "List of departments:"
            };

            Departments.ForEach(d => result.Add(d.ToString()));

            Utils.PrintAsBox(result);
        }

        public void AddDoctor(Doctor doctor)
        {
            Doctors.Add(doctor);
        }

        public void AddNurse(Nurse nurse)
        {
            Nurses.Add(nurse);
        }
    }
}