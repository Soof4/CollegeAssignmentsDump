#include <stdio.h>


main() {
    
    int sayilar[]= {20,60,45,42,23,24,26,125,66,55,145,50,30,40};
    int i, total;
    
    for(i=0, total=0 ; i<sizeof(sayilar)/sizeof(int) ; i++) {
        if(i%2 != 0) {
            total += sayilar[i];
        }
    }
    
    printf("Sonuc: %f", (double)total / (sizeof(sayilar)/sizeof(int)/2) );
    return 0;
}
