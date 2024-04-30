namespace HealthFacility_DIP
{
    public interface IMedicine_DIP
    {
        public int MedicineID { get; set; }
        public void ApplyMedicine();
        public void TestMedicine();
        
        public bool Equals(object? obj)
        {
            IMedicine_DIP? obj_;
            try
            {
                obj_ = (IMedicine_DIP?)obj;
            }
            catch
            {
                return false;
            }

            return obj_ != null && obj_.MedicineID == MedicineID;
        }
    }
}