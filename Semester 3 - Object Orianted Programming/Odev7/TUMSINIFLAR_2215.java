//Main_2215
import java.awt.color.ProfileDataException;
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
            printAllLists();
            
            Scanner scanner = new Scanner(System.in);
            
            System.out.println("\nSinif Secimi:\n"
                    + "1. Beverages\n"
                    + "2. Condiments\n"
                    + "3. Confections\n"
                    + "4. DairyProducts\n"
                    + "5. Cereals");
            
            int classChoice = scanner.nextInt();
            
            if (classChoice < 1 || classChoice > 5) {
                System.out.println("Lutfen yukaridaki siniflardan birini seciniz.");
                continue;
            }
            
            ArrayList<? extends Product_2215> chosenList = null;
            int coefficient = 0;
            
            switch (classChoice) {
                case 1: {
                    chosenList = beverageList;
                    printList(beverageList, "Beverages");
                    coefficient = Beverages_2215.getCoefficient();
                    break;
                }
                case 2: {
                    chosenList = condimentList;
                    printList(condimentList, "Condiments");
                    coefficient = Condiments_2215.getCoefficient();
                    break;
                }
                case 3: {
                    chosenList = confectionList;
                    printList(confectionList, "Confections");
                    coefficient = Confections_2215.getCoefficient();
                    break;
                }
                case 4: {
                    chosenList = dairyList;
                    printList(dairyList, "DairyProducts");
                    coefficient = DairyProducts_2215.getCoefficient();
                    break;
                }
                case 5: {
                    chosenList = cerealList;
                    printList(cerealList, "Cereals");
                    coefficient = Cereals_2215.getCoefficient();
                    break;
                }
            }
            
            System.out.println("Lutfen yukaridaki listeden bir urunun indexini giriniz.");
            int productIndex = scanner.nextInt();
            
            if (productIndex < 0 || productIndex >= chosenList.size()) {
                System.out.println("Girilen index'te urun yok.");
                continue;
            }
            
            Product_2215 chosenProduct = chosenList.get(productIndex);
            
            System.out.println("\nMENU:\n"
                    + "1. UrunStokGuncelle(int adet, bool GirisMi)\n"
                    + "2. UrunIsimGuncelle(String yeniIsım, String yeniDetay)\n"
                    + "3. UrunSil()\n"
                    + "4. YeniUrunEkle(Adi, BirimAgirligi, BirimFiyatı, StokMiktari, Detay)\n"
                    + "5. UrunFiyatGuncelle(int oran, bool indirimMi)\n"
                    + "6. UrunKategorikZamYap(int X)\n"
                    + "7. Cikis");
            
            
            int menuChoice = scanner.nextInt();
            
            switch (menuChoice) {
                case 1: {
                    System.out.println("Adet giriniz:");
                    int num = scanner.nextInt();
                    System.out.println("GirisMi:");
                    boolean isAdd = scanner.nextBoolean();
                    
                    chosenProduct.updateProductStock(num, isAdd);
                    break;
                }
                case 2: {
                    scanner.nextLine();
                    System.out.println("Yeni isim giriniz:");
                    String name = scanner.nextLine();
                    System.out.println("Yeni detay giriniz:");
                    String detail = scanner.nextLine();
                    
                    chosenProduct.updateProductName(name, detail);
                    break;
                }
                case 3: {
                    chosenProduct.removeProduct(chosenList);
                    break;
                }
                case 4: {
                    scanner.nextLine();
                    System.out.println("Isim giriniz:");
                    String name = scanner.nextLine();
                    System.out.println("Birim agirlik giriniz:");
                    String weight = scanner.nextLine();
                    System.out.println("Birim fiyat giriniz:");
                    double price = scanner.nextDouble();
                    System.out.println("Stok miktari giriniz:");
                    int stock = scanner.nextInt();
                    scanner.nextLine();
                    System.out.println("Detay giriniz:");
                    String detail = scanner.nextLine();
                    
                    chosenProduct.addNewProduct(name, weight, price, stock, detail);
                    break;
                }
                case 5: {
                    System.out.println("Oran giriniz:");
                    int ratio = scanner.nextInt();
                    System.out.println("indirimMi:");
                    boolean isSale = scanner.nextBoolean();
                    
                    chosenProduct.updateProductPrice(ratio, isSale, coefficient);
                    break;
                }
                case 6: {
                    System.out.println("X giriniz:");
                    int x = scanner.nextInt();
                    
                    Product_2215.raisePriceByCategory(x, chosenList, coefficient);
                    break;
                }
                case 7: {
                    return;
                }
                default: {
                    System.out.println("Lutfen menudeki seceneklerden birini giriniz.");
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

    public static void printList(ArrayList<? extends Product_2215> list, String title) {
        System.out.println("\n" + title);
        
        System.out.println(String.format("%-32s %-14s %-30s %-14s %-14s", 
                "Adi", "KategoriIndex", "BirimAgirligi", "BirimFiyati", "StokMiktari"));
        
        for (Product_2215 p : list) {
            System.out.println(String.format("%-32s %-14d %-30s %-14.2f %-14d", 
                    p.getName(), p.getCategoryIndex(), p.getWeight(), p.getPrice(), p.getStock()));
        }
    }
    
    public static void printAllLists() {
        printList(beverageList, "Beverages");
        printList(condimentList, "Condiments");
        printList(confectionList, "Confections");
        printList(dairyList, "Dairy Products");
        printList(cerealList, "Grains/Cereals");
    }
}

//IProduct_2215
import java.util.ArrayList;

public interface IProduct_2215 {
    public void updateProductStock(int amount, boolean isAdd);
    public void updateProductName(String newName, String newDetails);
    public void removeProduct(ArrayList<? extends Product_2215> list);
    public void addNewProduct(String name, String weight, double price, int stock, String details);
}

//Product_2215
import java.util.ArrayList;

public abstract class Product_2215 implements IProduct_2215 {
    private String name;
    private int categoryIndex;
    private String weight;
    private double price;
    private int stock;
    
    
    public Product_2215(String name, int categoryIndex, String weight, double price, int stock) {
        this.name = name;
        this.categoryIndex = categoryIndex;
        this.weight = weight;
        this.price = price;
        this.stock = stock;
    }
    
    
    public void updateProductPrice(int ratio, boolean isSale, int coefficient) {
        ratio += coefficient;
        
        if (isSale) {
            this.price *= (100.0 - ratio) / 100.0;
        }
        else {
            this.price *= (100.0 + ratio) / 100.0;
        }
    }
    
    public static void raisePriceByCategory(int x, ArrayList<? extends Product_2215> list, int coefficient) {
        x += coefficient;
        
        for (Product_2215 p : list) {
            p.setPrice(p.getPrice() * (100.0 + x) / 100.0);
        }
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
    
    public String getWeight() {
        return weight;
    }
    
    public void setWeight(String weight) {
        this.weight = weight;
    }
    
    public double getPrice() {
        return price;
    }
    
    public void setPrice(double price) {
        this.price = price;
    }
    
    public int getStock() {
        return stock;
    }
    
    public void setStock(int stock) {
        this.stock = stock;
    }    
}

//Beverages_2215
import java.util.ArrayList;

public class Beverages_2215 extends Product_2215 {
    private static final int coefficient = 1;
    private String categoryName;
    private String details;
    
    
    public Beverages_2215(String name, int categoryIndex, String weight, double price, int stock, String categoryName,
            String details) {
        super(name, categoryIndex, weight, price, stock);
        this.categoryName = categoryName;
        this.details = details;
    }
    
    
    @Override
    public void updateProductStock(int amount, boolean isAdd) {
        amount += coefficient;
        
        if (isAdd) {
            this.setStock(this.getStock() + amount);
        }
        else {
            this.setStock(this.getStock() - amount);
        }
    }

    @Override
    public void updateProductName(String newName, String newDetails) {
        this.setName(newName);
        this.setDetails(this.getDetails() + ", " + newDetails);
    }

    @Override
    public void removeProduct(ArrayList<? extends Product_2215> list) {
        list.remove(this);
    }
    
    @Override
    public void addNewProduct(String name, String weight, double price, int stock, String details) {
        switch (this.getCategoryIndex()) {
            case 1: {
                Main_2215.beverageList.add(new Beverages_2215(name, 1, weight, price, stock, "Beverages", details));
                break;
            }
            case 2: {
                Main_2215.condimentList.add(new Condiments_2215(name, 2, weight, price, stock, "Condiments", details));
                break;
            }
            case 3: {
                Main_2215.confectionList.add(new Confections_2215(name, 3, weight, price, stock, "Confections", details));
                break;
            }
            case 4: {
                Main_2215.dairyList.add(new DairyProducts_2215(name, 4, weight, price, stock, "Dairy Products", details));
                break;
            }
            case 5: {
                Main_2215.cerealList.add(new Cereals_2215(name, 5, weight, price, stock, "Grains/Cereals", details));
                break;
            }
        }
    }
    
    
    // Getters and Setters
    
    public static int getCoefficient() {
        return coefficient;
    }
    
    public String getCategoryName() {
        return categoryName;
    }

    public void setCategoryName(String categoryName) {
        this.categoryName = categoryName;
    }

    public String getDetails() {
        return details;
    }

    public void setDetails(String details) {
        this.details = details;
    }
}

//Condiments_2215
import java.util.ArrayList;

public class Condiments_2215 extends Product_2215 {
    private static final int coefficient = 2;
    private String categoryName;
    private String details;
    
    
    public Condiments_2215(String name, int categoryIndex, String weight, double price, int stock, String categoryName,
            String details) {
        super(name, categoryIndex, weight, price, stock);
        this.categoryName = categoryName;
        this.details = details;
    }
    
    @Override
    public void updateProductStock(int amount, boolean isAdd) {
        amount += coefficient;
        
        if (isAdd) {
            this.setStock(this.getStock() + amount);
        }
        else {
            this.setStock(this.getStock() - amount);
        }
        
    }

    @Override
    public void updateProductName(String newName, String newDetails) {
        this.setName(newName);
        this.setDetails(this.getDetails() + ", " + newDetails);
    }

    @Override
    public void removeProduct(ArrayList<? extends Product_2215> list) {
        list.remove(this);
    }

    @Override
    public void addNewProduct(String name, String weight, double price, int stock, String details) {
        switch (this.getCategoryIndex()) {
            case 1: {
                Main_2215.beverageList.add(new Beverages_2215(name, 1, weight, price, stock, "Beverages", details));
                break;
            }
            case 2: {
                Main_2215.condimentList.add(new Condiments_2215(name, 2, weight, price, stock, "Condiments", details));
                break;
            }
            case 3: {
                Main_2215.confectionList.add(new Confections_2215(name, 3, weight, price, stock, "Confections", details));
                break;
            }
            case 4: {
                Main_2215.dairyList.add(new DairyProducts_2215(name, 4, weight, price, stock, "Dairy Products", details));
                break;
            }
            case 5: {
                Main_2215.cerealList.add(new Cereals_2215(name, 5, weight, price, stock, "Grains/Cereals", details));
                break;
            }
        }
    }
    
    
    // Getters and Setters

    public static int getCoefficient() {
        return coefficient;
    }
    
    public String getCategoryName() {
        return categoryName;
    }

    public void setCategoryName(String categoryName) {
        this.categoryName = categoryName;
    }

    public String getDetails() {
        return details;
    }

    public void setDetails(String details) {
        this.details = details;
    }
}

//Confections_2215
import java.util.ArrayList;

public class Confections_2215 extends Product_2215 {
    private static final int coefficient = 3;
    private String categoryName;
    private String details;
    
    
    public Confections_2215(String name, int categoryIndex, String weight, double price, int stock, String categoryName,
            String details) {
        super(name, categoryIndex, weight, price, stock);
        this.categoryName = categoryName;
        this.details = details;
    }
    
    
    @Override
    public void updateProductStock(int amount, boolean isAdd) {
        amount += coefficient;
        
        if (isAdd) {
            this.setStock(this.getStock() + amount);
        }
        else {
            this.setStock(this.getStock() - amount);
        }
        
    }

    @Override
    public void updateProductName(String newName, String newDetails) {
        this.setName(newName);
        this.setDetails(this.getDetails() + ", " + newDetails);
    }
    
    @Override
    public void removeProduct(ArrayList<? extends Product_2215> list) {
        list.remove(this);
    }

    @Override
    public void addNewProduct(String name, String weight, double price, int stock, String details) {
        switch (this.getCategoryIndex()) {
            case 1: {
                Main_2215.beverageList.add(new Beverages_2215(name, 1, weight, price, stock, "Beverages", details));
                break;
            }
            case 2: {
                Main_2215.condimentList.add(new Condiments_2215(name, 2, weight, price, stock, "Condiments", details));
                break;
            }
            case 3: {
                Main_2215.confectionList.add(new Confections_2215(name, 3, weight, price, stock, "Confections", details));
                break;
            }
            case 4: {
                Main_2215.dairyList.add(new DairyProducts_2215(name, 4, weight, price, stock, "Dairy Products", details));
                break;
            }
            case 5: {
                Main_2215.cerealList.add(new Cereals_2215(name, 5, weight, price, stock, "Grains/Cereals", details));
                break;
            }
        }
    }
    
    
    // Getters and Setters

    public static int getCoefficient() {
        return coefficient;
    }
    
    public String getCategoryName() {
        return categoryName;
    }

    public void setCategoryName(String categoryName) {
        this.categoryName = categoryName;
    }

    public String getDetails() {
        return details;
    }

    public void setDetails(String details) {
        this.details = details;
    }
}

//DairyProducts_2215
import java.util.ArrayList;

public class DairyProducts_2215 extends Product_2215 {
    private static final int coefficient = 4;
    private String categoryName;
    private String details;
    
    
    public DairyProducts_2215(String name, int categoryIndex, String weight, double price, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, weight, price, stock);
        this.categoryName = categoryName;
        this.details = details;
    }
    
    
    @Override
    public void updateProductStock(int amount, boolean isAdd) {
        amount += coefficient;
        
        if (isAdd) {
            this.setStock(this.getStock() + amount);
        }
        else {
            this.setStock(this.getStock() - amount);
        }
    }

    @Override
    public void updateProductName(String newName, String newDetails) {
        this.setName(newName);
        this.setDetails(this.getDetails() + ", " + newDetails);
    }
    
    @Override
    public void removeProduct(ArrayList<? extends Product_2215> list) {
        list.remove(this);
    }
    
    @Override
    public void addNewProduct(String name, String weight, double price, int stock, String details) {
        switch (this.getCategoryIndex()) {
            case 1: {
                Main_2215.beverageList.add(new Beverages_2215(name, 1, weight, price, stock, "Beverages", details));
                break;
            }
            case 2: {
                Main_2215.condimentList.add(new Condiments_2215(name, 2, weight, price, stock, "Condiments", details));
                break;
            }
            case 3: {
                Main_2215.confectionList.add(new Confections_2215(name, 3, weight, price, stock, "Confections", details));
                break;
            }
            case 4: {
                Main_2215.dairyList.add(new DairyProducts_2215(name, 4, weight, price, stock, "Dairy Products", details));
                break;
            }
            case 5: {
                Main_2215.cerealList.add(new Cereals_2215(name, 5, weight, price, stock, "Grains/Cereals", details));
                break;
            }
        }
    }
    
    
    // Getters and Setters

    public static int getCoefficient() {
        return coefficient;
    }
    
    public String getCategoryName() {
        return categoryName;
    }

    public void setCategoryName(String categoryName) {
        this.categoryName = categoryName;
    }

    public String getDetails() {
        return details;
    }

    public void setDetails(String details) {
        this.details = details;
    }
}

//Cereals_2215
import java.util.ArrayList;

public class Cereals_2215 extends Product_2215 {
    private static final int coefficient = 5;
    private String categoryName;
    private String details;
    

    public Cereals_2215(String name, int categoryIndex, String weight, double price, int stock, String categoryName,
            String details) {
        super(name, categoryIndex, weight, price, stock);
        this.categoryName = categoryName;
        this.details = details;
    }
    
        
    @Override
    public void updateProductStock(int amount, boolean isAdd) {
        amount += coefficient;
        
        if (isAdd) {
            this.setStock(this.getStock() + amount);
        }
        else {
            this.setStock(this.getStock() - amount);
        }
        
    }

    @Override
    public void updateProductName(String newName, String newDetails) {
        this.setName(newName);
        this.setDetails(this.getDetails() + ", " + newDetails);
    }
    
    @Override
    public void removeProduct(ArrayList<? extends Product_2215> list) {
        list.remove(this);
    }
    
    @Override
    public void addNewProduct(String name, String weight, double price, int stock, String details) {
        switch (this.getCategoryIndex()) {
            case 1: {
                Main_2215.beverageList.add(new Beverages_2215(name, 1, weight, price, stock, "Beverages", details));
                break;
            }
            case 2: {
                Main_2215.condimentList.add(new Condiments_2215(name, 2, weight, price, stock, "Condiments", details));
                break;
            }
            case 3: {
                Main_2215.confectionList.add(new Confections_2215(name, 3, weight, price, stock, "Confections", details));
                break;
            }
            case 4: {
                Main_2215.dairyList.add(new DairyProducts_2215(name, 4, weight, price, stock, "Dairy Products", details));
                break;
            }
            case 5: {
                Main_2215.cerealList.add(new Cereals_2215(name, 5, weight, price, stock, "Grains/Cereals", details));
                break;
            }
        }
    }
    
    
    // Getters and Setters

    public static int getCoefficient() {
        return coefficient;
    }
    
    public String getCategoryName() {
        return categoryName;
    }

    public void setCategoryName(String categoryName) {
        this.categoryName = categoryName;
    }

    public String getDetails() {
        return details;
    }

    public void setDetails(String details) {
        this.details = details;
    }
}
