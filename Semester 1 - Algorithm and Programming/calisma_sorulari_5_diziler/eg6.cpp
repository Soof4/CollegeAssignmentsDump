#include <stdio.h>


main() {
    
    int sayilar[]= {20,60,45,42,23,24,26,125,66,55,145,50,30,40};
    int i, counter;
    
    for(i=0, counter=0 ; i<(sizeof(sayilar)/sizeof(int)-1) ; i++) {
        if(sayilar[i] % 2 == 0 && sayilar[i+1] % 2 == 0)
            counter++;
    }
    
    printf("Sonuc: %d", counter);
    
    return 0;
}
