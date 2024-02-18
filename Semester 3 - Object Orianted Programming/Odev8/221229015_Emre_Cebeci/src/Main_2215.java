import java.util.ArrayList;
import java.util.Scanner;

public class Main_2215 {
    public static ArrayList<Product_2215.Beverages_2215> beverageList = new ArrayList<Product_2215.Beverages_2215>();
    public static ArrayList<Product_2215.Condiments_2215> condimentList = new ArrayList<Product_2215.Condiments_2215>();
    public static ArrayList<Product_2215.Confections_2215> confectionList = new ArrayList<Product_2215.Confections_2215>();
    public static ArrayList<Product_2215.DairyProducts_2215> dairyList = new ArrayList<Product_2215.DairyProducts_2215>();
    public static ArrayList<Product_2215.Cereals_2215> cerealList = new ArrayList<Product_2215.Cereals_2215>();
    
    public static ArrayList<ArrayList<Product_2215>> allProductsList = new ArrayList<ArrayList<Product_2215>>();
    
    public static void main(String[] args) {
       String str = "sdfsdfsdf";
       str.length();
       
       

    }

    public static void menu() {
        while (true) {
            Scanner scanner = new Scanner(System.in);
            
            System.out.println("\nMENU:\n"
                    + "1: UrunStokGuncelle\n"
                    + "2: UrunKategorikIndirimYap\n"
                    + "3. IcecekUrunuSil\n"
                    + "4. CesniUrunEkle\n"
                    + "5. SekerlemeDetayEkle\n"
                    + "6. SutUrunuStokGuncelle\n"
                    + "7. TahilBirimAgirlikGuncelle\n"
                    + "8. DosyayaYaz\n"
                    + "8. Cikis");
            
            
            
            
            
            
            scanner.close();
        }
    }
}
