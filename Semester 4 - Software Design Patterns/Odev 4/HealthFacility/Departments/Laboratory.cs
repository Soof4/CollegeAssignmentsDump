namespace HealthFacility
{
    public class Laboratory : AbstractDepartment
    {
        private int EquipmentCount { get; set; }

        public Laboratory(string name, int id, bool isOpen, int equipmentCount) : base(name, id, isOpen)
        {
            EquipmentCount = equipmentCount;
        }

        public override void ShowInfo()
        {
            List<string> result = new List<string>() {
                ToString(),
                $"Equipment count: {EquipmentCount}"
            };

            Utils.PrintAsBox(result);
        }
    }
}