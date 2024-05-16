namespace HealthFacility
{
    public interface IMedicineFactory
    {
        public ICream? CreateCream(int id);
        public IPill? CreatePill(int id);
        public ISyrup? CreateSyrup(int id);
        public ICream? CreateCream(int id, string name, int stock, double price);
        public IPill? CreatePill(int id, string name, int stock, double price);
        public ISyrup? CreateSyrup(int id, string name, int stock, double price);
    }
}