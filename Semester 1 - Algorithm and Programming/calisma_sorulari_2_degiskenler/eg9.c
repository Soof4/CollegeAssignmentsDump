#include <stdio.h>

#define G 0.865

main() {
	double F, m1, m2, r;
	
	printf("m1: ");
	scanf("%lf", &m1);
	
	printf("m2: ");
	scanf("%lf", &m2);
	
	printf("r: ");
	scanf("%lf", &r);
	
	F = G * (m1 * m2 / (r*r));
	
	printf("F = %f", F);
}