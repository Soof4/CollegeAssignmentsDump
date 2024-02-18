#include <stdio.h>


main() {
    
    int i, j, k;
    
    for(i=1 ; i<=9 ; i+=2) {
        
        for(k=(10-i)/2 ; k>0 ; k--)
                printf(" ");
                
        for(j=i ; j>0 ; j--)    
            printf("*");
        
        printf("\n");
    }

}
