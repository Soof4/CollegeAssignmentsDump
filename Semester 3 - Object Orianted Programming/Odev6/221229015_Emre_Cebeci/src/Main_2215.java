import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Main_2215 {
    public static ArrayList<Beverages_2215> beverageList = new ArrayList<Beverages_2215>();
    public static ArrayList<Condiments_2215> condimentList = new ArrayList<Condiments_2215>();
    public static ArrayList<Confections_2215> confectionList = new ArrayList<Confections_2215>();
    public static ArrayList<DairyProducts_2215> dairyList = new ArrayList<DairyProducts_2215>();
    public static ArrayList<Cereals_2215> cerealList = new ArrayList<Cereals_2215>();
    
    public static void main(String[] args) {
        createLists("Urunler.txt");
        
        menu();
    }

    public static void menu() {
        while (true) {
            printLists();
            
            Scanner scanner = new Scanner(System.in);
            int choice;
            
            System.out.println("\nMENU:\n"
                    + "1: UrunFiyatGuncelle\n"
                    + "2: UrunKategorikZamYap\n"
                    + "3. UrunFiyatGuncelle (Beverages)\n"
                    + "4. CesniBirimAgirlikGuncelle\n"
                    + "5. UrunStokGuncelle (Confections)\n"
                    + "6. SutUrunuSil\n"
                    + "7. TahilUrunEkle\n"
                    + "8. Cikis");
            
            choice = scanner.nextInt();
            
            switch (choice) {
                case 1: {
                    scanner.nextLine();
                    System.out.println("Fiyati guncellenecek olan urunun ismini giriniz:");
                    String name = scanner.nextLine();
                    Product_2215 p = Product_2215.findProductByName(name);
                    
                    if (p == null) {
                        System.out.println("Urun bulunamadi.");
                    }
                    else {
                        System.out.println("Oran giriniz:");
                        int ratio = scanner.nextInt();
                        scanner.nextLine();
                        
                        System.out.println("Stok giriniz (Eger stoksuz islem yapmak istiyorsaniz sayi harici herhangi bir karakter giriniz):");
                        String stockStr = scanner.nextLine();
                        
                        try {
                            int stock = Integer.parseInt(stockStr);
                            p.updatePrice(ratio, stock);
                        }
                        catch (NumberFormatException e) {
                            p.updatePrice(ratio);
                        }
                    }
                    break;
                }
                case 2: {
                    scanner.nextLine();
                    System.out.println("Kategori ismi giriniz:");
                    String catName = scanner.nextLine();
                    Product_2215.raisePricesbyCategory(catName);
                    break;
                }
                
                case 3: {
                    scanner.nextLine();
                    System.out.println("Fiyati guncellenecek olan icecegin ismini giriniz:");
                    String name = scanner.nextLine();
                    
                    Beverages_2215 b = (Beverages_2215)Beverages_2215.findProductByName(name);
                    if (b == null) {
                        System.out.println("Icecek bulunamadi.");
                    }
                    else {
                        System.out.println("Oran giriniz:");
                        int ratio = scanner.nextInt();
                        scanner.nextLine();
                        
                        System.out.println("Stok giriniz (Eger stoksuz islem yapmak istiyorsaniz sayi harici herhangi bir karakter giriniz):");
                        String stockStr = scanner.nextLine();
                        
                        try {
                            int stock = Integer.parseInt(stockStr);
                            b.updatePrice(ratio, stock);
                        }
                        catch (NumberFormatException e) {
                            b.updatePrice(ratio);
                        }
                    }
                    break;
                }
                
                case 4: {
                    scanner.nextLine();
                    System.out.println("Yeni birim agirlik giriniz:");
                    String weight = scanner.nextLine();
                    System.out.println("Stok giriniz (Eger stoksuz islem yapmak istiyorsaniz sayi harici herhangi bir karakter giriniz):");
                    String stockStr = scanner.nextLine();
                    
                    try {
                        int stock = Integer.parseInt(stockStr);
                        Condiments_2215.updateUnitWeight(weight, stock);
                    }
                    catch (NumberFormatException e) {
                        Condiments_2215.updateUnitWeight(weight);
                    }
                    break;
                }
                
                case 5: {
                    scanner.nextLine();
                    System.out.println("Fiyati guncellenecek olan urunun ismini giriniz:");
                    String name = scanner.nextLine();
                    Confections_2215 p = (Confections_2215)Confections_2215.findProductByName(name);
                    
                    System.out.println("Stok giriniz:");
                    int stock = scanner.nextInt();
                    System.out.println("Boolean giriniz:");
                    boolean isAdd = scanner.nextBoolean();
                    
                    p.updateStock(stock, isAdd);
                    
                    break;
                }
                
                case 6: {
                    scanner.nextLine();
                    String min, max, price;
                    
                    System.out.println("Fiyat girin (Eger fiyatsiz islem yapmak istiyorsaniz sayi harici herhangi bir karakter giriniz):");
                    price = scanner.nextLine();
                    
                    try {
                        double priceDouble = Double.parseDouble(price);
                        try {
                            System.out.println("Min stok giriniz (Eger stoksuz islem yapmak istiyorsaniz sayi harici herhangi bir karakter giriniz):");
                            min = scanner.nextLine();
                            
                            int minInt = Integer.parseInt(min);
                            
                            System.out.println("Max stok giriniz (Eger stoksuz islem yapmak istiyorsaniz sayi harici herhangi bir karakter giriniz):");
                            max = scanner.nextLine();
                            
                            int maxInt = Integer.parseInt(max);
                            
                            DairyProducts_2215.removeDairyProduct(minInt, maxInt, priceDouble);
                        }
                        catch (NumberFormatException e) {
                            DairyProducts_2215.removeDairyProduct(priceDouble);
                        }
                    
                    }
                    catch (NumberFormatException e) {
                        DairyProducts_2215.removeDairyProduct();
                    }
                    break;
                }
                
                case 7: {
                    System.out.println("Hangi metod ile islem yapmak istiyorsunuz? (1/2):\n"
                            + "1. TahilUrunEkle(Adi, BirimFiyatı, StokMiktari)\n"
                            + "2. TahilUrunEkle(Adi, BirimAgirligi, BirimFiyatı, Detay)");
                    int choice2 = scanner.nextInt();
                    
                    if (choice2 == 1) {
                        scanner.nextLine();
                        System.out.println("Isim giriniz:");
                        String name = scanner.nextLine();
                        System.out.println("Fiyat giriniz:");
                        double price = scanner.nextDouble();
                        System.out.println("Stok giriniz:");
                        int stock = scanner.nextInt();
                        
                        Cereals_2215.addNewCerealProduct(name, price, stock);
                    }
                    else if (choice2 == 2) {
                        scanner.nextLine();
                        System.out.println("Isim giriniz:");
                        String name = scanner.nextLine();
                        System.out.println("Birim agirlik giriniz:");
                        String weight = scanner.nextLine();
                        System.out.println("Fiyat giriniz:");
                        double price = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Detay giriniz:");
                        String details = scanner.nextLine();
                        
                        Cereals_2215.addNewCerealProduct(name, weight, price, details);
                    }
                    else {
                        System.out.println("Anlamsiz bir sayi girildi. Menuye yonlendiriliyorsunuz.");
                    }
                    
                    break;
                }
                
                case 8: {
                    return;
                }
                
                default: {
                    System.out.println("Lutfen menudeki seceneklerden birini seciniz.");
                }
            }
            
        }
    }

    public static void createLists(String dir) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(dir));
            
            String line = br.readLine();    // Skip the title
            
            while (true) {
                line = br.readLine();
                
                if (line == null || line.isBlank() ) {
                    break;
                }
                
                String[] ats = line.split("\t");    // 0: name, 1: catIndex, 2: weight, 3: price, 4: stock
                String[] cAts = getCategoryInfo(Integer.parseInt(ats[1]));
                
                switch (Integer.parseInt(ats[1])) {
                    case 1: {    // Beverages
                        beverageList.add(new Beverages_2215(ats[0], 
                                Integer.parseInt(ats[1]), 
                                ats[2], 
                                Double.parseDouble(ats[3]), 
                                Integer.parseInt(ats[4]),
                                cAts[1],
                                cAts[2]));
                        break;
                    }
                    case 2: {    // Condiments
                        condimentList.add(new Condiments_2215(ats[0], 
                                Integer.parseInt(ats[1]), 
                                ats[2], 
                                Double.parseDouble(ats[3]), 
                                Integer.parseInt(ats[4]),
                                cAts[1],
                                cAts[2]));
                        break;
                    }
                    case 3: {    // Confections
                        confectionList.add(new Confections_2215(ats[0], 
                                Integer.parseInt(ats[1]), 
                                ats[2], 
                                Double.parseDouble(ats[3]), 
                                Integer.parseInt(ats[4]),
                                cAts[1],
                                cAts[2]));
                        break;
                    }
                    case 4: {    // DairyProducts
                        dairyList.add(new DairyProducts_2215(ats[0], 
                                Integer.parseInt(ats[1]), 
                                ats[2], 
                                Double.parseDouble(ats[3]), 
                                Integer.parseInt(ats[4]),
                                cAts[1],
                                cAts[2]));
                        break;
                    }
                    case 5: {    // Cereals
                        cerealList.add(new Cereals_2215(ats[0], 
                                Integer.parseInt(ats[1]), 
                                ats[2], 
                                Double.parseDouble(ats[3]), 
                                Integer.parseInt(ats[4]),
                                cAts[1],
                                cAts[2]));
                        break;
                    }
                }
            }
            
            
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static String[] getCategoryInfo(int categoryIndex) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("UrunGrubu.txt"));
            
            String line = br.readLine();    // Skip the title
            
            while (true) {
                line = br.readLine();
                
                if (line == null || line.isBlank() ) {
                    break;
                }
                
                String[] ats = line.split("\t");    // 0: index, 1: name, 2: details
                
                if (Integer.parseInt(ats[0]) == categoryIndex) {
                    return ats;
                }
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        
        return null;
    }

    public static void printLists() {
        System.out.println("\nBeverages:");
        System.out.println(String.format("%-32s %-14s %-30s %-14s %-14s", 
                "Adi", "KategoriIndex", "BirimAgirligi", "BirimFiyati", "StokMiktari"));
        for (Product_2215 p : beverageList) {
            System.out.println(String.format("%-32s %-14d %-30s %-14.2f %-14d", 
                    p.getName(), p.getCategoryIndex(), p.getUntiWeight(), p.getUnitPrice(), p.getStock()));
        }
        
        System.out.println("\nCondiments:");
        System.out.println(String.format("%-32s %-14s %-30s %-14s %-14s", 
                "Adi", "KategoriIndex", "BirimAgirligi", "BirimFiyati", "StokMiktari"));
        for (Product_2215 p : condimentList) {
            System.out.println(String.format("%-32s %-14d %-30s %-14.2f %-14d", 
                    p.getName(), p.getCategoryIndex(), p.getUntiWeight(), p.getUnitPrice(), p.getStock()));
        }
        
        System.out.println("\nConfections:");
        System.out.println(String.format("%-32s %-14s %-30s %-14s %-14s", 
                "Adi", "KategoriIndex", "BirimAgirligi", "BirimFiyati", "StokMiktari"));
        for (Product_2215 p : confectionList) {
            System.out.println(String.format("%-32s %-14d %-30s %-14.2f %-14d", 
                    p.getName(), p.getCategoryIndex(), p.getUntiWeight(), p.getUnitPrice(), p.getStock()));
        }
        
        System.out.println("\nDairy Products:");
        System.out.println(String.format("%-32s %-14s %-30s %-14s %-14s", 
                "Adi", "KategoriIndex", "BirimAgirligi", "BirimFiyati", "StokMiktari"));
        for (Product_2215 p : dairyList) {
            System.out.println(String.format("%-32s %-14d %-30s %-14.2f %-14d", 
                    p.getName(), p.getCategoryIndex(), p.getUntiWeight(), p.getUnitPrice(), p.getStock()));
        }
        
        System.out.println("\nCereals:");
        System.out.println(String.format("%-32s %-14s %-30s %-14s %-14s", 
                "Adi", "KategoriIndex", "BirimAgirligi", "BirimFiyati", "StokMiktari"));
        for (Product_2215 p : cerealList) {
            System.out.println(String.format("%-32s %-14d %-30s %-14.2f %-14d", 
                    p.getName(), p.getCategoryIndex(), p.getUntiWeight(), p.getUnitPrice(), p.getStock()));
        }
    }
}
