namespace HealthFacility_DIP
{
    public class Vaccine
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

        public Vaccine(int medicineID) {
            MedicineID = medicineID;
        }
    }
}