import java.util.ArrayList;

public interface IProduct_2215 extends test {
    public int test = 0;
    public void updateProductStock(int amount, boolean isAdd);
    public void updateProductName(String newName, String newDetails);
    public void removeProduct(ArrayList<? extends Product_2215> list);
    public void addNewProduct(String name, String weight, double price, int stock, String details);
    public static void test() {
        
        
        int localInt = 90;
        System.out.println(localInt);
    };
}
