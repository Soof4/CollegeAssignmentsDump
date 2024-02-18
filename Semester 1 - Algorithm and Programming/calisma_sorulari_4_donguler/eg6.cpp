#include <stdio.h>

main() {
    
    int nums[10];
    int i, min, max;
    
    for( i=0 ; i<10 ; i++ ) {
        printf("%d. Sayi: ", i+1);
        scanf("%d", &nums[i]);
    }
    
    min = max = nums[0];
    
    for( i=0 ; i<10 ; i++ ) {
        if( nums[i] > max )
            max = nums[i];
        else if( nums[i] < min )
            min = nums[i];   
    }
    
    printf("\nEn buyuk sayi: %d", max);
    printf("\nEn kucuk sayi: %d", min);
    
}
