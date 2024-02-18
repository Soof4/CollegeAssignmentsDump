#include <stdio.h>


main() {
    
    int num, digit_count = 0;
    
    printf("Bir sayi girin: ");
    scanf("%d", &num);
    
    while(num > 0) {
        digit_count++;
        num /= 10;
    }
    
    printf("Basamak sayisi: %d", digit_count);
    
    
    
    
}
