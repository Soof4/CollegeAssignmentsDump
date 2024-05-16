namespace HealthFacility
{
    public class OverTheCounterMedicineFactory : IMedicineFactory
    {
        public ICream? CreateCream(int id, string name, int stock, double price)
        {
            if (stock < 0)
            {
                Console.WriteLine("Invalid stock amount.");
                return null;
            }

            if (price < 0)
            {
                Console.WriteLine("Invalid price value.");
                return null;
            }

            return new OverTheCounterCream(id, name, stock, price);
        }

        public ICream? CreateCream(int id)
        {
            return Program.dbManager.GetOverTheCounterCream(id);
        }

        public IPill? CreatePill(int id, string name, int stock, double price)
        {
            if (stock < 0)
            {
                Console.WriteLine("Invalid stock amount.");
                return null;
            }

            if (price < 0)
            {
                Console.WriteLine("Invalid price value.");
                return null;
            }

            return new OverTheCounterPill(id, name, stock, price);
        }

        public IPill? CreatePill(int id)
        {
            return Program.dbManager.GetOverTheCounterPill(id);
        }

        public ISyrup? CreateSyrup(int id, string name, int stock, double price)
        {
            if (stock < 0)
            {
                Console.WriteLine("Invalid stock amount.");
                return null;
            }

            if (price < 0)
            {
                Console.WriteLine("Invalid price value.");
                return null;
            }

            return new OverTheCounterSyrup(id, name, stock, price);
        }

        public ISyrup? CreateSyrup(int id)
        {
            return Program.dbManager.GetOverTheCounterSyrup(id);
        }
    }
}