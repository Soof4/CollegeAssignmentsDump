package package1;

import java.io.BufferedReader;
import java.io.FileReader;

import package2.Beverages_2215;
import package2.Cereals_2215;
import package2.Condiments_2215;
import package2.Confections_2215;
import package2.DairyProducts_2215;
import package2.Main_2215;

public class DataReader_2215 {
    
    protected static void ListeleriOlustur(String dir) {
        try {
            // Reading UrunGrubu.txt to extract category details
            BufferedReader br = new BufferedReader(new FileReader("UrunGrubu.txt"));
            
            String line = br.readLine();    // Read the title line
            
            while (true) {
                line = br.readLine();
                
                if (line == null || line.isEmpty()) {
                    break;
                }
                
                String[] attributes = line.split("\t");    // 0: CategoryIndex, 1: CategoryName, 2: Details
                
                switch (Integer.parseInt(attributes[0])) {
                    case 1:
                        Beverages_2215.setCategoryName(attributes[1]);
                        Beverages_2215.setDetails(attributes[2]);
                        break;
                    case 2:
                        Condiments_2215.setCategoryName(attributes[1]);
                        Condiments_2215.setDetails(attributes[2]);
                        break;
                    case 3:
                        Confections_2215.setCategoryName(attributes[1]);
                        Confections_2215.setDetails(attributes[2]);
                        break;
                    case 4:
                        DairyProducts_2215.setCategoryName(attributes[1]);
                        DairyProducts_2215.setDetails(attributes[2]);
                        break;
                    case 5:
                        Cereals_2215.setCategoryName(attributes[1]);
                        Cereals_2215.setDetails(attributes[2]);
                        break;
                }
            }
            
            br.close();
            
            // Reading Urunler.txt to extract products
            br = new BufferedReader(new FileReader(dir));
            
            line = br.readLine();    // Read the title line
            
            while (true) {
                line = br.readLine();
                
                if (line == null || line.isEmpty()) {
                    break;
                }
                
                
                String[] attributes = line.split("\t");    // 0: Name, 1: CategoryIndex, 2: UnitWeight, 3: UnitPrice, 4: Stock
                
                switch (Integer.parseInt(attributes[1])) {
                    case 1:    // Beverages
                        Main_2215.beverageList.add(new Beverages_2215(attributes[0],
                                Integer.parseInt(attributes[1]),
                                attributes[2],
                                Double.parseDouble(attributes[3]),
                                Integer.parseInt(attributes[4])
                                ));
                        break;
                    case 2:    // Condiments
                        Main_2215.condimentList.add(new Condiments_2215(attributes[0],
                                Integer.parseInt(attributes[1]),
                                attributes[2],
                                Double.parseDouble(attributes[3]),
                                Integer.parseInt(attributes[4])
                                ));
                        break;
                    case 3:    // Confections
                        Main_2215.confectionList.add(new Confections_2215(attributes[0],
                                Integer.parseInt(attributes[1]),
                                attributes[2],
                                Double.parseDouble(attributes[3]),
                                Integer.parseInt(attributes[4])
                                ));
                        break;
                    case 4:    // DairyProducts
                        Main_2215.dairyProductList.add(new DairyProducts_2215(attributes[0],
                                Integer.parseInt(attributes[1]),
                                attributes[2],
                                Double.parseDouble(attributes[3]),
                                Integer.parseInt(attributes[4])
                                ));
                        break;
                    case 5:    // Cereals
                        Main_2215.cerealList.add(new Cereals_2215(attributes[0],
                                Integer.parseInt(attributes[1]),
                                attributes[2],
                                Double.parseDouble(attributes[3]),
                                Integer.parseInt(attributes[4])
                                ));
                        break;
                }
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

}
