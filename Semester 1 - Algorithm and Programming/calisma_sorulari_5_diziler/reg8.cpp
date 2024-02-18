#include <stdio.h>


int main() {
    int sayilar[]= { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
    int i, total;
    double ort;
    
    for (i=1, total=0 ; i<sizeof(sayilar)/sizeof(int) ; i+=2) {
        total += sayilar[i];
    }
    
    ort = total/(sizeof(sayilar)/sizeof(int)/2);
    
    for (i=1 ; i<sizeof(sayilar)/sizeof(int) ; i+=2) {
        if (sayilar[i] > ort)
            printf("%d\t", sayilar[i]);
    }
}

