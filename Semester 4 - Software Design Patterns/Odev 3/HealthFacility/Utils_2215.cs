using System.Reflection;
using System.Globalization;

namespace HealthFacility
{
    public static class Utils
    {
        public static string NormalizeName(string name)
        {
            CultureInfo culture = new CultureInfo("tr-TR", false);
            name = name.ToLower(culture);
            name = name.Substring(0, 1).ToUpper(culture) + name.Substring(1);
            return name;
        }

        public static void PrintListAsTable<T>(List<T> list)
        {
            if (list.Count == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }

            PropertyInfo[] properties = typeof(T).GetProperties();

            // Get the max length for each column
            int[] maxLengths = new int[properties.Length];

            for (int i = 0; i < properties.Length; i++)
            {
                maxLengths[i] = properties[i].Name.Length;
            }

            for (int i = 0; i < properties.Length; i++)
            {
                foreach (T item in list)
                {
                    int length = Convert.ToString(properties[i].GetValue(item))?.Length ?? 0;
                    if (length > maxLengths[i])
                    {
                        maxLengths[i] = length;
                    }
                }
            }

            // Print headers
            Console.WriteLine();

            for (int i = 0; i < properties.Length; i++)
            {
                Console.Write(properties[i].Name.PadRight(maxLengths[i] + 2));
            }

            // Print the header line
            Console.WriteLine();
            
            string headerLine = "";
            int sumLength = maxLengths.Sum() + maxLengths.Length * 2 - 2;
            for (int i = 0; i < sumLength; i++) headerLine += "-";
            
            Console.Write(headerLine);

            // Print elements
            Console.WriteLine();

            foreach (var obj in list)
            {
                for (int i = 0; i < properties.Length; i++)
                {
                    string value = Convert.ToString(properties[i].GetValue(obj)) ?? "";
                    Console.Write(value.PadRight(maxLengths[i] + 2));
                }
                Console.WriteLine();
            }
        }
    }
}