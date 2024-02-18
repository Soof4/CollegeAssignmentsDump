#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sayi_bul(int *dizi, int n) {
    int ortdan_kucuk_ikinci,ortdan_kucuk_ilk;
    float ort = 0;

    for(int i=0; i<n; i++) {
        ort += *(dizi+i);
    }

    ort /= n;
    printf("\nort: %f", ort);
    ortdan_kucuk_ilk = ortdan_kucuk_ikinci = 0;

    for(int i = 0; i<n; i++) {
        if(*(dizi+i)<ort) {
            if(*(dizi+i)>ortdan_kucuk_ilk) {
                ortdan_kucuk_ikinci = ortdan_kucuk_ilk;
                ortdan_kucuk_ilk = *(dizi+i);
            }
        }
    }

    return ortdan_kucuk_ikinci;
}


int main() {
    srand(time(NULL));
    int n;
    printf("\nN: ");
    scanf("%d", &n);

    int dizi[n];
    for(int i=0; i<n; i++) {
        *(dizi+i) = 10 + rand()%21;
    }
    for(int i=0; i<n; i++) {
        printf("%d ", *(dizi+i));
    }
    printf("\nSonuc: %d", sayi_bul(dizi, n));

    return 0;
}