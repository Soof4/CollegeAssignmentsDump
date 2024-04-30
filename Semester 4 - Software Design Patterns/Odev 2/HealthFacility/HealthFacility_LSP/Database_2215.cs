namespace HealthFacility_LSP
{
    public static class Database
    {
        private static List<Appointment> Appointments = new List<Appointment>();
        private static List<Device> Devices = new List<Device>();

        public static void InsertAppointment(Appointment appointment)
        {
            Appointments.Add(appointment);
        }

        public static void InsertDevice(Device device)
        {
            Devices.Add(device);
        }

        public static List<Appointment> GetAllAppointmentsOfProf(int professionalId)
        {
            List<Appointment> result = new List<Appointment>();

            foreach (Appointment apt in Appointments)
            {
                if (apt.Professional.ProfessionalID == professionalId)
                {
                    result.Add(apt);
                }
            }

            return result;
        }

        public static Device? GetDevice(int deviceId)
        {
            foreach (Device dvc in Devices)
            {
                if (dvc.DeviceId == deviceId)
                {
                    return dvc;
                }
            }
            return null;
        }

        public static bool DeleteAppointment(int appointmentId)
        {
            foreach (Appointment apt in Appointments)
            {
                if (apt.AppointmentID == appointmentId)
                {
                    Appointments.Remove(apt);
                    return true;
                }
            }
            return false;
        }

        public static Appointment? GetAppointment(int appointmentId)
        {
            foreach (Appointment apt in Appointments)
            {
                if (apt.AppointmentID == appointmentId)
                {
                    return apt;
                }
            }
            return null;
        }
    }
}