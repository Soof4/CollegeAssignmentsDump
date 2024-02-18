package package2;


public class Confections_2215 extends Product_2215 {
    private static String categoryName;
    private static String details;
    
    public Confections_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
    }
    
    protected static void SekerlemeUrunEkle(String name, String unitWeight, double unitPrice, int stock) {
        Main_2215.confectionList.add(new Confections_2215(name, 3,
                unitWeight, unitPrice, stock));
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
