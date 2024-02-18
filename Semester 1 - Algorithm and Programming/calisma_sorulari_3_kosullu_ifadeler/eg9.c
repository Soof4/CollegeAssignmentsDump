#include <stdio.h>


int main() {
	int A, B, C;
	
	printf("A = ");
	scanf("%d", &A);
	
	printf("B = ");
	scanf("%d", &B);
	
	printf("C = ");
	scanf("%d", &C);
	
	
	if (A*A + B*B == C*C)
	    printf("Dik ucgen cizilebilir.");
	    
	else
	    printf("Dik ucgen cizilemez.");
}