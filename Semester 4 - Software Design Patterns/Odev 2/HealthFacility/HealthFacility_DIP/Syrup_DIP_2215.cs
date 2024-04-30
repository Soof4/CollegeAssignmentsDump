namespace HealthFacility_DIP
{
    public class Syrup_DIP : IMedicine_DIP
    {
        public int MedicineID { get; set; }

        public void ApplyMedicine()
        {
            Console.WriteLine("Swallowing syrup.");
        }
        public void TestMedicine()
        {
            Console.WriteLine($"Syrup (ID: {MedicineID}) is being tested.");
        }

        public Syrup_DIP(int medicineID) {
            MedicineID = medicineID;
        }
    }
}