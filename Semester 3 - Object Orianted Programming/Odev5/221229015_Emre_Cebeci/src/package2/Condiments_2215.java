package package2;

import java.util.Scanner;

public class Condiments_2215 extends Product_2215 {
    private static String categoryName;
    private static String details;
    
    public Condiments_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
    }
    
    protected static void CesniStokGuncelle(boolean isSell, int amount) {
        System.out.println("İşlem yapılacak olan çeşni'nin index'ini giriniz.");
        Scanner scanner = new Scanner(System.in);
        int targetIndex = scanner.nextInt();
        
        if (targetIndex >= Main_2215.condimentList.size() || targetIndex < 0) {
            System.out.println("Girilen index çeşni listesinin dışında. İşlem iptal edildi.");
            return;
        }
        
        Condiments_2215 targetCondiment = Main_2215.condimentList.get(targetIndex);

        if (isSell) {
            if (targetCondiment.getStock() < amount) {    // Negative check
                amount = targetCondiment.getStock();
            }
            amount *= -1;
        }
        
        targetCondiment.setStock(targetCondiment.getStock() + amount);
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
