#include <stdio.h>

main() {
    
    bool is_prime = false;
    int i, num_count, input_num;
    
    while(!is_prime) {
        
        printf("Bir sayi girin: ");
        scanf("%d", &input_num);
        
        is_prime = true;
        
        if( input_num < 2 )
            is_prime = false;
            
        for( i=2 ; i<=input_num/2.0 ; i++) {
            if( input_num % i == 0 ) {
                is_prime = false;
                break;
            }
        }
        
        num_count++;
    }
    
    printf("\n%d tane sayi girilmistir.", num_count);
    
    
}
