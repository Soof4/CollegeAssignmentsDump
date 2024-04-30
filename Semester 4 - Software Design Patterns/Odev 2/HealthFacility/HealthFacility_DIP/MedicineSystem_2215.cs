namespace HealthFacility_DIP
{
    public class MedicineSystem
    {
        private Dictionary<Cream, int> RegisteredCreams = new Dictionary<Cream, int>();
        private Dictionary<Drug, int> RegisteredDrugs = new Dictionary<Drug, int>();
        private Dictionary<Syrup, int> RegisteredSyrups = new Dictionary<Syrup, int>();
        private Dictionary<Vaccine, int> RegisteredVaccines = new Dictionary<Vaccine, int>();

        public void RegisterCream(Cream cream, int stock)
        {
            if (RegisteredCreams.TryAdd(cream, stock))
            {
                Console.WriteLine($"Registered the medicine with ID {cream.MedicineID}.");
            }
            else
            {
                Console.WriteLine($"Couldn't register the medicine.");
            };
        }
        public void RegisterDrug(Drug drug, int stock)
        {
            if (RegisteredDrugs.TryAdd(drug, stock))
            {
                Console.WriteLine($"Registered the medicine with ID {drug.MedicineID}.");
            }
            else
            {
                Console.WriteLine($"Couldn't register the medicine.");
            }
        }
        public void RegisterSyrup(Syrup syrup, int stock)
        {
            if (RegisteredSyrups.TryAdd(syrup, stock))
            {
                Console.WriteLine($"Registered the medicine with ID {syrup.MedicineID}.");
            }
            else
            {
                Console.WriteLine($"Couldn't register the medicine.");
            }
        }
        public void RegisterVaccine(Vaccine vaccine, int stock)
        {
            if (RegisteredVaccines.TryAdd(vaccine, stock))
            {
                Console.WriteLine($"Registered the medicine with ID {vaccine.MedicineID}.");
            }
            else
            {
                Console.WriteLine($"Couldn't register the medicine.");
            }
        }


        public void UnregisterCream(Cream cream)
        {
            RegisteredCreams.Remove(cream);
        }
        public void UnregisterDrug(Drug drug)
        {
            RegisteredDrugs.Remove(drug);
        }
        public void UnregisterSyrup(Syrup syrup)
        {
            RegisteredSyrups.Remove(syrup);
        }
        public void UnregisterVaccine(Vaccine vaccine, int stock)
        {
            RegisteredVaccines.Remove(vaccine);
        }

        public void RestockCream(Cream medicine, int stock)
        {
            if (stock <= 0)
            {
                Console.WriteLine("Invalid stock amount.");
            }
            else
            {
                Cream? med = null;
                foreach (var kvp in RegisteredCreams)
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
                    RegisteredCreams[med] += stock;
                }
            }
        }
        public void RestockDrug(Drug medicine, int stock)
        {
            if (stock <= 0)
            {
                Console.WriteLine("Invalid stock amount.");
            }
            else
            {
                Drug? med = null;
                foreach (var kvp in RegisteredDrugs)
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
                    RegisteredDrugs[med] += stock;
                }
            }
        }
        public void RestockSyrup(Syrup medicine, int stock)
        {
            if (stock <= 0)
            {
                Console.WriteLine("Invalid stock amount.");
            }
            else
            {
                Syrup? med = null;
                foreach (var kvp in RegisteredSyrups)
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
                    RegisteredSyrups[med] += stock;
                }
            }
        }
        public void RestockVaccine(Vaccine medicine, int stock)
        {
            if (stock <= 0)
            {
                Console.WriteLine("Invalid stock amount.");
            }
            else
            {
                Vaccine? med = null;
                foreach (var kvp in RegisteredVaccines)
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
                    RegisteredVaccines[med] += stock;
                }
            }
        }

        public void TestAllMedicine()
        {
            foreach (var med in RegisteredCreams)
            {
                med.Key.TestMedicine();
            }
            foreach (var med in RegisteredDrugs)
            {
                med.Key.TestMedicine();
            }
            foreach (var med in RegisteredSyrups)
            {
                med.Key.TestMedicine();
            }
            foreach (var med in RegisteredVaccines)
            {
                med.Key.TestMedicine();
            }
        }
    }
}