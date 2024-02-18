//Main_2215
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Main_2215 {
    public static ArrayList<Beverages_2215> beverageList = new ArrayList<Beverages_2215>();
    public static ArrayList<Condiments_2215> condimentList = new ArrayList<Condiments_2215>();
    public static ArrayList<Confections_2215> confectionList = new ArrayList<Confections_2215>();
    public static ArrayList<DairyProducts_2215> dairyProductList = new ArrayList<DairyProducts_2215>();
    public static ArrayList<Cereals_2215> cerealList = new ArrayList<Cereals_2215>();
    
    
    public static void main(String[] args) {
        menu();
    }

    private static void menu() {
        
        createLists("Urunler.txt", "UrunGrubu.txt");
        
        printEveryList();
        
        while (true) {
            System.out.println("1: StokMiktarinaGoreUrunFiyatlariGuncelle\n" +
                               "2: UrunZamYap\n" +
                               "3. IcecekStoklariniGuncelle\n" +
                               "4. CesniBirimAgirlikGuncelle\n" +
                               "5. SekerlemeDetayEkle\n" +
                               "6. SutUrunleriniSil\n"+
                               "7. TahilUrunEkle\n" +
                               "8. Çıkış");
            
            Scanner scanner = new Scanner(System.in);
            int choice; 
            
            try {
                choice = scanner.nextInt();
            }
            catch (Exception e) {
                System.out.println("Lütfen bir sayı girin.");
                continue;
            }
            
            switch (choice) {
                case 1: {    // Update product prices based on stock amount
                    System.out.println("Stok miktarı girin: ");
                    int inputStock = scanner.nextInt();
                    System.out.print("Güncel fiyat girin: ");
                    int inputUpdatedPrice = scanner.nextInt();
                    
                    Product_2215.updateProductPricesBasedOnStock(inputStock, inputUpdatedPrice);
                    
                    printEveryList();
                    break;
                }
                case 2: {    // Increase price
                    System.out.println("X girin: ");
                    int inputX = scanner.nextInt();
                    
                    Product_2215.increaseLowestPrice(inputX);
                    
                    printEveryList();
                    break;
                }
                case 3: {    // Update beverages' stock
                    System.out.println("Miktar girin: ");
                    int inputAmount = scanner.nextInt();
                    
                    Beverages_2215.updateAllBeverageStocks(inputAmount);
                    
                    Beverages_2215.printList();
                    break;
                }
                case 4: {    // Update condiments's unit weight
                    System.out.println("N girin: ");
                    int inputN = scanner.nextInt();
                    
                    scanner.nextLine();
                    
                    System.out.print("Yeni birim ağırlık girin: ");
                    String inputWeight = scanner.nextLine();
                    
                    Condiments_2215.updateCondimentsUnitWeight(inputN, inputWeight);
                    
                    Condiments_2215.printList();
                    break;
                }
                case 5: {    // Add confection detail
                    scanner.nextLine();
                    
                    System.out.println("Aranacak ürünün ismini girin: ");
                    String inputName = scanner.nextLine();
                    System.out.print("Yeni detay girin: ");
                    String inputDetail = scanner.nextLine();
                    
                    Confections_2215.addConfectionDetail(inputName, inputDetail);
                    break;
                }
                case 6: {    // Remove dairy product
                    System.out.println("Min fiyat girin: ");
                    int inputMin = scanner.nextInt();
                    System.out.print("Max fiyat girin: ");
                    int inputMax = scanner.nextInt();
                    
                    DairyProducts_2215.removeDairyProduct(inputMin, inputMax);
                    DairyProducts_2215.printList();
                    break;
                }
                case 7: {    // Add new cereal product
                    scanner.nextLine();
                    
                    System.out.println("Ürünün ismini girin: ");
                    String inputName = scanner.nextLine();
                    
                    System.out.println("Birim ağırlığı girin: ");
                    String inputWeight = scanner.nextLine();
                    
                    System.out.println("Fiyat girin: ");
                    double inputPrice = scanner.nextDouble();
                    
                    System.out.println("Stok girin: ");
                    int inputStock = scanner.nextInt();
                    
                    Cereals_2215.addNewCerealProduct(inputName, inputWeight, inputPrice, inputStock);
                    
                    Cereals_2215.printList();
                    break;
                }
                case 8: {    // Exit
                    return;
                }
                default: {
                    System.out.println("Menüde olmayan bir sayı girildi.");
                    break;
                }
            }
		}
	}

    private static void createLists(String productFile, String categoryFile) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(productFile));
            br.readLine();    // Read the title row
            
            while (true) {
                String line = br.readLine();
                
                if (line == null) {
                    break;
                }
                
                String[] attributes = line.split("\t");    // 0: Name, 1: CategoryIndex, 2: UnitWeight, 3: UnitPrice, 4: Stock
                
                // Figure out the category
                String categoryName = readCategoryName(Integer.parseInt(attributes[1]), categoryFile);
                String categoryDetails = readCategoryDetails(Integer.parseInt(attributes[1]), categoryFile);
                
                // Addition to the list
                if (categoryName.equals("Beverages")) {
                    Main_2215.beverageList.add(new Beverages_2215(attributes[0],
                            Integer.parseInt(attributes[1]),
                            attributes[2],
                            Double.parseDouble(attributes[3]),
                            Integer.parseInt(attributes[4]),
                            categoryName,
                            categoryDetails));
                }
                else if (categoryName.equals("Condiments") ) {
                    Main_2215.condimentList.add(new Condiments_2215(attributes[0],
                            Integer.parseInt(attributes[1]),
                            attributes[2],
                            Double.parseDouble(attributes[3]),
                            Integer.parseInt(attributes[4]),
                            categoryName,
                            categoryDetails));
                }
                else if (categoryName.equals("Confections") ) {
                    Main_2215.confectionList.add(new Confections_2215(attributes[0],
                            Integer.parseInt(attributes[1]),
                            attributes[2],
                            Double.parseDouble(attributes[3]),
                            Integer.parseInt(attributes[4]),
                            categoryName,
                            categoryDetails));
                }
                else if (categoryName.equals("Dairy Products") ) {
                    Main_2215.dairyProductList.add(new DairyProducts_2215(attributes[0],
                            Integer.parseInt(attributes[1]),
                            attributes[2],
                            Double.parseDouble(attributes[3]),
                            Integer.parseInt(attributes[4]),
                            categoryName,
                            categoryDetails));
                }
                else {
                    Main_2215.cerealList.add(new Cereals_2215(attributes[0],
                            Integer.parseInt(attributes[1]),
                            attributes[2],
                            Double.parseDouble(attributes[3]),
                            Integer.parseInt(attributes[4]),
                            categoryName,
                            categoryDetails));
                }
                
            }
            br.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static String readCategoryName(int index, String categoryFile) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(categoryFile));
            br.readLine();    // Read the title row
            
            while (true) {
                String line = br.readLine();
                
                if (line == null) {
                    break;
                }
                
                String[] attributes = line.split("\t");    // 0: CategoryIndex, 1: Name, 2: Details
                
                if (Integer.parseInt(attributes[0]) == index) {
                    br.close();
                    return attributes[1];
                }
            }
            br.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        
        return "Kategori bulunamadı.";
    }

    public static String readCategoryDetails(int index, String categoryFile) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(categoryFile));
            br.readLine();    // Read the title row
            
            while (true) {
                String line = br.readLine();
                
                if (line == null) {
                    break;
                }
                
                String[] attributes = line.split("\t");    // 0: CategoryIndex, 1: Name, 2: Details
                
                if (Integer.parseInt(attributes[0]) == index) {
                    br.close();
                    return attributes[2];
                }
            }
            br.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        
        return "Kategori bulunamadı.";
    }
    
    public static void printEveryList() {
        Beverages_2215.printList();
        System.out.println();
        Condiments_2215.printList();
        System.out.println();
        Confections_2215.printList();
        System.out.println();
        DairyProducts_2215.printList();
        System.out.println();
        Cereals_2215.printList();
        System.out.println();
        
    }
    
    
}

//Product_2215
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

    
    public static void updateProductPricesBasedOnStock(int thresholdStock, int updatedPrice) {
        for (Beverages_2215 p : Main_2215.beverageList) {
            if (p.getStock() < thresholdStock) {
                p.setUnitPrice(updatedPrice * (1 + (50 - p.getStock()) / 100f));
            }
        }
        
        for (Condiments_2215 p : Main_2215.condimentList) {
            if (p.getStock() < thresholdStock) {
                p.setUnitPrice(updatedPrice * (1 + (50 - p.getStock()) / 100f));
            }
        }
        
        for (Confections_2215 p : Main_2215.confectionList) {
            if (p.getStock() < thresholdStock) {
                p.setUnitPrice(updatedPrice * (1 + (50 - p.getStock()) / 100f));
            }
        }
        
        for (DairyProducts_2215 p : Main_2215.dairyProductList) {
            if (p.getStock() < thresholdStock) {
                p.setUnitPrice(updatedPrice * (1 + (50 - p.getStock()) / 100f));
            }
        }
        
        for (Cereals_2215 p : Main_2215.cerealList) {
            if (p.getStock() < thresholdStock) {
                p.setUnitPrice(updatedPrice * (1 + (50 - p.getStock()) / 100f));
            }
        }
        
    }

    public static void increaseLowestPrice(int x) {
        
        Product_2215 lowestPricedProduct = null;
        
        for (Beverages_2215 p : Main_2215.beverageList) {
            if (lowestPricedProduct == null || p.getUnitPrice() < lowestPricedProduct.getUnitPrice()) {
                lowestPricedProduct = p;
            }
        }
        
        for (Condiments_2215 p : Main_2215.condimentList) {
            if (lowestPricedProduct == null || p.getUnitPrice() < lowestPricedProduct.getUnitPrice()) {
                lowestPricedProduct = p;
            }
        }
        
        for (Confections_2215 p : Main_2215.confectionList) {
            if (lowestPricedProduct == null || p.getUnitPrice() < lowestPricedProduct.getUnitPrice()) {
                lowestPricedProduct = p;
            }
        }
        
        for (DairyProducts_2215 p : Main_2215.dairyProductList) {
            if (lowestPricedProduct == null || p.getUnitPrice() < lowestPricedProduct.getUnitPrice()) {
                lowestPricedProduct = p;
            }
        }
        
        for (Cereals_2215 p : Main_2215.cerealList) {
            if (lowestPricedProduct == null || p.getUnitPrice() < lowestPricedProduct.getUnitPrice()) {
                lowestPricedProduct = p;
            }
        }
        
        lowestPricedProduct.setUnitPrice(lowestPricedProduct.getUnitPrice() * (100 + x) / 100);
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
import java.util.ArrayList;

public class Beverages_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    
    public Beverages_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }


    public static void updateAllBeverageStocks(int amount) {
        for (Beverages_2215 p : Main_2215.beverageList) {
            if (p.getStock() + amount < 0) {
                p.setStock(0);
            }
            else {
                p.setStock(p.getStock() + amount);
            }
        }
    }
    
    public static void printList() {
        System.out.println("Beverages");
        
        if (Main_2215.beverageList.size() < 1) {
            System.out.println("Liste boş.");
            return;
        }
        
        System.out.println(String.format("%-36s %-8s %-26s %-10s %-10s", "İsim", "K. Index", "Br. Ağr.", "Br. Fyt.", "Stok"));
        
        for (Beverages_2215 p : Main_2215.beverageList) {
            System.out.println(String.format("%-36s %-8d %-26s %-10.2f %-10d", p.getName(), p.getCategoryIndex(), p.getUnitWeight(), p.getUnitPrice(), p.getStock()));
        }
    }
    
    
    // Getters and Setters
    
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
public class Condiments_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    
    public Condiments_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }


    public static void updateCondimentsUnitWeight(int n, String newUnitWeight) {
        if (n > Main_2215.condimentList.size() ) {
            System.out.println(n + ". ürün listede bulunamadı. (Listede sadece " + Main_2215.condimentList.size() + " eleman var.)");
            return;
        }
        
        Main_2215.condimentList.get(n - 1).setUnitWeight(newUnitWeight);
    }
    
    public static void printList() {
        System.out.println("Condiments");
        
        if (Main_2215.condimentList.size() < 1) {
            System.out.println("Liste boş.");
            return;
        }
        
        System.out.println(String.format("%-36s %-8s %-26s %-10s %-10s", "İsim", "K. Index", "Br. Ağr.", "Br. Fyt.", "Stok"));
        
        for (Condiments_2215 p : Main_2215.condimentList) {
            System.out.println(String.format("%-36s %-8d %-26s %-10.2f %-10d", p.getName(), p.getCategoryIndex(), p.getUnitWeight(), p.getUnitPrice(), p.getStock()));
        }
    }
    
    
    // Getters and Setters
    
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
public class Confections_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    
    public Confections_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }


    public static void addConfectionDetail(String name, String newDetail) {
        for (Confections_2215 p : Main_2215.confectionList) {
            if (p.getName().toLowerCase().equals(name.toLowerCase())) {
                p.setDetails(p.getDetails() + ", " + newDetail);
                printProductDetails();
                return;
            }
        }
    }
    
    
    private static void printProductDetails() {
        System.out.println(String.format("%-36s %s", "İsim", "Detay"));
        for (Confections_2215 p : Main_2215.confectionList) {
            System.out.println(String.format("%-36s %s", p.getName(), p.details));
        }
    }
    
    
    public static void printList() {
        System.out.println("Confections");
        
        if (Main_2215.confectionList.size() < 1) {
            System.out.println("Liste boş.");
            return;
        }
        
        System.out.println(String.format("%-36s %-8s %-26s %-10s %-10s", "İsim", "K. Index", "Br. Ağr.", "Br. Fyt.", "Stok"));
        
        for (Confections_2215 p : Main_2215.confectionList) {
            System.out.println(String.format("%-36s %-8d %-26s %-10.2f %-10d", p.getName(), p.getCategoryIndex(), p.getUnitWeight(), p.getUnitPrice(), p.getStock()));
        }
    }
    
    
    
    // Getters and Setters
    
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
public class DairyProducts_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    
    public DairyProducts_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }


    public static void removeDairyProduct(int minPrice, int maxPrice) {
        for (int i = Main_2215.dairyProductList.size() - 1; i >= 0; i--) {
            DairyProducts_2215 p = Main_2215.dairyProductList.get(i);
            
            if (p.getUnitPrice() > minPrice && p.getUnitPrice() < maxPrice) {
                Main_2215.dairyProductList.remove(i);
            }
        }
    }
    
    public static void printList() {
        System.out.println("Dairy Products");
        
        if (Main_2215.dairyProductList.size() < 1) {
            System.out.println("Liste boş.");
            return;
        }
        
        System.out.println(String.format("%-36s %-8s %-26s %-10s %-10s", "İsim", "K. Index", "Br. Ağr.", "Br. Fyt.", "Stok"));
        
        for (DairyProducts_2215 p : Main_2215.dairyProductList) {
            System.out.println(String.format("%-36s %-8d %-26s %-10.2f %-10d", p.getName(), p.getCategoryIndex(), p.getUnitWeight(), p.getUnitPrice(), p.getStock()));
        }
    }
    
    
    // Getters and Setters
    
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
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Cereals_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    
    public Cereals_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }


    public static void addNewCerealProduct(String name, String unitWeight, double unitPrice, int stock) {
        int cIndex = findCategoryIndex("UrunGrubu.txt");
        Main_2215.cerealList.add(new Cereals_2215(name, cIndex, unitWeight, unitPrice, stock, Main_2215.readCategoryName(cIndex, "UrunGrubu.txt"), unitWeight));
    }
    
    
    private static int findCategoryIndex(String categoryFile) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(categoryFile));
            br.readLine();    // Read the title row
            
            while (true) {
                String line = br.readLine();
                
                if (line == null) {
                    break;
                }
                
                String[] attributes = line.split("\t");    // 0: CategoryIndex, 1: Name, 2: Details
                
                if (attributes[1].toLowerCase().contains("cereal")) {
                    br.close();
                    return Integer.parseInt(attributes[0]);
                }
            }
            br.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        
        return -1;
    }
    
    public static void printList() {
        System.out.println("Cereals");
        
        if (Main_2215.cerealList.size() < 1) {
            System.out.println("Liste boş.");
            return;
        }
        
        System.out.println(String.format("%-36s %-8s %-26s %-10s %-10s", "İsim", "K. Index", "Br. Ağr.", "Br. Fyt.", "Stok"));
        
        for (Cereals_2215 p : Main_2215.cerealList) {
            System.out.println(String.format("%-36s %-8d %-26s %-10.2f %-10d", p.getName(), p.getCategoryIndex(), p.getUnitWeight(), p.getUnitPrice(), p.getStock()));
        }
    }
    
    
    
    // Getters and Setters
    
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
