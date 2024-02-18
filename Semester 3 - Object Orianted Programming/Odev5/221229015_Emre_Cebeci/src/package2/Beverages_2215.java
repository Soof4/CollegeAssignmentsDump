package package2;

public class Beverages_2215 extends Product_2215 {
    private static String categoryName;
    private static String details;
    
    public Beverages_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
    }
    
    protected static void IcecekBirimAgirlikGuncelle(String newWeight) {
        if (Main_2215.beverageList.isEmpty()) {
            System.out.println("Içecek listesi boş.");
            return;
        }
        
        Main_2215.beverageList.get(Main_2215.beverageList.size() - 1).setUnitWeight(newWeight);
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
