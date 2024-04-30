namespace HealthFacility_DIP
{
    public class Cream
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

        public Cream(int medicineID) {
            MedicineID = medicineID;
        }
    }
}