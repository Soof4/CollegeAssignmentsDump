#include <stdio.h>

int power(int base, int n) {
    int result = base;
    
    for( ; n>1 ; n--)
        result *= base;
    
    return result;
}


main() {
    
    int i, num;
    
    printf("Bir sayi girin:");
    scanf("%d", &num);
    
    for(i=1 ; i<num ; i++) {
        
        printf("\n%d", power(i,i));
        
    }
    
}
