#include <stdio.h>

int main() {
	int num1, num2, num3, num4, delta1, delta2;
	
	
	printf("1. Sayi: ");
	scanf("%d", &num1);
	
	printf("2. Sayi: ");
	scanf("%d", &num2);
	
	printf("3. Sayi: ");
	scanf("%d", &num3);
	
	delta1 = num2 - num1;
    delta2 = num3 - num2;
    
    num4 = num3 + (2*delta2 - delta1);
    
    printf("4. Sayi: %d olmalidir.", num4);
    
}
