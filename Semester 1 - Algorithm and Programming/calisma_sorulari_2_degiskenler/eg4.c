#include <stdio.h>

main() {
    double F, K;
    
    printf("Kelvin değeri girin: ");
    scanf("%lf", &K);
    
    F = (K - 235.15) * 9/5.0 + 32;
    printf("%f = %f'dir.", K, F);
}