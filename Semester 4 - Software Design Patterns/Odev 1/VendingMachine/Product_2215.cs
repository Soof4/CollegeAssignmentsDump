namespace VendingMachine
{

    public enum ProductType
    {
        Snickers,
        CocaCola,
        Doritos,
        KitKat,
        Pepsi,
        PotatoChips,
        MnMs,
        Sprite,
        Twix,
        MountainDew,
        PeanutButterCups,
        Fanta,
        Pringles,
        ChocolateBar,
        DrPepper,
        Skittles
    }

    public class Product
    {
        public static int MAX_PRODUCT_STOCK = 32;
        public ProductType ProductType { get; set; }
        public double Price { get; set; }
        private int stock;
        public int Stock
        {
            get
            {
                return stock;
            }

            set
            {
                if (value > MAX_PRODUCT_STOCK || value < 0)
                {
                    throw new ArgumentOutOfRangeException(nameof(value), $"Value must be between 0 and {MAX_PRODUCT_STOCK}");
                }

                stock = value;
            }
        }
    }
}