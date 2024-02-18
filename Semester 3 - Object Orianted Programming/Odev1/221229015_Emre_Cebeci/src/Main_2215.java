
import java.util.Scanner;

public class Main_2215 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (true) {
			System.out.print("\nBir p sayısı girin veya \"tüm\" yazın: ");
			String input = scanner.next();
			if (input.toLowerCase().equals("tüm") || input.toLowerCase().equals("tum")) {
				TumunuYazdir();
			}
			else {
				SayiChenAsaliMi(Integer.parseInt(input));
			}
			System.out.println("---------------------------------------");
		}
	}
	
	private static boolean AsalMi(int sayi) {
		if (sayi < 2) {
			return false;
		}
		
		int limit = sayi / 2;
		for (int i = 2; i <= limit; i++) {
			if (sayi % i == 0) {
				return false;
			}
		}
		
		return true;
	}
	
	private static boolean Asal2CarpaniVarMi(int sayi) {
		int primeMuls = 0;
		
		for (int i = 2; i <= sayi; i++) {
			if (AsalMi(i)) {
				int powPrime = i;
				
				while (powPrime <= sayi) {
					if (sayi % powPrime == 0) {
						primeMuls++;
						
						if (primeMuls == 1) {
							System.out.print("Asal çarpanları: ");
						}
						if (primeMuls > 1) {
							System.out.print(" * ");
						}
						
						System.out.print(i);
					}
					powPrime *= i;
				}
				
				
			}
		}
		
		if (primeMuls < 1) {
			System.out.println("Asal çarpanları yoktur.");
		}
		
		if (primeMuls == 2) {
			System.out.print(" = " + (sayi - 2) + " + 2. ");
			return true;
		}
		
		return false;
	}
	
	private static boolean Asal2CarpaniVarMiNoPrint(int sayi) {
		int primeMuls = 0;
		
		for (int i = 2; i <= sayi; i++) {
			if (AsalMi(i)) {
				int powPrime = i;
				
				while (powPrime <= sayi) {
					if (sayi % powPrime == 0) {
						primeMuls++;
					}
					powPrime *= i;
				}
			}
		}
		
		if (primeMuls == 2) {
			return true;
		}
		
		return false;
	}
	
	private static boolean SayiChenAsaliMi(int sayi) {
		if (AsalMi(sayi)) {
			if (AsalMi(sayi + 2)) {
				System.out.println("Chen Asalı");
				return true;
			}
			if (Asal2CarpaniVarMi(sayi + 2)) {
				System.out.println("Chen Asalı");
				return true;
			}
			
		}
		System.out.println("Chen Asalı değil.");
		return false;
	}
	
	private static boolean SayiChenAsaliMiNoPrint(int sayi) {
		return AsalMi(sayi) && (AsalMi(sayi + 2) || Asal2CarpaniVarMiNoPrint(sayi + 2));
	}
	
	private static void TumunuYazdir() {
		for (int i = 10; i < 100; i++) {
			if (SayiChenAsaliMiNoPrint(i)) {
				System.out.print(i + " ");
			}
		}
		System.out.println();
	}
}
