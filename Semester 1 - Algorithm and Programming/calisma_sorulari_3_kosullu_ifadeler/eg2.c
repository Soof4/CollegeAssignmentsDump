#include <stdio.h>


main() {
    
    int vize1, vize2, final, but;
    double ort;
    
    printf("Vize 1: ");
    scanf("%d", &vize1);
    
    printf("Vize 2: ");
    scanf("%d", &vize2);
    
    printf("Final: ");
    scanf("%d", &final);
    
    ort = vize1*.3 + vize2*.3 + final*.4;
    
    
    if (ort < 50) {
        
        printf("ORTALAMANIZ: %f, KALDINIZ.", ort);
        printf("\nButunleme notunuzu girin: ");
        scanf("%d", &but);
        
        ort = vize1*.3 + vize2*.3 + but*.4;
        
    }
    
    if (ort < 50)
        printf("ORTALAMANIZ: %f, KALDINIZ.", ort);
    
    else
        printf("ORTALAMANIZ: %f, GECTINIZ.", ort);
    
    return 0;
}
