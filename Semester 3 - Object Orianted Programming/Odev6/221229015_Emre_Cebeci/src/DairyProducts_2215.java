
public class DairyProducts_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    public DairyProducts_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }

    
    public static void removeDairyProduct() {
        DairyProducts_2215 targetD = null;
        
        for (DairyProducts_2215 d : Main_2215.dairyList) {
            if (targetD == null || d.getStock() < targetD.getStock()) {
                targetD = d;
            }
        }
        
        if (targetD == null) {
            System.out.println("Sut urunleri listesi bos.");
            return;
        }
        
        Main_2215.dairyList.remove(targetD);
    }
    
    public static void removeDairyProduct(int min, int max, double price) {
        for (int i = Main_2215.dairyList.size() - 1; i > -1; i--) {
            DairyProducts_2215 d = Main_2215.dairyList.get(i);
            
            if (d.getStock() >= min && d.getStock() <= max && d.getUnitPrice() < price) {
                Main_2215.dairyList.remove(i);
            }
        }
    }
    
    public static void removeDairyProduct(double price) {
        for (int i = Main_2215.dairyList.size() - 1; i > -1; i--) {
            if (Main_2215.dairyList.get(i).getUnitPrice() < price) {
                Main_2215.dairyList.remove(i);
            }
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
