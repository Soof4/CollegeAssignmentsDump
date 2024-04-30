namespace VendingMachine
{
    public class GetterSetterVendingMachine
    {
        public static readonly int MAX_PRODUCT_TYPES = 16;
        public static readonly int MAX_PRODUCT_STOCK = 32;
        public int[] ProductStocks { get; set; } = new int[MAX_PRODUCT_TYPES];
        public double[] ProductPrices { get; set; } = new double[MAX_PRODUCT_TYPES];
        public int Penny1Amount { get; set; } = 100;
        public int Penny5Amount { get; set; } = 100;
        public int Penny10Amount { get; set; } = 100;
        public int Penny25Amount { get; set; } = 100;
        public int Penny50Amount { get; set; } = 100;
        public int TRY1Amount { get; set; } = 100;
    }
}