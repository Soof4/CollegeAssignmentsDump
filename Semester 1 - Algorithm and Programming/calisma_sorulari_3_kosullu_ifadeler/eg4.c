#include <stdio.h>


int main() {
	int n, m;
	
	printf("Bir sayi gir: ");
	scanf("%d", &n);
	printf("Bir sayi gir: ");
	scanf("%d", &m);
	
	if (m / (float)n == 3 || n / (float)m == 3)
        printf("Birbirinin 3 katidir.");
    else
        printf("Birbirinin 3 kati degildir.");

}