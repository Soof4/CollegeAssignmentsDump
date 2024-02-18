
public class Confections_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    public Confections_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }

    
    public static Product_2215 findProductByName(String name) {
        name = name.toLowerCase();
        
        for (Product_2215 p : Main_2215.confectionList) {
            if (p.getName().toLowerCase().equals(name)) {
                return p;
            }
        }
        
        return null;
    }
    
    @Override
    public void updateStock(int stock, boolean isAdd) {
        if (this.getStock() > 10 && !isAdd || this.getStock() < 20 && isAdd) {
            super.updateStock(stock, isAdd);
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
