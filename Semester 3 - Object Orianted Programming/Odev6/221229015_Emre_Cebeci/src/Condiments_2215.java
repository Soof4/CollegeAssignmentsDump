
public class Condiments_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    public Condiments_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }

    
    public static void updateUnitWeight(String weight) {
        Condiments_2215 targetC = null;
        for (Condiments_2215 c : Main_2215.condimentList) {
            if (targetC == null || c.getStock() > targetC.getStock()) {
                targetC = c;
            }
        }
        
        if (targetC == null) {
            System.out.println("Condiments listesi bos.");
            return;
        }
        
        targetC.setUntiWeight(weight);
    }
    
    public static void updateUnitWeight(String weight, int stock) {
        Condiments_2215 targetC = null; 
        
        for (Condiments_2215 c: Main_2215.condimentList) {
            if (targetC == null || Math.abs(stock - c.getStock()) < Math.abs(stock - targetC.getStock())) {
                targetC = c;
            }
        }
        
        if (targetC == null) {
            System.out.println("Condiments listesi bos.");
            return;
        }
        
        targetC.setUntiWeight(weight);
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
