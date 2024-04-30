namespace VendingMachine
{
    public class EncapsulatedVendingMachine
    {
        private Product[] Products = new Product[Enum.GetValues(typeof(ProductType)).Length];
        private int Penny1Amount { get; set; } = 100;
        private int Penny5Amount { get; set; } = 100;
        private int Penny10Amount { get; set; } = 100;
        private int Penny25Amount { get; set; } = 100;
        private int Penny50Amount { get; set; } = 100;
        private int TRY1Amount { get; set; } = 100;

        public EncapsulatedVendingMachine()
        {
            Array.Fill(Products, new Product());

            for (int i = 0; i < Products.Length; i++)
            {
                Products[i].ProductType = (ProductType)i;
                Products[i].Price = Math.Round(i + 0.25, 2);    // Rounding because of binary to decimal conversion may return slightly wrong values
                Products[i].Stock = 32;
            }
        }

        public void Buy(ProductType productType, int penny1Amount = 0, int penny5Amount = 0,
                        int penny10Amount = 0, int penny25Amount = 0, int penny50Amount = 0,
                        int try1Amount = 0)
        {
            Product product = ChooseProduct(productType);

            double totalPennies = Math.Round(penny1Amount * 0.01 +
                                             penny5Amount * 0.05 +
                                             penny10Amount * 0.10 +
                                             penny25Amount * 0.25 +
                                             penny50Amount * 0.5 +
                                             try1Amount, 2);

            if (totalPennies < product.Price)
            {
                Console.WriteLine("Not enough coins were inserted!");
                return;
            }

            if (product.Stock <= 0)
            {
                Console.WriteLine("Out of stock!");
                return;
            }

            InsertCoins(penny1Amount, penny5Amount, penny10Amount, penny25Amount, penny50Amount, try1Amount);

            if (totalPennies > product.Price)    // If machine needs to dispense exchange coins
            {
                double exchangeAmount = Math.Round(totalPennies - product.Price, 2);

                if (!IsExchangePossible(exchangeAmount))
                {
                    Console.WriteLine("Machine doesnt have enough coins for the exchange, cancelling the payment.");
                    Dispense(penny1Amount, penny5Amount, penny10Amount, penny25Amount, penny50Amount, try1Amount);
                    return;
                }

                int[] coins = GetExchangeCoins(exchangeAmount);
                Dispense(coins[5], coins[4], coins[3], coins[2], coins[1], coins[0]);
            }

            DropItem(product);
            Console.WriteLine("Successfully bought the item!");
        }

        public Product ChooseProduct(ProductType type)
        {
            Product tProduct = Products[0];

            foreach (Product p in Products)
            {
                if (p.ProductType == type)
                {
                    tProduct = p;
                    break;
                }
            }

            return tProduct;
        }
        public void DropItem(Product product)
        {
            product.Stock--;
            Console.WriteLine("Dropped the product!");
        }

        public void InsertCoins(int penny1Amount = 0, int penny5Amount = 0, int penny10Amount = 0,
                                int penny25Amount = 0, int penny50Amount = 0, int try1Amount = 0)
        {
            if (penny1Amount < 0 || penny5Amount < 0 || penny10Amount < 0 || penny25Amount < 0 || penny50Amount < 0 || try1Amount < 0)
            {
                Console.WriteLine("Invalid coin amount!");
                return;
            }

            Penny1Amount += penny1Amount;
            Penny5Amount += penny5Amount;
            Penny10Amount += penny10Amount;
            Penny25Amount += penny25Amount;
            Penny50Amount += penny50Amount;
            TRY1Amount += try1Amount;

            Console.WriteLine("Inserted coins.");
        }

        /// <summary>
        /// Checks whatever if the exchange is possible with the coins inside the machine.
        /// </summary>
        /// <param name="exchangeAmount"></param>
        /// <returns></returns>
        private bool IsExchangePossible(double exchangeAmount)
        {
            int futureTRY1Exchange = 0;
            int futurePenny50Exchange = 0;
            int futurePenny25Exchange = 0;
            int futurePenny10Exchange = 0;
            int futurePenny5Exchange = 0;
            int futurePenny1Exchange = 0;

            while (exchangeAmount >= 1 && TRY1Amount - futureTRY1Exchange > 0)
            {
                futureTRY1Exchange++;
                exchangeAmount = Math.Round(exchangeAmount - 1, 2);
            }
            while (exchangeAmount >= 0.5 && Penny50Amount - futurePenny50Exchange > 0)
            {
                futurePenny50Exchange++;
                exchangeAmount = Math.Round(exchangeAmount - 0.5, 2);
            }
            while (exchangeAmount >= 0.25 && Penny25Amount - futurePenny25Exchange > 0)
            {
                futurePenny25Exchange++;
                exchangeAmount = Math.Round(exchangeAmount - 0.25, 2);
            }
            while (exchangeAmount >= 0.1 && Penny10Amount - futurePenny10Exchange > 0)
            {
                futurePenny10Exchange++;
                exchangeAmount = Math.Round(exchangeAmount - 0.1, 2);
            }
            while (exchangeAmount >= 0.05 && Penny5Amount - futurePenny5Exchange > 0)
            {
                futurePenny5Exchange++;
                exchangeAmount = Math.Round(exchangeAmount - 0.05, 2);
            }
            while (exchangeAmount >= 0.01 && Penny1Amount - futurePenny1Exchange > 0)
            {
                futurePenny1Exchange++;
                exchangeAmount = Math.Round(exchangeAmount - 0.01, 2);
            }

            return exchangeAmount == 0;
        }

        /// <summary>
        /// Returns an array of coin amounts. Coin types go from greater to lesser, index 0 representing TRY1 while index 5 representing 1 penny.<br></br>
        /// (This method assumes that exchange is possible.)
        /// </summary>
        /// <param name="exchangeAmount"></param>
        /// <returns></returns>
        private int[] GetExchangeCoins(double exchangeAmount)
        {
            int[] coins = new int[6];

            while (exchangeAmount >= 1 && TRY1Amount - coins[0] > 0)
            {
                coins[0]++;
                exchangeAmount = Math.Round(exchangeAmount - 1, 2);
            }
            while (exchangeAmount >= 0.5 && Penny50Amount - coins[1] > 0)
            {
                coins[1]++;
                exchangeAmount = Math.Round(exchangeAmount - 0.5, 2);
            }
            while (exchangeAmount >= 0.25 && Penny25Amount - coins[2] > 0)
            {
                coins[2]++;
                exchangeAmount = Math.Round(exchangeAmount - 0.25, 2);
            }
            while (exchangeAmount >= 0.1 && Penny10Amount - coins[3] > 0)
            {
                coins[3]++;
                exchangeAmount = Math.Round(exchangeAmount - 0.1, 2);
            }
            while (exchangeAmount >= 0.05 && Penny5Amount - coins[4] > 0)
            {
                coins[4]++;
                exchangeAmount = Math.Round(exchangeAmount - 0.05, 2);
            }
            while (exchangeAmount >= 0.01 && Penny1Amount - coins[5] > 0)
            {
                coins[5]++;
                exchangeAmount = Math.Round(exchangeAmount - 0.01, 2);
            }

            return coins;
        }
        private void Dispense(int penny1Amount = 0, int penny5Amount = 0, int penny10Amount = 0,
                              int penny25Amount = 0, int penny50Amount = 0, int try1Amount = 0)
        {
            Penny1Amount -= penny1Amount;
            Penny5Amount -= penny5Amount;
            Penny10Amount -= penny10Amount;
            Penny25Amount -= penny25Amount;
            Penny50Amount -= penny50Amount;
            TRY1Amount -= try1Amount;

            string msg = "Dispensed ";

            if (try1Amount != 0)
            {
                msg += $"{try1Amount} TRY 1, ";
            }
            if (penny50Amount != 0)
            {
                msg += $"{penny50Amount} 50 pennies, ";
            }
            if (penny25Amount != 0)
            {
                msg += $"{penny25Amount} 25 pennies, ";
            }
            if (penny10Amount != 0)
            {
                msg += $"{penny10Amount} 10 pennies, ";
            }
            if (penny5Amount != 0)
            {
                msg += $"{penny5Amount} 5 pennies, ";
            }
            if (penny1Amount != 0)
            {
                msg += $"{penny1Amount} 1 pennies, ";
            }

            Console.WriteLine(msg);
        }

        /// <summary>
        /// Increase or decrease the stock of a product. (Degression is only allowed for 0 < amount <= current stock of the item)
        /// </summary>
        /// <param name="productIndex"></param>
        /// <param name="amount"></param>
        public void Restock(ProductType productType, int amount)
        {
            Product product = ChooseProduct(productType);

            if (amount < 0 && -amount >= product.Stock)
            {
                Console.WriteLine("Invalid restock amount.");
                return;
            }

            if (product.Stock + amount > Product.MAX_PRODUCT_STOCK)
            {
                Console.WriteLine("Cancelled the restocking, amount is too big.");
                return;
            }

            product.Stock += amount;

            Console.WriteLine("Succesfully restocked the item.");
        }

    }
}