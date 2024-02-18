#include <stdio.h>


main() {
    
    int num, digit_count, two_digit_num_count = 0;
    
    while(num != -1) {
        digit_count = 0;
        printf("Bir sayi giriniz: ");
        scanf("%d", &num);
        
        while(num > 0) {
            num /= 10;
            digit_count++;
        }
        
        if(digit_count == 2)
            two_digit_num_count++;
            
        
    }
    
    printf("\n›ki basamakli sayi adeti: %d", two_digit_num_count);
}
