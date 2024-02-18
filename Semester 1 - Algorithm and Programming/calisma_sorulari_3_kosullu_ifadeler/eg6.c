#include <stdio.h>

int main() {
    
    int maas, parca;
    
    printf("Maaas: ");
    scanf("%d", &maas);
    
    printf("Parca: ");
    scanf("%d", &parca);
    
    if (parca > 149)
        maas *= 1.3;
        
    else if (parca > 99)
        maas *= 1.25;
        
    else if (parca > 49)
        maas *= 1.2;
    
    printf("Toplam maas: %d", maas);
    
}