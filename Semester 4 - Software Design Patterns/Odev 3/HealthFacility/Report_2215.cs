namespace HealthFacility
{
    public class Report : IReport
    {
        public int ReportID { get; set; }
        public IDoctor Doctor { get; set; }
        public Patient Patient { get; set; }

        public Report(IDoctor doctor, Patient patient)
        {
            Doctor = doctor;
            Patient = patient;
        }

        public void PrintToConsole()
        {
            Console.WriteLine($"This report was written by Dr. {Doctor.Name} {Doctor.Surname} for {Patient.Name} {Patient.Surname}.");
        }

        public void PrintAsFile()
        {
            FileStream fs = new FileStream($"Report_{ReportID}.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);
            sw.Write($"This report was written by Dr. {Doctor.Name} {Doctor.Surname} for {Patient.Name} {Patient.Surname}.\n\nReportID: {ReportID}");
            sw.Close();
        }
    }
}