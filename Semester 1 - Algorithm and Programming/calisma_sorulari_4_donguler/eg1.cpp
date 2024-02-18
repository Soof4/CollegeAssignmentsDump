#include <stdio.h>

main() {
    
    int nums[10];
    int i, max;
    
    for( i=0 ; i<10 ; i++ ) {
        printf("%d. Sayi: ", i+1);
        scanf("%d", &nums[i]);
    }
    
    max = nums[0];
    
    for( ; i >=0 ; i-- ) {
        if ( nums[i] > max)
            max = nums[i];
    }
    
    printf("En buyuk sayi: %d", max);
    
}
