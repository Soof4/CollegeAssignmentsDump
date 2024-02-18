#include <stdio.h>

main() {
    int toplam, sayi;
    
    toplam = 0;
    printf("Sayı girin: ");
    scanf("%d", &sayi);
    toplam += sayi;
    
    printf("Sayı girin: ");
    scanf("%d", &sayi);
    toplam += sayi;
    
    printf("Sayı girin: ");
    scanf("%d", &sayi);
    toplam += sayi;
    
    printf("Toplam = %d", toplam);
    
}