#include <stdio.h>

main() {
    double x, y;
    printf("x için bir değer giriniz: ");
    scanf("%lf", &x);
    y = 3*x*x;
    printf("x=%f için y=%f olmalıdır.", x, y);
    
}