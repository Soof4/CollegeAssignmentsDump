package package2;

import java.util.ArrayList;
import java.util.Scanner;

import package1.DataReader_2215;

public class Main_2215 extends DataReader_2215 {
    public static ArrayList<Beverages_2215> beverageList = new ArrayList<Beverages_2215>();
    public static ArrayList<Condiments_2215> condimentList = new ArrayList<Condiments_2215>();
    public static ArrayList<Confections_2215> confectionList = new ArrayList<Confections_2215>();
    public static ArrayList<DairyProducts_2215> dairyProductList = new ArrayList<DairyProducts_2215>();
    public static ArrayList<Cereals_2215> cerealList = new ArrayList<Cereals_2215>();
    
    public static void main(String[] args) {
        menu();
    }
    
    private static void menu() {
        Scanner scanner = new Scanner(System.in);
        int choice;
        
        DataReader_2215.ListeleriOlustur("Urunler.txt");
        Product_2215.printCategories();
        System.out.println();
        Product_2215.printAllProducts();
        
        while(true) {
            System.out.println("\nMENU:\n"
                    + "1: UrunleriFiyataGoreSil\n"
                    + "2: UrunKategorikStokGuncelle\n"
                    + "3. IcecekBirimAgirlikGuncelle \n"
                    + "4. CesniStokGuncelle\n"
                    + "5. SekerlemeUrunEkle\n"
                    + "6. SutUrunleriDetayEkle\n"
                    + "7. HububatSil\n"
                    + "8. Çıkış");
            
            choice = scanner.nextInt();
            scanner.nextLine();
            
            switch (choice) {
                case 1:
                    System.out.println("Lütfen minFiyatı giriniz.");
                    double minPrice = scanner.nextDouble();
                    System.out.println("Lütfen maxFiyatı giriniz.");
                    double maxPrice = scanner.nextDouble();
                    
                    Product_2215.UrunleriFiyataGoreSil(minPrice, maxPrice);
                    Product_2215.printAllProducts();
                    break;
                case 2:
                    System.out.println("Lütfen kategori ismini giriniz.");
                    String categoryName = scanner.nextLine();
                    System.out.println("Lütfen x değerini giriniz.");
                    int x = scanner.nextInt();
                    
                    Product_2215.UrunKategoriStokGuncelle(categoryName, x);
                    Product_2215.printAllProducts();
                    break;
                case 3:
                    System.out.println("Lütfen yeni birim ağırlığı giriniz.");
                    String newUnitWeight = scanner.nextLine();
                    
                    Beverages_2215.IcecekBirimAgirlikGuncelle(newUnitWeight);
                    Product_2215.printAllProducts();
                    break;
                case 4:
                    System.out.println("Satılacak mı? (y/n)");
                    boolean isSell = scanner.nextLine().toLowerCase().trim().equals("y");
                    System.out.println("Lütfen miktar giriniz.");
                    int amount = scanner.nextInt();
                    scanner.nextLine();
                    
                    Condiments_2215.CesniStokGuncelle(isSell, amount);
                    Product_2215.printAllProducts();
                    break;
                case 5:
                    System.out.println("Lütfen isim giriniz.");
                    String name = scanner.nextLine();
                    System.out.println("Lütfen birim ağırlık giriniz.");
                    String weight = scanner.nextLine();
                    System.out.println("Lütfen fiyat giriniz.");
                    double price = scanner.nextDouble();
                    System.out.println("Lütfen stok miktarı giriniz.");
                    int stock = scanner.nextInt();
                    scanner.nextLine();
                    
                    Confections_2215.SekerlemeUrunEkle(name, weight, price, stock);
                    Product_2215.printAllProducts();
                    break;
                case 6:
                    System.out.println("Lütfen yeni detay giriniz.");
                    String newDetail = scanner.nextLine();
                    
                    DairyProducts_2215.SutUrunleriDetayEkle(newDetail);
                    Product_2215.printCategories();
                    break;
                case 7:
                    System.out.println("Lütfen isim giriniz.");
                    String delName = scanner.nextLine();
                    
                    Cereals_2215.HububatSil(delName);
                    Product_2215.printAllProducts();
                    break;
                case 8:
                    return;
                default:
                    System.out.println("Lütfen menüde olan bir seçeneği seçiniz.");
                    break;
            }
        }
    }
}
