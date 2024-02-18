#include <stdio.h>


main() {
    
    int i, j, k=0, input;
    int top_3_primes[3];
    
    printf("Bir sayi girin: ");
    scanf("%d", &input);
    
    
    for(i=input-1 ; i>0 && k<3 ; i--) {
        bool is_prime = true;
        
        for(j=2 ; j < i/2 ; j++) {
            if(i%j == 0) {
                is_prime = false;
                break;
            }
        }
        
        if(is_prime) {
            top_3_primes[k] = i;
            k++;
        }
    }

    printf("\nGirilen sayidan kucuk en buyuk ucuncu asay sayi: %d", top_3_primes[2]);
}
