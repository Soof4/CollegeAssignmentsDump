namespace HealthFacility_DIP
{
    public class Syrup
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

        public Syrup(int medicineID) {
            MedicineID = medicineID;
        }
    }
}