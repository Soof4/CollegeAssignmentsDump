import java.util.ArrayList;
import java.io.Serializable;

public abstract class Product_2215 implements IProduct_2215, Serializable {
    private String name;
    private int categoryIndex;
    private String weight;
    private double price;
    private int stock;
    
    
    public Product_2215(String name, int categoryIndex, String weight, double price, int stock) {
        this.name = name;
        this.categoryIndex = categoryIndex;
        this.weight = weight;
        this.price = price;
        this.stock = stock;
    }
    
    
    public void updateProductPrice(int ratio, boolean isSale, int coefficient) {
        ratio += coefficient;
        
        if (isSale) {
            this.price *= (100.0 - ratio) / 100.0;
        }
        else {
            this.price *= (100.0 + ratio) / 100.0;
        }
    }
    
    public static void raisePriceByCategory(int x, ArrayList<? extends Product_2215> list, int coefficient) {
        x += coefficient;
        
        for (Product_2215 p : list) {
            p.setPrice(p.getPrice() * (100.0 + x) / 100.0);
        }
    }
    
    
    // Getters and Setters
    public String getName() {
        return name;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public int getCategoryIndex() {
        return categoryIndex;
    }
    
    public void setCategoryIndex(int categoryIndex) {
        this.categoryIndex = categoryIndex;
    }
    
    public String getWeight() {
        return weight;
    }
    
    public void setWeight(String weight) {
        this.weight = weight;
    }
    
    public double getPrice() {
        return price;
    }
    
    public void setPrice(double price) {
        this.price = price;
    }
    
    public int getStock() {
        return stock;
    }
    
    public void setStock(int stock) {
        this.stock = stock;
    }    
}
