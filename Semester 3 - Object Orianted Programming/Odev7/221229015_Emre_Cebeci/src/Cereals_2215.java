import java.util.ArrayList;

public class Cereals_2215 extends Product_2215 {
    private static final int coefficient = 5;
    private String categoryName;
    private String details;
    

    public Cereals_2215(String name, int categoryIndex, String weight, double price, int stock, String categoryName,
            String details) {
        super(name, categoryIndex, weight, price, stock);
        this.categoryName = categoryName;
        this.details = details;
    }
    
        
    @Override
    public void updateProductStock(int amount, boolean isAdd) {
        amount += coefficient;
        
        if (isAdd) {
            this.setStock(this.getStock() + amount);
        }
        else {
            this.setStock(this.getStock() - amount);
        }
        
    }

    @Override
    public void updateProductName(String newName, String newDetails) {
        this.setName(newName);
        this.setDetails(this.getDetails() + ", " + newDetails);
    }
    
    @Override
    public void removeProduct(ArrayList<? extends Product_2215> list) {
        list.remove(this);
    }
    
    @Override
    public void addNewProduct(String name, String weight, double price, int stock, String details) {
        switch (this.getCategoryIndex()) {
            case 1: {
                Main_2215.beverageList.add(new Beverages_2215(name, 1, weight, price, stock, "Beverages", details));
                break;
            }
            case 2: {
                Main_2215.condimentList.add(new Condiments_2215(name, 2, weight, price, stock, "Condiments", details));
                break;
            }
            case 3: {
                Main_2215.confectionList.add(new Confections_2215(name, 3, weight, price, stock, "Confections", details));
                break;
            }
            case 4: {
                Main_2215.dairyList.add(new DairyProducts_2215(name, 4, weight, price, stock, "Dairy Products", details));
                break;
            }
            case 5: {
                Main_2215.cerealList.add(new Cereals_2215(name, 5, weight, price, stock, "Grains/Cereals", details));
                break;
            }
        }
    }
    
    
    // Getters and Setters

    public static int getCoefficient() {
        return coefficient;
    }
    
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
