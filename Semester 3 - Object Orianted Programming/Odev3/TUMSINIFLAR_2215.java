//Main_2215.java
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main_2215 {

    public static void main(String[] args) {
        Menu();
    }

    public static void Menu() {
        ArrayList<Urun_2215> urunList = ListeOlustur("Urunler.txt");
        ArrayList<Kategori_2215> kategoriList = null;
        
        while (true) {
            System.out.println("\nMENU:\n"
                    + "1: ListeOlustur\n"
                    + "2: YeniKategoriListeOlustur\n"
                    + "3. BirimFiyatGuncelle\n"
                    + "4. StokGüncelle\n"
                    + "5. UrunSil\n"
                    + "6. Cıkış");
            
            Scanner scanner = new Scanner(System.in);
            int option = scanner.nextInt();
            
            switch (option) {
                case 1:
                    urunList = ListeOlustur("Urunler.txt");
                    break;
                case 2:
                    kategoriList = YeniKategoriListeOlustur("UrunGrubu.txt");
                    System.out.println("N girin:");
                    KategorikGoster(urunList, scanner.nextInt(), kategoriList);
                    break;
                case 3:
                    System.out.println("X girin: ");
                    BirimFiyatGuncelle(urunList, scanner.nextInt());
                    break;
                case 4:
                    StokGuncelleVeUrunEkle(kategoriList, urunList);
                    break;
                case 5:
                    UrunSil(kategoriList, urunList);
                    break;
                case 6:
                    return;
                default:
                    System.out.println("Lütfen menüde olan bir seçeneği seçiniz.");
                    break;
            }
        }
    }
    
    public static ArrayList<Urun_2215> ListeOlustur(String dosyaAdi) {
        FileReader fileReader = null;

        try {
            fileReader = new FileReader(dosyaAdi);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        BufferedReader bufferReader = new BufferedReader(fileReader);

        ArrayList<Urun_2215> urunList = new ArrayList<Urun_2215>();

        
        // Read the title line
        try {
            bufferReader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }    
        
        // Read the products
        while (true) {
            String line = null;
            try {
                line = bufferReader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            if (line == null) {
                break;
            }

            String[] ozellikler = line.split("\t");

            urunList.add(new Urun_2215(ozellikler[0], 
                    Integer.parseInt(ozellikler[1]), 
                    ozellikler[2], 
                    Double.parseDouble(ozellikler[3]), 
                    Integer.parseInt(ozellikler[4]))
                    );
        }
        
        // Print all the products
        System.out.println("Tüm ürünlerin listesi:");
        System.out.println(String.format("%-40s %-9s %-25s %-10s %-9s", "Ürün İsmi", "Kategori", "Br. Ağırlık", "Br. Fiyat", "Stok Mik."));
        System.out.println("-------------------------------------------------------------------------------------------------");
        for (Urun_2215 urun : urunList) {
            System.out.println(String.format("%-40s %-9d %-25s %-10.2f %-9d", urun.Adi, urun.KategoriIndex, urun.BirimAgirligi, urun.BirimFiyati, urun.StokMiktari));
        }
        
        return urunList;
    }

    public static ArrayList<Kategori_2215> YeniKategoriListeOlustur(String dosyaAdi) {
        ArrayList<Kategori_2215> kategoriList = new ArrayList<Kategori_2215>();
        FileReader fileReader = null;

        try {
            fileReader = new FileReader(dosyaAdi);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        BufferedReader bufferReader = new BufferedReader(fileReader);
        
        // Read the title line
        try {
            bufferReader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }    
        
        // Read the categories
        while (true) {
            String line = null;
            try {
                line = bufferReader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            if (line == null) {
                break;
            }

            String[] ozellikler = line.split("\t");

            kategoriList.add(new Kategori_2215(Integer.parseInt(ozellikler[0]),
                        ozellikler[1],
                        ozellikler[2],
                        0));
        }
        
        
        // Print all the categories
        System.out.println("Tüm kategorilerin listesi:");
        
        for (Kategori_2215 kategori : kategoriList) {
            System.out.println(String.format("%-6d %-20s %-66s", kategori.Index, kategori.Adi, kategori.Detay));
        }
        
        return kategoriList;
    }
    
    public static void KategorikGoster(ArrayList<Urun_2215> urunList, int N, ArrayList<Kategori_2215> kategoriList) {
        KategoriListGuncelle(urunList, kategoriList);
        
        System.out.println("\nIndex\tAdet");
        for (int i = 0; i < kategoriList.size() && i < N; i++) {
            System.out.println(kategoriList.get(i).Index + "\t" + kategoriList.get(i).Adet);
        }
    }
    
    private static void KategoriListGuncelle(ArrayList<Urun_2215> urunList, ArrayList<Kategori_2215> kategoriList) {
        for (Urun_2215 urun : urunList) {
            for (Kategori_2215 kategori : kategoriList) {
                if (kategori.Index == urun.KategoriIndex) {
                    kategori.Adet++;
                }
            }
        }
        
        kategoriList.sort((k1, k2) -> k2.Adet - k1.Adet);
    }
    
    public static void BirimFiyatGuncelle(ArrayList<Urun_2215> urunList, int x) {
        // Find min and max prices
        double minPrice = urunList.get(0).BirimFiyati;
        double maxPrice = urunList.get(0).BirimFiyati;
        
        for (Urun_2215 urun : urunList) {
            if (urun.BirimFiyati < minPrice) {
                minPrice = urun.BirimFiyati;
            }
            if (urun.BirimFiyati > maxPrice) {
                maxPrice = urun.BirimFiyati;
            }
        }
        
        // Manipulate the prices
        for (Urun_2215 urun : urunList) {
            if (urun.BirimFiyati == minPrice) {
                urun.BirimFiyati = urun.BirimFiyati * (100 + x) / 100;
            }
            if (urun.BirimFiyati == maxPrice) {
                urun.BirimFiyati = urun.BirimFiyati * (100 - x) / 100;
            }
        }
        
        // Print all the products
        System.out.println("Tüm ürünlerin listesi:");
        System.out.println(String.format("%-40s %-9s %-25s %-10s %-9s", "Ürün İsmi", "Kategori", "Br. Ağırlık", "Br. Fiyat", "Stok Mik."));
        System.out.println("-------------------------------------------------------------------------------------------------");
        for (Urun_2215 urun : urunList) {
            System.out.println(String.format("%-40s %-9d %-25s %-10.2f %-9d", urun.Adi, urun.KategoriIndex, urun.BirimAgirligi, urun.BirimFiyati, urun.StokMiktari));
        }
    }

    public static void StokGuncelleVeUrunEkle(ArrayList<Kategori_2215> kategoriList, ArrayList<Urun_2215> urunList) {
        if (kategoriList == null) {
            System.out.println("Kategori listesi oluşturulmadan bu seçenek kullanılamaz.");
            return;
        }
        
        // Find the lowest category and max stock
        int minStokKategoriIndex = -1;
        int minStok = Integer.MAX_VALUE;
        int maxStok = -1;
        
        for (int i = 0; i < kategoriList.size(); i++) {
            int stok = 0;
            for (Urun_2215 urun : urunList) {
                if (urun.KategoriIndex == kategoriList.get(i).Index) {
                    stok += urun.StokMiktari;
                }
            }
            
            if (stok < minStok) {
                minStokKategoriIndex = i;
                minStok = stok;
            }
            
            if (stok > maxStok) {
                maxStok = stok;
            }
        }
        
        int urunAdet = maxStok - minStok;
        
        // Get other informations
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Urun ismi girin: ");
        String urunIsmi = scanner.nextLine();
        System.out.println("Urun birim agirligi girin: ");
        String urunBirimAgirligi = scanner.nextLine();
        System.out.println("Urun birim fiyati girin: ");
        double urunBirimFiyat = scanner.nextDouble();
        
        urunList.add(new Urun_2215(urunIsmi, minStokKategoriIndex, urunBirimAgirligi, urunBirimFiyat, urunAdet));
        
        // Print all the products
        System.out.println("Tüm ürünlerin listesi:");
        for (Urun_2215 urun : urunList) {
            System.out.println(String.format("%-40s %-9d %-25s %-10.2f %-9d", urun.Adi, urun.KategoriIndex, urun.BirimAgirligi, urun.BirimFiyati, urun.StokMiktari));
        }
        
        KategoriListGuncelle(urunList, kategoriList);
    }

    public static void UrunSil(ArrayList<Kategori_2215> kategoriList, ArrayList<Urun_2215> urunList) {
        if (kategoriList == null) {
            System.out.println("Kategori listesi oluşturulmadan bu seçenek kullanılamaz.");
            return;
        }
        
        // Find the lowest category
        int minStokKategoriIndex = -1;
        int minStok = Integer.MAX_VALUE;
        
        for (int i = 0; i < kategoriList.size(); i++) {
            int stok = 0;
            for (Urun_2215 urun : urunList) {
                if (urun.KategoriIndex == kategoriList.get(i).Index) {
                    stok += urun.StokMiktari;
                }
            }
            
            if (stok < minStok) {
                minStokKategoriIndex = i;
                minStok = stok;
            }
        }
        
        // Find the most expensive product
        int maxUrunFiyat = Integer.MAX_VALUE;
        int maxFiyatUrunIndex = -1;
        
        for (int i = 0; i < urunList.size(); i++) {
            Urun_2215 urun = urunList.get(i);
            if (urun.KategoriIndex == minStokKategoriIndex && (maxFiyatUrunIndex == -1 || urun.BirimFiyati > maxUrunFiyat)) {
                maxFiyatUrunIndex = i;
            }
        }
        
        // Handle no suitable product
        if (maxFiyatUrunIndex == -1) {
            System.out.println("Şartları sağlayan ürün bulunamadı. (En düşük stoğa sahip olan kategoride ürün kalmadı.)");
            return;
        }
        
        // Print the deleted product name
        System.out.println(urunList.get(maxFiyatUrunIndex).Adi + " silindi.");
        urunList.remove(maxFiyatUrunIndex);
        
        // Print all the products
        System.out.println("Tüm ürünlerin listesi:");
        System.out.println(String.format("%-40s %-9s %-25s %-10s %-9s", "Ürün İsmi", "Kategori", "Br. Ağırlık", "Br. Fiyat", "Stok Mik."));
        System.out.println("-------------------------------------------------------------------------------------------------");
        for (Urun_2215 urun : urunList) {
            System.out.println(String.format("%-40s %-9d %-25s %-10.2f %-9d", urun.Adi, urun.KategoriIndex, urun.BirimAgirligi, urun.BirimFiyati, urun.StokMiktari));
        }
        
        KategoriListGuncelle(urunList, kategoriList);
    }

}


//Kategori_2215.java
public class Kategori_2215 {
    public int Index;
    public String Adi;
    public String Detay;
    public int Adet;
    
    public Kategori_2215(int index, String adi, String detay, int adet) {
        this.Index = index;
        this.Adi = adi;
        this.Detay = detay;
        this.Adet = adet;
    }
}

//Urun_2215.java
public class Urun_2215 {
	public String Adi;
	public int KategoriIndex;
	public String BirimAgirligi;
	public double BirimFiyati;
	public int StokMiktari;
	
	public Urun_2215(String adi, int kategoriIndex, String birimAgirligi, double birimFiyati, int stokMiktari) {
		this.Adi = adi;
		this.KategoriIndex = kategoriIndex;
		this.BirimAgirligi = birimAgirligi;
		this.BirimFiyati = birimFiyati;
		this.StokMiktari = stokMiktari;
	}
}
