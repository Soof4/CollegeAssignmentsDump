namespace HealthFacility
{
    public interface ICompositeDepartment
    {
        public void AddDepartment(IDepartment department);
        public void AddDepartments(IEnumerable<IDepartment> departments);
        public void RemoveDepartment(IDepartment department);
        public void RemoveDepartment(int index);
        public IEnumerable<IDepartment> GetDepartments();
        public void ListDeparments();
    }
}