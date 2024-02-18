#include <stdio.h>

main() {
    int vize1, vize2, final;
    double result;
    
    printf("Vize1: ");
    scanf("%d", &vize1);
    
    printf("Vize2: ");
    scanf("%d", &vize2);
    
    printf("Final: ");
    scanf("%d", &final);
    
    
    result = vize1*.3 + vize2*.3 + final*.4;
    printf("Sonuç: %f", result);
    
}