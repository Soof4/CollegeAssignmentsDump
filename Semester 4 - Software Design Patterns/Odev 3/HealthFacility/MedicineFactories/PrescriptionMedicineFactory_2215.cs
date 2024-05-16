namespace HealthFacility
{
    public class PrescriptionMedicineFactory : IMedicineFactory
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

            return new PrescriptionCream(id, name, stock, price);
        }

        public ICream? CreateCream(int id)
        {
            return Program.dbManager.GetPrescriptionCream(id);
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

            return new PrescriptionPill(id, name, stock, price);
        }

        public IPill? CreatePill(int id)
        {
            return Program.dbManager.GetPrescriptionPill(id);
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

            return new PrescriptionSyrup(id, name, stock, price);
        }

        public ISyrup? CreateSyrup(int id)
        {
            return Program.dbManager.GetPrescriptionSyrup(id);
        }
    }
}