#include <stdio.h>


main() {
    
    int result, base, n;
    
    printf("Taban: ");
    scanf("%d", &base);
    
    printf("Us: ");
    scanf("%d", &n);
    
    result = base;
    for( ; n>1 ; n-- ) {  // result = base oldugu icin baslangicta ztn bir defa carpmis gibi oldugundan "n>1" gerekiyor. result=1 olsaydi "n>0" olmaliydi.
        result *= base;
    }
    
    printf("Sonuc: %d", result);
    
}
