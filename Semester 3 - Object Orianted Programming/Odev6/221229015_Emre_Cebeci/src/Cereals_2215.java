
public class Cereals_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    public Cereals_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }

    
    public static void addNewCerealProduct(String name, double price, int stock) {
        Main_2215.cerealList.add(new Cereals_2215(name, 5, "10", price, stock, Main_2215.getCategoryInfo(5)[1], Main_2215.getCategoryInfo(5)[2]));
    }
    
    public static void addNewCerealProduct(String name, String weight, double price, String details) {
        Main_2215.cerealList.add(new Cereals_2215(name, 5, weight, price, 20, Main_2215.getCategoryInfo(5)[1], details));
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
