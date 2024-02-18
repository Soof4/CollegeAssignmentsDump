#include <stdio.h>

main() {
    
    int nums[10];
    int i, max, second_max;
    
    for( i=9 ; i>=0 ; i-- ) {
        printf("%d. Sayi: ", (10 - i));
        scanf("%d", &nums[i]);
    }
    
    max = second_max = nums[i];
    
    for( ; i<10 ; i++ ) {
        if( nums[i] > max ) {
            second_max = max;
            max = nums[i]; 
        }
        
        else if( nums[i] > second_max && nums[i] < max ) {
            second_max = nums[i];
        }
    }
    
    printf("En buyuk ikinci sayi: %d", second_max);
    
}
