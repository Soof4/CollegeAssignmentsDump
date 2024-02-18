#include <stdio.h>


main() {
    
    int sayilar[]= {20,60,45,42,23,24,26,125,66,55,145,50,30,40};
    int i;
    
    for(i=0 ; i<sizeof(sayilar)/sizeof(int); i++) {
        if(sayilar[i] % 2 == 0) {
            sayilar[i]++;
        }
        
    }
    
    for(i=0 ; i<sizeof(sayilar)/sizeof(int); i++) {
        printf("%d  ", sayilar[i]);
    }
    
    return 0;
}
