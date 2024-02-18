#include <stdio.h>


int main() {
    int sayilar[]= { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
    int i, counter;
    
    for (i=1, counter=0 ; i<sizeof(sayilar)/sizeof(int) ; i++) {
        if (sayilar[i-1] % 2 == 0 && sayilar[i] % 2 == 0) {
            counter++;
            printf("%2d-%2d\t", sayilar[i-1], sayilar[i]);
        }
    }
    
    printf("\n%d adet", counter);
}

