#include <stdio.h>
#define LINE_AMOUNT 10


main() {
    
    int i, j, k;
    
    
    for(i=0 ; i<LINE_AMOUNT ; i++) {  //bir satir
    
        for(j=LINE_AMOUNT-1-i ; j>0 ; j--)
            printf(" ");
        
        printf("*");
        
        if(i !=0) {
            for(k=2*i-1 ; k>0 ; k--)
                printf(" ");
        
        printf("*");
        }
        
        printf("\n");
           
    }
    
}
