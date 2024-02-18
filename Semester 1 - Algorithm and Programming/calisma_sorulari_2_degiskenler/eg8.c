#include <stdio.h>

main(){
	int num, digit1, digit2, digit3;
	
	printf("Sayı: ");
	scanf("%d", &num);
	
	digit3 = num % 10;
	num /= 10;
	
	digit2 = num % 10;
	num /= 10;
	
	digit1 = num;
	
	printf("1. Basamak: %d\n2. Basamak: %d\n3. Basamak: %d", digit1, digit2, digit3);
}