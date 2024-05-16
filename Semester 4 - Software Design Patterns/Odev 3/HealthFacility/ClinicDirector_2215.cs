using System.Data;
using System.Data.SQLite;

namespace HealthFacility
{
    public class ClinicDirector
    {
        private IClinicBuilder _builder;

        public ClinicDirector(IClinicBuilder builder)
        {
            _builder = builder;
        }

        public void BuildMinimalClinic(IDoctor doctor)
        {
            _builder.AddDoctor(doctor);
        }

        public void BuildStandardClinic(IDoctor doctor)
        {
            _builder.AddDoctor(doctor);
            _builder.AddNurse(1);
            _builder.AddReceptionDesk();
        }

        public void BuildAdvancedClinic(IDoctor doctor, int patientRoomCount, int nurseCount, int labCount)
        {
            _builder.AddDoctor(doctor);
            _builder.AddPatientRoom(patientRoomCount);
            _builder.AddNurse(nurseCount);
            _builder.AddReceptionDesk();
            _builder.AddLaboratory(labCount);
        }
    }
}