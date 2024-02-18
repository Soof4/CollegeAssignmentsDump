#include <stdio.h>

main() {
    int i, num, total;
    
    printf("Bir sayi girin: ");
    scanf("%d", &num);
    
    for( num-- ; num > 0 ; num-- ) {
        total = 0;
        
        for( i=1 ; i<=num/2.0 ; i++ )
            if( num % i == 0 )
                total += i;
        
        if( total == num )
            printf("\nBu sayidan kucuk mukemmel sayi: %d", num);
    }
}
