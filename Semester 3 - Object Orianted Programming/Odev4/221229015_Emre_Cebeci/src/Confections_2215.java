
public class Confections_2215 extends Product_2215 {
    private String categoryName;
    private String details;
    
    
    public Confections_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock,
            String categoryName, String details) {
        super(name, categoryIndex, unitWeight, unitPrice, stock);
        this.categoryName = categoryName;
        this.details = details;
    }


    public static void addConfectionDetail(String name, String newDetail) {
        for (Confections_2215 p : Main_2215.confectionList) {
            if (p.getName().toLowerCase().equals(name.toLowerCase())) {
                p.setDetails(p.getDetails() + ", " + newDetail);
                printProductDetails();
                return;
            }
        }
    }
    
    
    private static void printProductDetails() {
        System.out.println(String.format("%-36s %s", "İsim", "Detay"));
        for (Confections_2215 p : Main_2215.confectionList) {
            System.out.println(String.format("%-36s %s", p.getName(), p.details));
        }
    }
    
    
    public static void printList() {
        System.out.println("Confections");
        
        if (Main_2215.confectionList.size() < 1) {
            System.out.println("Liste boş.");
            return;
        }
        
        System.out.println(String.format("%-36s %-8s %-26s %-10s %-10s", "İsim", "K. Index", "Br. Ağr.", "Br. Fyt.", "Stok"));
        
        for (Confections_2215 p : Main_2215.confectionList) {
            System.out.println(String.format("%-36s %-8d %-26s %-10.2f %-10d", p.getName(), p.getCategoryIndex(), p.getUnitWeight(), p.getUnitPrice(), p.getStock()));
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
