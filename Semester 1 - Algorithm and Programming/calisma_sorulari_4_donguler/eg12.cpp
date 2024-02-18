#include <stdio.h>

main() {
    
    int i, j;

    for(i=1 ; i<=9 ; i+=2) {
        
        for(j=i; j>0 ; j--)
            printf("*");
        
        printf("\n");   
    }

}
