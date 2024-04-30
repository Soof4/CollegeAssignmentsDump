namespace HealthFacility_DIP
{
    public class MedicineSystem_DIP
    {
        private Dictionary<IMedicine_DIP, int> RegisteredMedicines = new Dictionary<IMedicine_DIP, int>();    // medicine: stock

        public void RegisterMedicine(IMedicine_DIP medicine, int stock)
        {
            if (RegisteredMedicines.Any(m => m.Key.MedicineID == medicine.MedicineID)) {
                Console.WriteLine("Couldn't register the medicine. This ID already exists.");
            }
            else if (RegisteredMedicines.TryAdd(medicine, stock))
            {
                Console.WriteLine($"Registered the medicine with ID {medicine.MedicineID}.");
            }
            else
            {
            Console.WriteLine($"Couldn't register the medicine.");
            }
        }
        public void UnregisterMedicine(IMedicine_DIP medicine)
        {
            RegisteredMedicines.Remove(medicine);
        }
        public void RestockMedicine(IMedicine_DIP medicine, int stock)
        {
            if (stock <= 0)
            {
                Console.WriteLine("Invalid stock amount.");
            }
            else
            {
                IMedicine_DIP? med = null;
                foreach (var kvp in RegisteredMedicines)
                {
                    if (kvp.Key.MedicineID == medicine.MedicineID)
                    {
                        med = kvp.Key;
                    }
                }

                if (med == null)
                {
                    Console.WriteLine("Couldn't find the medicine.");
                }
                else
                {
                    RegisteredMedicines[med] += stock;
                }
            }
        }

        public void TestAllMedicine()
        {
            foreach (var medicine in RegisteredMedicines)
            {
                medicine.Key.TestMedicine();
            }
        }
    }
}