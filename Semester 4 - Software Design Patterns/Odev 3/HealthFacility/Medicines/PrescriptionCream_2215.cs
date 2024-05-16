namespace HealthFacility
{
    public class PrescriptionCream : ICream
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }


        public PrescriptionCream(int id, string name, int stock, double price)
        {
            MedicineID = id;
            Name = name;
            Stock = stock;
            Price = price;
        }


        public void Apply(Patient patient)
        {
            Console.WriteLine($"Applying {Name} to {patient.Name} {patient.Surname}.");
        }

        public void SellTo(Patient patient)
        {
            Stock--;
            Console.WriteLine($"Sold 1 {Name} for {Price} TRY to {patient.Name} {patient.Surname}.");
        }
    }
}