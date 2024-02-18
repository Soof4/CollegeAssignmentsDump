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
