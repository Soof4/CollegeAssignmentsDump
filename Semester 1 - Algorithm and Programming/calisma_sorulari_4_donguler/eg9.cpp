#include <stdio.h>


int power(int base, int n) {
    int result = 1;
    
    for( ; n>0 ; n--)
        result *= base;
    return result;
}


main() {
    
    int i, input_num, num, digit_count;
    
    printf("Bir sayi girin: ");
    scanf("%d", &input_num);
    
    num = input_num;
    
    digit_count = 0;
    while( num > 0 ) {
        num /= 10;
        digit_count++;
    }
    
    
    int digits[digit_count];
    for( i=0 ; i < digit_count ; i++ ) {
        digits[i] = input_num % 10;
        input_num /= 10;
    }
    
    num = 0;
    for( i = 0 ; i<digit_count ; i++ ) { // digits[0] birler basamagina denk gelir.
        num += digits[i] * power(10, digit_count-i-1);
    }
    printf("\n%d", num);
    
}
