#include <stdio.h>

main() {
    
    int num1, num2, container, i, prime_count;
    
    printf("1. Sayi: ");
    scanf("%d", &num1);
    printf("2. Sayi: ");
    scanf("%d", &num2);
    
    if(num2 > num1) {
        container = num1;
        num1 = num2;
        num2 = container;
    }
    
    //num1 > num2
    prime_count = 0;
    for( ; num2 < num1 ; num2++ ) { //num2 den basla num1'e kadar olan sayýlarý tek tek test et
        
        bool is_prime = true;
        
        for( i=2; i<=num2/2.0 ; i++) {
            if( num2%i == 0 ) {
                is_prime = false;
                break;
            }
        }
        
        if( is_prime == true && num2 != 1) {
            prime_count++;
            printf("%8d  ", num2);
        }
        
    }
    
    printf("\n\nTotal %d tane asal sayi vardir.", prime_count);
    
    
    return 0;
}
