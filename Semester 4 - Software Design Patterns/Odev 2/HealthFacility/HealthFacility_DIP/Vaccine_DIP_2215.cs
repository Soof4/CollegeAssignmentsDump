namespace HealthFacility_DIP
{
    public class Vaccine_DIP : IMedicine_DIP
    {
        public int MedicineID { get; set; }

        public void ApplyMedicine()
        {
            Console.WriteLine("Vaccinating.");
        }

        public void TestMedicine()
        {
            Console.WriteLine($"Vaccine (ID: {MedicineID}) is being tested.");
        }

        public Vaccine_DIP(int medicineID) {
            MedicineID = medicineID;
        }
    }
}