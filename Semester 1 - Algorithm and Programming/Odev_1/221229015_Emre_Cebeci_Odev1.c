#include <stdio.h>

main() {
    
    // Calc the total
    double ogrenci_no = 22.1229015;
    int ondalik_kisim = (ogrenci_no - (int)ogrenci_no)*10000000;
    int total = 0;
    
    total += (ondalik_kisim % 10);
    ondalik_kisim /= 10;
    total += (ondalik_kisim % 10);
    ondalik_kisim /= 10;
    total += (ondalik_kisim % 10);
    ondalik_kisim /= 10;
    total += (ondalik_kisim % 10);
    ondalik_kisim /= 10;
    total += (ondalik_kisim % 10);
    ondalik_kisim /= 10;
    total += (ondalik_kisim % 10);
    ondalik_kisim /= 10;
    total += (ondalik_kisim % 10);
    ondalik_kisim /= 10;
    
    
//    while (ondalik_kisim > 1) {
//        total += ondalik_kisim % 10;
//        ondalik_kisim /= 10;
//    }
    
    
    printf("Toplam: %d", total);
    
    
    ////// Find x
    long x = 0, y = 0;
    double res = 0;
    
    while (res < 0.1) {
        ++x;
        res = (x*x*x - total)/5.0;
        printf("\nx=%ld icin (%ld - %d)/5 = %.1f", x, x*x*x, total, res);
    }
    
    /// Asan basamak icin islemler
    ++x;
    res = (x*x*x - total)/5.0;
    printf("\nx=%ld icin (%ld - %d)/5 = %.1f", x, x*x*x, total, res);
    --x;
    ///
    
    printf("\n\nx=%ld oldugunda elde edilen sonuc araligindan cok uzaklastigindan x=%ld olacaktir.", x+1, x);
    printf("\n\nx=%ld; //x artik %ld olarak denklemde kullanilacaktir.\n", x, x);
    //////
    
    
    ////// Find y
    res = 0;
    while (res < .1 || res > .2) {
        ++y;
        res = (x*x*x - .1*y*y - total)/5.0;
        printf("\ny=%ld icin (%ld - %.1f - %d)/5 = %.2f", y, x*x*x, .1*y*y, total, res);
    
        if (res < 0.1) {
            
            // Farkli ogrenci numaralari icin bazen baslangicta bulunan x'e karsilik esitsizligi saglayan y degeri bulunamiyor. Bu sebeple x'i 1 arttirip tekrar y'yi aramak icin bu if'i ekledim.
            
            printf("\n\nBu x degerine uygun esitsizligi saglayan y degeri bulunamadigi icin x degeri 1 arttiriliyor.\n");
            ++x;
        }
    }
    //////
    
    printf("\n\nSonuc olarak x=%ld, y=%ld, toplam=%d durumunda esitsizlik saglanmaktadir.", x, y, total);
    
}
