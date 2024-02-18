#include <stdio.h>

main() {
    double a, b, c, y;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    
    y = (3*a*a + 2*b*b*b + c*c*c*c)/6.0;
    printf("y=%f", y);
}