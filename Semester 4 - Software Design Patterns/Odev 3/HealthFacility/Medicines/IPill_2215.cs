namespace HealthFacility
{
    public interface IPill
    {
        public int MedicineID { get; set; }
        public string Name { get; set; }
        public int Stock { get; set; }
        public double Price { get; set; }


        public void SellTo(Patient patient);
        public void Swallow(Patient patient);
    }
}