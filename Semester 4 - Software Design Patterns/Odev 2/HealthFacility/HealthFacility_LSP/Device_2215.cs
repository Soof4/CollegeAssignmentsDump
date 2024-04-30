namespace HealthFacility_LSP
{
    public class Device
    {
        public int DeviceId { get; set; }
        public DeviceType DeviceType { get; set; }
        public bool IsUsable { get; set; }

        public Device(int deviceId, DeviceType deviceType, bool isUsable)
        {
            DeviceId = deviceId;
            DeviceType = deviceType;
            IsUsable = isUsable;
        }

        public bool IsAvailable()
        {
            Device? device = Database.GetDevice(DeviceId);
            return device != null && device.IsUsable;
        }
    }
}