import java.util.ArrayList;
import java.util.Iterator;

public class Product_2215 {
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

    
    public static void updateProductStock(String productName, boolean isAdd) {
        productName = productName.toLowerCase();
        Product_2215 tp = null;
        
        for (ArrayList<Product_2215> l : Main_2215.allProductsList) {
            for (Product_2215 p : l) {
                if (p.name.toLowerCase().equals(productName)) {
                    tp = p;
                    break;
                }
            }
            
            if (tp != null) {
                break;
            }
        }
        
        if (isAdd) {
            tp.stock += tp.stock / 2;
        }
        else {
            tp.stock -= tp.stock / 2;
        }
    }
    
    public static void lowerPricesBasedOnProductCategory(String categoryName, int x) {
        for (ArrayList<Product_2215> l : Main_2215.allProductsList) {
            if (l.size() > 0 && l.get(0)) {
                
            }
        }
    }
    
    public static double getCategoryPriceMean(ArrayList<Product_2215> list) {
        double sum = 0;
        
        for (Product_2215 p : list) {
            sum += p.price;
        }
        
        return sum / list.size();
    }
    
    
    // Nested Classes
    
    public static class Beverages_2215 extends Product_2215 {
        private String categoryName;
        private String details;
        
        
        public Beverages_2215(String name, int categoryIndex, String weight, double price, int stock,
                String categoryName, String details) {
            super(name, categoryIndex, weight, price, stock);
            this.categoryName = categoryName;
            this.details = details;
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
    
    public static class Condiments_2215 extends Product_2215 {
        private String categoryName;
        private String details;
        
        
        public Condiments_2215(String name, int categoryIndex, String weight, double price, int stock,
                String categoryName, String details) {
            super(name, categoryIndex, weight, price, stock);
            this.categoryName = categoryName;
            this.details = details;
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
    
    public static class Confections_2215 extends Product_2215 {
        private String categoryName;
        private String details;
        
        
        public Confections_2215(String name, int categoryIndex, String weight, double price, int stock,
                String categoryName, String details) {
            super(name, categoryIndex, weight, price, stock);
            this.categoryName = categoryName;
            this.details = details;
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
    
    public static class DairyProducts_2215 extends Product_2215 {
        private String categoryName;
        private String details;
        
        
        public DairyProducts_2215(String name, int categoryIndex, String weight, double price, int stock,
                String categoryName, String details) {
            super(name, categoryIndex, weight, price, stock);
            this.categoryName = categoryName;
            this.details = details;
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
    
    public static class Cereals_2215 extends Product_2215 {
        private String categoryName;
        private String details;
        
        
        public Cereals_2215(String name, int categoryIndex, String weight, double price, int stock, String categoryName,
                String details) {
            super(name, categoryIndex, weight, price, stock);
            this.categoryName = categoryName;
            this.details = details;
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
