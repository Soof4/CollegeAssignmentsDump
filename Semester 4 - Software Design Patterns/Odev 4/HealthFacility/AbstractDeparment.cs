namespace HealthFacility
{
    public abstract class AbstractDepartment : IDepartment
    {
        protected int ID { get; set; }
        protected string Name { get; set; }
        protected bool IsOpen { get; set; }

        public AbstractDepartment(string name, int id, bool isOpen)
        {
            ID = id;
            Name = name;
            IsOpen = isOpen;
        }

        public void Close()
        {
            IsOpen = false;
            Console.WriteLine($"{Name} has been closed.");
        }

        public void Open()
        {
            IsOpen = true;
            Console.WriteLine($"{Name} has been opened.");

        }

        public abstract void ShowInfo();

        public override string ToString()
        {
            return $"ID: {ID} - Name: {Name}";
        }
    }
}