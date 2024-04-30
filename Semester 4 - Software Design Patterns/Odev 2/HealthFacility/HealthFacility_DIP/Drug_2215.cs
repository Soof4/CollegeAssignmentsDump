namespace HealthFacility_DIP
{
    public class Drug
    {
        public int MedicineID { get; set; }

        public void ApplyMedicine()
        {
            Console.WriteLine("Taking drug.");
        }

        public void TestMedicine()
        {
            Console.WriteLine($"Drug (ID: {MedicineID}) is being tested.");
        }

        public Drug(int medicineID) {
            MedicineID = medicineID;
        }
    }
}