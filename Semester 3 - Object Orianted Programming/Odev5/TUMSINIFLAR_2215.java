//DataReader_2215
package package1;

import java.io.BufferedReader;
import java.io.FileReader;

import package2.Beverages_2215;
import package2.Cereals_2215;
import package2.Condiments_2215;
import package2.Confections_2215;
import package2.DairyProducts_2215;
import package2.Main_2215;

public class DataReader_2215 {
    
    protected static void ListeleriOlustur(String dir) {
        try {
            // Reading UrunGrubu.txt to extract category details
            BufferedReader br = new BufferedReader(new FileReader("UrunGrubu.txt"));
            
            String line = br.readLine();    // Read the title line
            
            while (true) {
                line = br.readLine();
                
                if (line == null || line.isEmpty()) {
                    break;
                }
                
                String[] attributes = line.split("\t");    // 0: CategoryIndex, 1: CategoryName, 2: Details
                
                switch (Integer.parseInt(attributes[0])) {
                    case 1:
                        Beverages_2215.setCategoryName(attributes[1]);
                        Beverages_2215.setDetails(attributes[2]);
                        break;
                    case 2:
                        Condiments_2215.setCategoryName(attributes[1]);
                        Condiments_2215.setDetails(attributes[2]);
                        break;
                    case 3:
                        Confections_2215.setCategoryName(attributes[1]);
                        Confections_2215.setDetails(attributes[2]);
                        break;
                    case 4:
                        DairyProducts_2215.setCategoryName(attributes[1]);
                        DairyProducts_2215.setDetails(attributes[2]);
                        break;
                    case 5:
                        Cereals_2215.setCategoryName(attributes[1]);
                        Cereals_2215.setDetails(attributes[2]);
                        break;
                }
            }
            
            br.close();
            
            // Reading Urunler.txt to extract products
            br = new BufferedReader(new FileReader(dir));
            
            line = br.readLine();    // Read the title line
            
            while (true) {
                line = br.readLine();
                
                if (line == null || line.isEmpty()) {
                    break;
                }
                
                
                String[] attributes = line.split("\t");    // 0: Name, 1: CategoryIndex, 2: UnitWeight, 3: UnitPrice, 4: Stock
                
                switch (Integer.parseInt(attributes[1])) {
                    case 1:    // Beverages
                        Main_2215.beverageList.add(new Beverages_2215(attributes[0],
                                Integer.parseInt(attributes[1]),
                                attributes[2],
                                Double.parseDouble(attributes[3]),
                                Integer.parseInt(attributes[4])
                                ));
                        break;
                    case 2:    // Condiments
                        Main_2215.condimentList.add(new Condiments_2215(attributes[0],
                                Integer.parseInt(attributes[1]),
                                attributes[2],
                                Double.parseDouble(attributes[3]),
                                Integer.parseInt(attributes[4])
                                ));
                        break;
                    case 3:    // Confections
                        Main_2215.confectionList.add(new Confections_2215(attributes[0],
                                Integer.parseInt(attributes[1]),
                                attributes[2],
                                Double.parseDouble(attributes[3]),
                                Integer.parseInt(attributes[4])
                                ));
                        break;
                    case 4:    // DairyProducts
                        Main_2215.dairyProductList.add(new DairyProducts_2215(attributes[0],
                                Integer.parseInt(attributes[1]),
                                attributes[2],
                                Double.parseDouble(attributes[3]),
                                Integer.parseInt(attributes[4])
                                ));
                        break;
                    case 5:    // Cereals
                        Main_2215.cerealList.add(new Cereals_2215(attributes[0],
                                Integer.parseInt(attributes[1]),
                                attributes[2],
                                Double.parseDouble(attributes[3]),
                                Integer.parseInt(attributes[4])
                                ));
                        break;
                }
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

}

//Main_2215
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

//Product_2215
package package2;

public class Product_2215 {
    private String name;
    private int categoryIndex;
    private String unitWeight;
    private double unitPrice;
    private int stock;
    
    
    public Product_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super();
        this.name = name;
        this.categoryIndex = categoryIndex;
        this.unitWeight = unitWeight;
        this.unitPrice = unitPrice;
        this.stock = stock;
    }

    protected static void UrunleriFiyataGoreSil(double minPrice, double maxPrice) {
        for (int i = Main_2215.beverageList.size() - 1; i > -1; i--) {
            Product_2215 p = Main_2215.beverageList.get(i);
            if (p.getUnitPrice() < maxPrice && p.getUnitPrice() > minPrice) {
                Main_2215.beverageList.remove(i);
            }
        }
        
        for (int i = Main_2215.condimentList.size() - 1; i > -1; i--) {
            Product_2215 p = Main_2215.condimentList.get(i);
            if (p.getUnitPrice() < maxPrice && p.getUnitPrice() > minPrice) {
                Main_2215.condimentList.remove(i);
            }
        }
        
        
        for (int i = Main_2215.confectionList.size() - 1; i > -1; i--) {
            Product_2215 p = Main_2215.confectionList.get(i);
            if (p.getUnitPrice() < maxPrice && p.getUnitPrice() > minPrice) {
                Main_2215.confectionList.remove(i);
            }
        }
        
        for (int i = Main_2215.dairyProductList.size() - 1; i > -1; i--) {
            Product_2215 p = Main_2215.dairyProductList.get(i);
            if (p.getUnitPrice() < maxPrice && p.getUnitPrice() > minPrice) {
                Main_2215.dairyProductList.remove(i);
            }
        }
        
        for (int i = Main_2215.cerealList.size() - 1; i > -1; i--) {
            Product_2215 p = Main_2215.cerealList.get(i);
            if (p.getUnitPrice() < maxPrice && p.getUnitPrice() > minPrice) {
                Main_2215.cerealList.remove(i);
            }
        }
    }

    protected static void UrunKategoriStokGuncelle(String categoryName, int x) {
         switch (categoryName.toLowerCase().trim()) {
             case "beverages":
             case "beverage":
                 for (Product_2215 p : Main_2215.beverageList) {
                    p.setStock(p.getStock() + (int)(p.getStock() * (x / 100f)));
                 }
                 break;
             case "condiments":
             case "condiment":
                 for (Product_2215 p : Main_2215.condimentList) {
                     p.setStock(p.getStock() + (int)(p.getStock() * (x / 100f)));
                  }
                 break;
             case "confections":
             case "confection":
                 for (Product_2215 p : Main_2215.confectionList) {
                     p.setStock(p.getStock() + (int)(p.getStock() * (x / 100f)));
                  }
                 break;
             case "dairyproducts":
             case "dairy products":
             case "dairyproduct":
             case "dairy product":
                 for (Product_2215 p : Main_2215.dairyProductList) {
                     p.setStock(p.getStock() + (int)(p.getStock() * (x / 100f)));
                  }
                 break;
             case "cereals":
             case "cereal":
             case "grains/cereals":
                 for (Product_2215 p : Main_2215.cerealList) {
                     p.setStock(p.getStock() + (int)(p.getStock() * (x / 100f)));
                  }
                 break;
             default:
                 System.out.println("Girilen kategori ismi bulunamadı.");
         }
    }
    
    protected static void printAllProducts() {
        System.out.println(String.format("%-34s %-14s %-30s %-12s %-12s", 
                "Adi", "KategoriIndex", "BirimAgirligi", "BirimFiyati", "StokMiktari"));
        for (Product_2215 p : Main_2215.beverageList) {
            System.out.println(String.format("%-34s %-14d %-30s %-12.2f %-12d", 
                    p.name, p.categoryIndex, p.unitWeight, p.unitPrice, p.stock));
        }
        
        for (Product_2215 p : Main_2215.condimentList) {
            System.out.println(String.format("%-34s %-14d %-30s %-12.2f %-12d", 
                    p.name, p.categoryIndex, p.unitWeight, p.unitPrice, p.stock));
        }
        
        for (Product_2215 p : Main_2215.confectionList) {
            System.out.println(String.format("%-34s %-14d %-30s %-12.2f %-12d", 
                    p.name, p.categoryIndex, p.unitWeight, p.unitPrice, p.stock));
        }
        
        for (Product_2215 p : Main_2215.dairyProductList) {
            System.out.println(String.format("%-34s %-14d %-30s %-12.2f %-12d", 
                    p.name, p.categoryIndex, p.unitWeight, p.unitPrice, p.stock));
        }
        
        for (Product_2215 p : Main_2215.cerealList) {
            System.out.println(String.format("%-34s %-14d %-30s %-12.2f %-12d", 
                    p.name, p.categoryIndex, p.unitWeight, p.unitPrice, p.stock));
        }
    }
    
    protected static void printCategories() {
        System.out.println(String.format("%-14s %-30s %-80s", "KategoriIndex", "Adi", "Detay"));
        System.out.println(String.format("%-14d %-30s %-80s", 1, Beverages_2215.getCategoryName(), Beverages_2215.getDetails()));
        System.out.println(String.format("%-14d %-30s %-80s", 2, Condiments_2215.getCategoryName(), Condiments_2215.getDetails()));
        System.out.println(String.format("%-14d %-30s %-80s", 3, Confections_2215.getCategoryName(), Confections_2215.getDetails()));
        System.out.println(String.format("%-14d %-30s %-80s", 4, DairyProducts_2215.getCategoryName(), DairyProducts_2215.getDetails()));
        System.out.println(String.format("%-14d %-30s %-80s", 5, Cereals_2215.getCategoryName(), Cereals_2215.getDetails()));
    }
    
    // Getters and Setters
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getCategoryIndex() {
        return categoryIndex;
    }

    public void setCategoryIndex(int categoryIndex) {
        this.categoryIndex = categoryIndex;
    }

    public String getUnitWeight() {
        return unitWeight;
    }

    public void setUnitWeight(String unitWeight) {
        this.unitWeight = unitWeight;
    }

    public double getUnitPrice() {
        return unitPrice;
    }

    public void setUnitPrice(double unitPrice) {
        this.unitPrice = unitPrice;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }
}

//Beverages_2215
package package2;

public class Beverages_2215 extends Product_2215 {
    private static String categoryName;
    private static String details;
    
    public Beverages_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
    }
    
    protected static void IcecekBirimAgirlikGuncelle(String newWeight) {
        if (Main_2215.beverageList.isEmpty()) {
            System.out.println("Içecek listesi boş.");
            return;
        }
        
        Main_2215.beverageList.get(Main_2215.beverageList.size() - 1).setUnitWeight(newWeight);
    }

    
    
    // Getters and Setters
    public static String getCategoryName() {
        return categoryName;
    }

    public static void setCategoryName(String newCategoryName) {
        categoryName = newCategoryName;
    }

    public static String getDetails() {
        return details;
    }

    public static void setDetails(String newDetails) {
        details = newDetails;
    }
}

//Condiments_2215
package package2;

import java.util.Scanner;

public class Condiments_2215 extends Product_2215 {
    private static String categoryName;
    private static String details;
    
    public Condiments_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
    }
    
    protected static void CesniStokGuncelle(boolean isSell, int amount) {
        System.out.println("İşlem yapılacak olan çeşni'nin index'ini giriniz.");
        Scanner scanner = new Scanner(System.in);
        int targetIndex = scanner.nextInt();
        
        if (targetIndex >= Main_2215.condimentList.size() || targetIndex < 0) {
            System.out.println("Girilen index çeşni listesinin dışında. İşlem iptal edildi.");
            return;
        }
        
        Condiments_2215 targetCondiment = Main_2215.condimentList.get(targetIndex);

        if (isSell) {
            if (targetCondiment.getStock() < amount) {    // Negative check
                amount = targetCondiment.getStock();
            }
            amount *= -1;
        }
        
        targetCondiment.setStock(targetCondiment.getStock() + amount);
    }
    
    // Getters and Setters
    public static String getCategoryName() {
        return categoryName;
    }

    public static void setCategoryName(String newCategoryName) {
        categoryName = newCategoryName;
    }

    public static String getDetails() {
        return details;
    }

    public static void setDetails(String newDetails) {
        details = newDetails;
    }
}

//Confections_2215
package package2;


public class Confections_2215 extends Product_2215 {
    private static String categoryName;
    private static String details;
    
    public Confections_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
    }
    
    protected static void SekerlemeUrunEkle(String name, String unitWeight, double unitPrice, int stock) {
        Main_2215.confectionList.add(new Confections_2215(name, 3,
                unitWeight, unitPrice, stock));
    }
    
    // Getters and Setters
    public static String getCategoryName() {
        return categoryName;
    }

    public static void setCategoryName(String newCategoryName) {
        categoryName = newCategoryName;
    }

    public static String getDetails() {
        return details;
    }

    public static void setDetails(String newDetails) {
        details = newDetails;
    }
}

//DairyProducts_2215
package package2;

public class DairyProducts_2215 extends Product_2215 {
    public static String categoryName;
    public static String details;
    
    public DairyProducts_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
    }
    
    protected static void SutUrunleriDetayEkle(String newDetail) {
        details += ", " + newDetail;
    }
    
    // Getters and Setters
    public static String getCategoryName() {
        return categoryName;
    }

    public static void setCategoryName(String newCategoryName) {
        categoryName = newCategoryName;
    }

    public static String getDetails() {
        return details;
    }

    public static void setDetails(String newDetails) {
        details = newDetails;
    }
}

//Cereals_2215
package package2;

public class Cereals_2215 extends Product_2215 {
    private static String categoryName;
    private static String details;
    
    public Cereals_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
    }
    
    protected static void HububatSil(String productName) {
        for (Cereals_2215 c : Main_2215.cerealList) {
            if (c.getName().toLowerCase().equals(productName.toLowerCase())) {
                Main_2215.cerealList.remove(c);
                break;
            }
        }
    }
    
    
    // Getters and Setters
    public static String getCategoryName() {
        return categoryName;
    }

    public static void setCategoryName(String newCategoryName) {
        categoryName = newCategoryName;
    }

    public static String getDetails() {
        return details;
    }

    public static void setDetails(String newDetails) {
        details = newDetails;
    }
}
