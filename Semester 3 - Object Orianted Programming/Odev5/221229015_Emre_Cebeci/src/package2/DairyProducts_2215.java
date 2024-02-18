package package2;

public class DairyProducts_2215 extends Product_2215 {
    public static String categoryName;
    public static String details;
    
    public DairyProducts_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
    }
    
    protected static void SutUrunleriDetayEkle(String newDetail) {
        details += ", " + newDetail;
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
