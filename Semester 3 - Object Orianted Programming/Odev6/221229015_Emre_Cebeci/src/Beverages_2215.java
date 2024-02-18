
public class Beverages_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    
    public Beverages_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }

    
    public static Product_2215 findProductByName(String name) {
        name = name.toLowerCase();
        
        for (Product_2215 p : Main_2215.beverageList) {
            if (p.getName().toLowerCase().equals(name)) {
                return p;
            }
        }
        
        return null;
    }
    
    @Override
    public void updatePrice(int ratio) {
        if (this.getStock() < 20) {
            super.updatePrice(ratio / 2);
        }
        else if (this.getStock() < 50) {
            super.updatePrice(ratio);
        }
        else {
            super.updatePrice(ratio * ratio);
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
