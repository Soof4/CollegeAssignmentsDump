namespace HealthFacility
{
    public class ModernClinic
    {
        public int ModernClinicID { get; set; }
        public List<IDoctor> Doctors { get; set; } = new List<IDoctor>();
        public int NumberOfNurses { get; set; }
        public int NumberOfLaboratories { get; set; }
        public int NumberOfPatientRooms { get; set; }
        public bool HasReceptionDesk { get; set; }

        public void ListDoctors()
        {
            Console.WriteLine("List of doctors:");
            Utils.PrintListAsTable(Doctors);
        }

        public void ShowInfo()
        {
            Console.WriteLine("Clinic Info:\n" +
                              $"Number of doctors: {Doctors.Count}\n" + 
                              $"Number of nurses: {NumberOfNurses}\n" +
                              $"Number of laboratories: {NumberOfLaboratories}\n" +
                              $"Number of patient rooms: {NumberOfPatientRooms}\n" +
                              $"Has a reception desk: {HasReceptionDesk}");
        }
    }
}