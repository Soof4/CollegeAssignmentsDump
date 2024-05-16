namespace HealthFacility
{
    public class PrescriptionPill : IPill
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }


        public PrescriptionPill(int id, string name, int stock, double price)
        {
            MedicineID = id;
            Name = name;
            Stock = stock;
            Price = price;
        }


        public void Swallow(Patient patient)
        {
            Console.WriteLine($"{patient.Name} {patient.Surname} is swallowing {Name}.");
        }

        public void SellTo(Patient patient)
        {
            Stock--;
            Console.WriteLine($"Sold 1 {Name} for {Price} TRY to {patient.Name} {patient.Surname}.");
        }
    }
}