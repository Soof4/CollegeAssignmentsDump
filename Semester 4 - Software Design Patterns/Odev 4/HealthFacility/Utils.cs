using System.Globalization;
using System.Reflection.Metadata;

namespace HealthFacility
{
    public static class Utils
    {
        public static void PrintAsBox(IEnumerable<string?> list)
        {
            int maxLength = 0;
            foreach (string? str in list)
            {
                if (str != null && str.Length > maxLength)
                {
                    maxLength = str.Length;
                }
            }

            // Print the first line
            maxLength += 2;
            string text = "+";

            for (int i = 0; i < maxLength; i++)
            {
                text += "-";
            }

            text += "+";
            Console.WriteLine(text);

            // Print the elements
            maxLength--;

            foreach (string? str in list)
            {
                if (str == null) continue;

                string elementText = "| ";
                elementText += str;

                for (int i = str.Length; i < maxLength; i++)
                {
                    elementText += " ";
                }

                elementText += "|";
                Console.WriteLine(elementText);
            }

            Console.WriteLine(text);
        }

        public static string NormalizeName(string name)
        {
            CultureInfo culture = new CultureInfo("tr-TR", false);

            string[] names = name.Split(" ");
            for (int i = 0; i < names.Length; i++)
            {
                names[i] = names[i].ToLower(culture);
                names[i] = names[i][..1].ToUpper(culture) + names[i][1..];
            }

            name = string.Join(" ", names);
            return name;
        }
    }
}