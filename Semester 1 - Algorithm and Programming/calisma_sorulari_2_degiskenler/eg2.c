#include <stdio.h>

main() {
    double total = 0;
    double n;
    int counter;
    for (counter = 0; counter < 3; ++counter) {
        printf("\nLütfen bir sayı giriniz: ");
        scanf("%lf", &n);
        total += n;
    }
    printf("Girilen sayıların ortalaması: %f", total/(double)counter);
}