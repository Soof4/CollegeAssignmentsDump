namespace HealthFacility
{
    public class Surgeon : IEmployee
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public double Salary { get; set; }
        
        public Surgeon(int id, string name, string surname, double salary)
        {
            ID = id;
            Name = name;
            Surname = surname;
            Salary = salary;
        }
    }
}