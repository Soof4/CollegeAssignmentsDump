
public class Product_2215 {
    private String name;
    private int categoryIndex;
    private String unitWeight;
    private double unitPrice;
    private int stock;
    
    
    public Product_2215(String name, int categoryIndex, String untiWeight, double unitPrice, int stock) {
        this.name = name;
        this.categoryIndex = categoryIndex;
        this.unitWeight = untiWeight;
        this.unitPrice = unitPrice;
        this.stock = stock;
    }

    public static Product_2215 findProductByName(String name) {
        name = name.toLowerCase();
        
        for (Product_2215 p : Main_2215.beverageList) {
            if (p.name.toLowerCase().equals(name)) {
                return p;
            }
        }
        
        for (Product_2215 p : Main_2215.condimentList) {
            if (p.name.toLowerCase().equals(name)) {
                return p;
            }
        }
        
        for (Product_2215 p : Main_2215.confectionList) {
            if (p.name.toLowerCase().equals(name)) {
                return p;
            }
        }
        
        for (Product_2215 p : Main_2215.dairyList) {
            if (p.name.toLowerCase().equals(name)) {
                return p;
            }
        }
        
        for (Product_2215 p : Main_2215.cerealList) {
            if (p.name.toLowerCase().equals(name)) {
                return p;
            }
        }
        
        return null;
    }
    
    public void updatePrice(int ratio) {
        this.unitPrice = this.unitPrice * (100.0 + ratio) / 100.0;
    }
    
    public void updatePrice(int ratio, int stock) {
        if (stock > this.stock) {
            this.unitPrice = this.unitPrice * (100.0 + ratio) / 100.0;
        }
    }
    
    public void updateStock(int stock, boolean isAdd) {
        if (isAdd) {
            this.stock += stock;
        }
        else {
            this.stock -= stock;
        }
    }
    
    public static void raisePricesbyCategory(String catName) {
        if (catName.toLowerCase().contains("beverage")) {
            for (Product_2215 p : Main_2215.beverageList) {
                if (p.stock > 10) { 
                    p.updatePrice(p.getName().length());
                }
            }
        }
        else if (catName.toLowerCase().contains("condiment")) {
            for (Product_2215 p : Main_2215.condimentList) {
                if (p.stock > 10) { 
                    p.updatePrice(p.getName().length());
                }
            }
        }
        else if (catName.toLowerCase().contains("confection")) {
            for (Product_2215 p : Main_2215.confectionList) {
                if (p.stock > 10) { 
                    p.updatePrice(p.getName().length());
                }
            }
        }
        else if (catName.toLowerCase().contains("dairy")) {
            for (Product_2215 p : Main_2215.dairyList) {
                if (p.stock > 10) { 
                    p.updatePrice(p.getName().length());
                }
            }
        }
        else if (catName.toLowerCase().contains("cereal")) {
            for (Product_2215 p : Main_2215.cerealList) {
                if (p.stock > 10) { 
                    p.updatePrice(p.getName().length());
                }
            }
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
    
    public String getUntiWeight() {
        return unitWeight;
    }
    
    public void setUntiWeight(String untiWeight) {
        this.unitWeight = untiWeight;
    }
    
    public double getUnitPrice() {
        return unitPrice;
    }
    
    public void setUnitPrice(double unitPrice) {
        this.unitPrice = unitPrice;
    }
    
    public int getStock() {
        return stock;
    }
    
    public void setStock(int stock) {
        this.stock = stock;
    }
}
