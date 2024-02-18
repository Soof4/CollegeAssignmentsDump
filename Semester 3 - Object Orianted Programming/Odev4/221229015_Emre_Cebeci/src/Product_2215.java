
public class Product_2215 {
    private String name;
    private int categoryIndex;
    private String unitWeight;
    private double unitPrice;
    private int stock;
    
    
    public Product_2215(String name, int categoryIndex, String unitWeight, double unitPrice, int stock) {
        super();
        this.name = name;
        this.categoryIndex = categoryIndex;
        this.unitWeight = unitWeight;
        this.unitPrice = unitPrice;
        this.stock = stock;
    }

    
    public static void updateProductPricesBasedOnStock(int thresholdStock, int updatedPrice) {
        for (Beverages_2215 p : Main_2215.beverageList) {
            if (p.getStock() < thresholdStock) {
                p.setUnitPrice(updatedPrice * (1 + (50 - p.getStock()) / 100f));
            }
        }
        
        for (Condiments_2215 p : Main_2215.condimentList) {
            if (p.getStock() < thresholdStock) {
                p.setUnitPrice(updatedPrice * (1 + (50 - p.getStock()) / 100f));
            }
        }
        
        for (Confections_2215 p : Main_2215.confectionList) {
            if (p.getStock() < thresholdStock) {
                p.setUnitPrice(updatedPrice * (1 + (50 - p.getStock()) / 100f));
            }
        }
        
        for (DairyProducts_2215 p : Main_2215.dairyProductList) {
            if (p.getStock() < thresholdStock) {
                p.setUnitPrice(updatedPrice * (1 + (50 - p.getStock()) / 100f));
            }
        }
        
        for (Cereals_2215 p : Main_2215.cerealList) {
            if (p.getStock() < thresholdStock) {
                p.setUnitPrice(updatedPrice * (1 + (50 - p.getStock()) / 100f));
            }
        }
        
    }

    public static void increaseLowestPrice(int x) {
        
        Product_2215 lowestPricedProduct = null;
        
        for (Beverages_2215 p : Main_2215.beverageList) {
            if (lowestPricedProduct == null || p.getUnitPrice() < lowestPricedProduct.getUnitPrice()) {
                lowestPricedProduct = p;
            }
        }
        
        for (Condiments_2215 p : Main_2215.condimentList) {
            if (lowestPricedProduct == null || p.getUnitPrice() < lowestPricedProduct.getUnitPrice()) {
                lowestPricedProduct = p;
            }
        }
        
        for (Confections_2215 p : Main_2215.confectionList) {
            if (lowestPricedProduct == null || p.getUnitPrice() < lowestPricedProduct.getUnitPrice()) {
                lowestPricedProduct = p;
            }
        }
        
        for (DairyProducts_2215 p : Main_2215.dairyProductList) {
            if (lowestPricedProduct == null || p.getUnitPrice() < lowestPricedProduct.getUnitPrice()) {
                lowestPricedProduct = p;
            }
        }
        
        for (Cereals_2215 p : Main_2215.cerealList) {
            if (lowestPricedProduct == null || p.getUnitPrice() < lowestPricedProduct.getUnitPrice()) {
                lowestPricedProduct = p;
            }
        }
        
        lowestPricedProduct.setUnitPrice(lowestPricedProduct.getUnitPrice() * (100 + x) / 100);
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

    public String getUnitWeight() {
        return unitWeight;
    }

    public void setUnitWeight(String unitWeight) {
        this.unitWeight = unitWeight;
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
