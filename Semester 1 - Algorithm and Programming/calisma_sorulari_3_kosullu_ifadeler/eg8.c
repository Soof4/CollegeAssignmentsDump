#include <stdio.h>


int main() {
	int num, bas_son, bas_ilk;
	
	printf("Sayi: ");
	scanf("%d", &num);
	
	bas_son = num % 10;
	bas_ilk = num / (10*10*10*10);
	
	if (bas_son > bas_ilk) {
	
	num += (bas_son - bas_ilk)*10*10*10*10;
	num -= (bas_son - bas_ilk);
	}
	
	printf("Son durum: %d", num);
}