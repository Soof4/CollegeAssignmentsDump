namespace HealthFacility
{
    public interface IEmployee
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }
    }
}