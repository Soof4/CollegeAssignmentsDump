package package2;

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

    protected static void UrunleriFiyataGoreSil(double minPrice, double maxPrice) {
        for (int i = Main_2215.beverageList.size() - 1; i > -1; i--) {
            Product_2215 p = Main_2215.beverageList.get(i);
            if (p.getUnitPrice() < maxPrice && p.getUnitPrice() > minPrice) {
                Main_2215.beverageList.remove(i);
            }
        }
        
        for (int i = Main_2215.condimentList.size() - 1; i > -1; i--) {
            Product_2215 p = Main_2215.condimentList.get(i);
            if (p.getUnitPrice() < maxPrice && p.getUnitPrice() > minPrice) {
                Main_2215.condimentList.remove(i);
            }
        }
        
        
        for (int i = Main_2215.confectionList.size() - 1; i > -1; i--) {
            Product_2215 p = Main_2215.confectionList.get(i);
            if (p.getUnitPrice() < maxPrice && p.getUnitPrice() > minPrice) {
                Main_2215.confectionList.remove(i);
            }
        }
        
        for (int i = Main_2215.dairyProductList.size() - 1; i > -1; i--) {
            Product_2215 p = Main_2215.dairyProductList.get(i);
            if (p.getUnitPrice() < maxPrice && p.getUnitPrice() > minPrice) {
                Main_2215.dairyProductList.remove(i);
            }
        }
        
        for (int i = Main_2215.cerealList.size() - 1; i > -1; i--) {
            Product_2215 p = Main_2215.cerealList.get(i);
            if (p.getUnitPrice() < maxPrice && p.getUnitPrice() > minPrice) {
                Main_2215.cerealList.remove(i);
            }
        }
    }

    protected static void UrunKategoriStokGuncelle(String categoryName, int x) {
         switch (categoryName.toLowerCase().trim()) {
             case "beverages":
             case "beverage":
                 for (Product_2215 p : Main_2215.beverageList) {
                    p.setStock(p.getStock() + (int)(p.getStock() * (x / 100f)));
                 }
                 break;
             case "condiments":
             case "condiment":
                 for (Product_2215 p : Main_2215.condimentList) {
                     p.setStock(p.getStock() + (int)(p.getStock() * (x / 100f)));
                  }
                 break;
             case "confections":
             case "confection":
                 for (Product_2215 p : Main_2215.confectionList) {
                     p.setStock(p.getStock() + (int)(p.getStock() * (x / 100f)));
                  }
                 break;
             case "dairyproducts":
             case "dairy products":
             case "dairyproduct":
             case "dairy product":
                 for (Product_2215 p : Main_2215.dairyProductList) {
                     p.setStock(p.getStock() + (int)(p.getStock() * (x / 100f)));
                  }
                 break;
             case "cereals":
             case "cereal":
             case "grains/cereals":
                 for (Product_2215 p : Main_2215.cerealList) {
                     p.setStock(p.getStock() + (int)(p.getStock() * (x / 100f)));
                  }
                 break;
             default:
                 System.out.println("Girilen kategori ismi bulunamadı.");
         }
    }
    
    protected static void printAllProducts() {
        System.out.println(String.format("%-34s %-14s %-30s %-12s %-12s", 
                "Adi", "KategoriIndex", "BirimAgirligi", "BirimFiyati", "StokMiktari"));
        for (Product_2215 p : Main_2215.beverageList) {
            System.out.println(String.format("%-34s %-14d %-30s %-12.2f %-12d", 
                    p.name, p.categoryIndex, p.unitWeight, p.unitPrice, p.stock));
        }
        
        for (Product_2215 p : Main_2215.condimentList) {
            System.out.println(String.format("%-34s %-14d %-30s %-12.2f %-12d", 
                    p.name, p.categoryIndex, p.unitWeight, p.unitPrice, p.stock));
        }
        
        for (Product_2215 p : Main_2215.confectionList) {
            System.out.println(String.format("%-34s %-14d %-30s %-12.2f %-12d", 
                    p.name, p.categoryIndex, p.unitWeight, p.unitPrice, p.stock));
        }
        
        for (Product_2215 p : Main_2215.dairyProductList) {
            System.out.println(String.format("%-34s %-14d %-30s %-12.2f %-12d", 
                    p.name, p.categoryIndex, p.unitWeight, p.unitPrice, p.stock));
        }
        
        for (Product_2215 p : Main_2215.cerealList) {
            System.out.println(String.format("%-34s %-14d %-30s %-12.2f %-12d", 
                    p.name, p.categoryIndex, p.unitWeight, p.unitPrice, p.stock));
        }
    }
    
    protected static void printCategories() {
        System.out.println(String.format("%-14s %-30s %-80s", "KategoriIndex", "Adi", "Detay"));
        System.out.println(String.format("%-14d %-30s %-80s", 1, Beverages_2215.getCategoryName(), Beverages_2215.getDetails()));
        System.out.println(String.format("%-14d %-30s %-80s", 2, Condiments_2215.getCategoryName(), Condiments_2215.getDetails()));
        System.out.println(String.format("%-14d %-30s %-80s", 3, Confections_2215.getCategoryName(), Confections_2215.getDetails()));
        System.out.println(String.format("%-14d %-30s %-80s", 4, DairyProducts_2215.getCategoryName(), DairyProducts_2215.getDetails()));
        System.out.println(String.format("%-14d %-30s %-80s", 5, Cereals_2215.getCategoryName(), Cereals_2215.getDetails()));
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
