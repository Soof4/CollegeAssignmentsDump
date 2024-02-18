#include <stdio.h>

int bit_ikilisi_bul(int sayi1, int sayi2) {
    int ayni_bit_sayisi;

    ayni_bit_sayisi = 0;

    int sayi_boyut, sayi_kop;

    sayi_kop = sayi2;
    if(sayi1>sayi2) {
        sayi_kop = sayi1;
    }
    sayi_boyut = 0;
    while (sayi_kop > 0) {
        sayi_boyut++;
        sayi_kop >>= 1;
    }


    for(int i=0; i<sayi_boyut; i++) {
        if ((sayi1&1) == (sayi2&1)) {
            ayni_bit_sayisi++;
        }
        sayi1 >>= 1;
        sayi2 >>= 1;
    }
    return ayni_bit_sayisi;
}



int main() {
    printf("%d", bit_ikilisi_bul(10,12));

    return 0;
}