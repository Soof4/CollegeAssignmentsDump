#include <stdio.h>

main() {
    
    int personel_turu, maas;
    
    printf("Personel turu: ");
    scanf("%d", &personel_turu);
    
    printf("Suandaki maasiniz: ");
    scanf("%d", &maas);

    switch(personel_turu) {
        case 1: maas *= 1.5; break;
        case 2: maas *= 1.3; break;
        case 3: maas *= 1.4; break;
        case 4: maas *= 1.2; break;
        default:;
    }
    
    printf("Zamli maasiniz: %d", maas);
    
    return 0;
}
