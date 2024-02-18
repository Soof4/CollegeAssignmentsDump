package package2;

public class Cereals_2215 extends Product_2215 {
    private static String categoryName;
    private static String details;
    
    public Cereals_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
    }
    
    protected static void HububatSil(String productName) {
        for (Cereals_2215 c : Main_2215.cerealList) {
            if (c.getName().toLowerCase().equals(productName.toLowerCase())) {
                Main_2215.cerealList.remove(c);
                break;
            }
        }
    }
    
    
    // Getters and Setters
    public static String getCategoryName() {
        return categoryName;
    }

    public static void setCategoryName(String newCategoryName) {
        categoryName = newCategoryName;
    }

    public static String getDetails() {
        return details;
    }

    public static void setDetails(String newDetails) {
        details = newDetails;
    }
}
