namespace VendingMachine
{
    public class DataOnlyVendingMachine
    {
        public static readonly int MAX_PRODUCT_TYPES = 16;
        public static readonly int MAX_PRODUCT_STOCK = 32;
        public int[] productStocks = new int[MAX_PRODUCT_TYPES];
        public double[] productPrices = new double[MAX_PRODUCT_TYPES];
        public int penny1Amount = 100;
        public int penny5Amount = 100;
        public int penny10Amount = 100; 
        public int penny25Amount = 100;
        public int penny50Amount = 100;
        public int TRY1Amount = 100;
    }
}