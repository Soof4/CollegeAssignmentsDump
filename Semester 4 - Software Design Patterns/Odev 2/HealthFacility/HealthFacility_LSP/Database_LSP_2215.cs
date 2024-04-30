namespace HealthFacility_LSP
{
    public static class Database_LSP
    {
        private static List<DoctorAppointment_LSP> DocAppointments = new List<DoctorAppointment_LSP>();
        private static List<DiagnosticAppointment_LSP> DiagAppointments = new List<DiagnosticAppointment_LSP>();
        private static List<Device> Devices = new List<Device>();

        public static void InsertDoctorAppointment(DoctorAppointment_LSP appointment)
        {
            DocAppointments.Add(appointment);
        }
        public static void InsertDiagnosticAppointment(DiagnosticAppointment_LSP appointment)
        {
            DiagAppointments.Add(appointment);
        }

        public static void InsertDevice(Device device)
        {
            Devices.Add(device);
        }

        public static List<DoctorAppointment_LSP> GetAllDoctorAppointmentsOfProf(int professionalId)
        {
            List<DoctorAppointment_LSP> result = new List<DoctorAppointment_LSP>();

            foreach (DoctorAppointment_LSP apt in DocAppointments)
            {
                if (apt.Professional.ProfessionalID == professionalId)
                {
                    result.Add(apt);
                }
            }

            return result;
        }

        public static List<DiagnosticAppointment_LSP> GetAllDiagnosticAppointmentsOfProf(int professionalId)
        {
            List<DiagnosticAppointment_LSP> result = new List<DiagnosticAppointment_LSP>();

            foreach (DiagnosticAppointment_LSP apt in DiagAppointments)
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

        public static bool DeleteDoctorAppointment(int appointmentId)
        {
            foreach (DoctorAppointment_LSP apt in DocAppointments)
            {
                if (apt.AppointmentID == appointmentId)
                {
                    DocAppointments.Remove(apt);
                    return true;
                }
            }
            return false;
        }

        public static bool DeleteDiagnosticAppointment(int appointmentId)
        {
            foreach (DiagnosticAppointment_LSP apt in DiagAppointments)
            {
                if (apt.AppointmentID == appointmentId)
                {
                    DiagAppointments.Remove(apt);
                    return true;
                }
            }
            return false;
        }

        public static DoctorAppointment_LSP? GetDoctorAppointment(int appointmentId)
        {
            foreach (DoctorAppointment_LSP apt in DocAppointments)
            {
                if (apt.AppointmentID == appointmentId)
                {
                    return apt;
                }
            }
            return null;
        }
        public static DiagnosticAppointment_LSP? GetDiagnosticAppointment(int appointmentId)
        {
            foreach (DiagnosticAppointment_LSP apt in DiagAppointments)
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