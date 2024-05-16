namespace HealthFacility
{
    public class OverTheCounterSyrup : ISyrup
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }
        public double Tax { get; set; }


        public OverTheCounterSyrup(int id, string name, int stock, double price, double tax = 0.20)
        {
            MedicineID = id;
            Name = name;
            Stock = stock;
            Price = price;
            Tax = tax;
        }


        public void Ingest(Patient patient)
        {
            Console.WriteLine($"{patient.Name} {patient.Surname} is ingesting {Name}.");
        }

        public void SellTo(Patient patient)
        {
            Stock--;
            Console.WriteLine($"Sold 1 {Name} for {Price * (1 + Tax)} TRY to {patient.Name} {patient.Surname}.");
        }
    }
}