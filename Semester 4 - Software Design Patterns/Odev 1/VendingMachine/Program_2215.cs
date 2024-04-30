namespace VendingMachine
{
    public class Program
    {
        public static void Main(string[] args)
        {
            // RunDataOnlyVendingMachine();
            // RunGetterSetterVendingMachine();
            // RunPrimitiveVendingMachine();
            RunEncapsulatedVendingMachine();
        }

        public static void RunDataOnlyVendingMachine()
        {
            DataOnlyVendingMachine machine = new DataOnlyVendingMachine();

            machine.productStocks[5]--;
            machine.penny50Amount += 10;
            machine.TRY1Amount++;
            machine.penny5Amount--;
            machine.productStocks[10] = -2000;
            machine.productPrices[0] = -700;
        }

        public static void RunGetterSetterVendingMachine()
        {
            GetterSetterVendingMachine machine = new GetterSetterVendingMachine();

            machine.ProductStocks[5]--;
            machine.Penny50Amount += 10;
            machine.TRY1Amount++;
            machine.Penny5Amount--;
            machine.ProductStocks[10] = -2000;
            machine.ProductPrices[0] = -700;
        }

        public static void RunPrimitiveVendingMachine() {
            PrimitiveVendingMachine machine = new PrimitiveVendingMachine();
            machine.Buy(0, 5, 7, 10, 1);
            machine.Buy(-50);
            machine.Buy(1);
            machine.Buy(4, 30, 30, 30, 30);
            machine.InsertCoins(5, 4, 70, -5);
            machine.Restock(-5, 10);
            machine.Restock(10, 100);
            machine.Restock(10, -5);
        }

        public static void RunEncapsulatedVendingMachine() {
            EncapsulatedVendingMachine machine = new EncapsulatedVendingMachine();

            machine.InsertCoins(try1Amount: 1000);
            machine.Buy(ProductType.ChocolateBar, penny50Amount: 5, try1Amount: 10, penny5Amount: 40);
            machine.Restock(ProductType.Doritos, -30);
            machine.Buy(ProductType.Doritos, 10, 10, 10, 10, 50);
            machine.Restock(ProductType.Doritos, 5);
        }
    }
}