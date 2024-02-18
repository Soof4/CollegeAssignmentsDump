#include <stdio.h>


main() {
    int i, num, digit_count;
    
    printf("Bir sayi girin: ");
    scanf("%d", &num);
    
    digit_count = 0;
    while(num > 0) {
        digit_count++;
        num /= 10;
    }
    
    for( i=0 ; i<digit_count ; i++ )
        printf("9");
    
}
