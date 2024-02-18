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
