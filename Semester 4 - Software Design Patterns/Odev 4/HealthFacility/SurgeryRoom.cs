namespace HealthFacility
{
    public class SurgeryRoom
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public bool IsClean { get; set; }
        public SurgeryRoom(int id, string name, bool isClean)
        {
            ID = id;
            Name = name;
            IsClean = isClean;
        }

        public void ShowInfo()
        {
            List<string> result = new List<string>() {
                ToString()
            };

            Utils.PrintAsBox(result);
        }

        public override string ToString()
        {
            return $"ID: {ID} - Name: {Name}";
        }
    }
}