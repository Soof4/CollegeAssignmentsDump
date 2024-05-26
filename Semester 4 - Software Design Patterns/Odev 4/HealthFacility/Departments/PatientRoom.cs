namespace HealthFacility
{
    public class PatientRoom : AbstractDepartment
    {
        private int BedCount { get; set; }

        public PatientRoom(string name, int id, bool isOpen, int bedCount) : base(name, id, isOpen)
        {
            BedCount = bedCount;
        }

        public override void ShowInfo()
        {
            List<string> result = new List<string>() {
                ToString(),
                $"Bed count: {BedCount}"
            };

            Utils.PrintAsBox(result);
        }
    }
}