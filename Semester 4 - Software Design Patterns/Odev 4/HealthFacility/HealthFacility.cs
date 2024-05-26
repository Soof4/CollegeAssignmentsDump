namespace HealthFacility
{
    public class HealthFacility
    {
        private List<IDepartment> Departments { get; set; }
        private List<SurgeryRoom> SurgeryRooms { get; set; }
        private DatabaseManager DBManager { get; set; }
        private PaymentContext PaymentContext { get; set; }

        public HealthFacility()
        {
            Departments = new List<IDepartment>();
            SurgeryRooms = new List<SurgeryRoom>();
            DBManager = new DatabaseManager();
            PaymentContext = new PaymentContext();
        }
        public void Initialize()
        {
            Departments = DBManager.GetAllPolyclinics();

            foreach (var dep in Departments)
            {
                dep.Open();
            }

            Console.WriteLine("All departments are now open.");

            SurgeryRooms = DBManager.GetAllSurgeryRooms();

            foreach (var sr in SurgeryRooms)
            {
                sr.IsClean = true;
                DBManager.UpdateSurgeryRoom(sr.ID, sr.Name, sr.IsClean ? 1 : 0);
            }

            Console.WriteLine("All surgery rooms are now clean.");

            PaymentContext = new PaymentContext();
            
            Console.WriteLine("Payment system is now active.");
        }
    }
}