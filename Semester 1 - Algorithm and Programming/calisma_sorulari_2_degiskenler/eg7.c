#include <stdio.h>

main() {
    int r1, r2, r3;
    float r_es;
    
    printf("R1: ");
    scanf("%d", &r1);
    
    printf("R2: ");
    scanf("%d", &r2);
    
    printf("R3: ");
    scanf("%d", &r3);
    
    r_es = (r1*r2*r3)/(float)(r1*r3+r1*r2+r2*r3);
    printf("R eş: %f", r_es);
}