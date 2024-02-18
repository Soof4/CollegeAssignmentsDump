
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
