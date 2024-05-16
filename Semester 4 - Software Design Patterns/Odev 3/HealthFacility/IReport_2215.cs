namespace HealthFacility
{
    public interface IReport
    {
        public int ReportID { get; set; }
        IDoctor Doctor { get; set; }
        Patient Patient { get; set; }
        public void PrintToConsole();
        public void PrintAsFile();
    }
}