namespace HealthFacility_DIP
{
    public class Cream_DIP : IMedicine_DIP
    {
        public int MedicineID { get; set; }

        public void ApplyMedicine()
        {
            Console.WriteLine("Applying cream.");
        }

        public void TestMedicine()
        {
            Console.WriteLine($"Cream (ID: {MedicineID}) is being tested.");
        }

        public Cream_DIP(int medicineID) {
            MedicineID = medicineID;
        }
    }
}