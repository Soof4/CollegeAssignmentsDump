#include <stdio.h>

abs(number) {    //sayinin mutlak degerini bulmak icin eger sayi negatifse -1 ile carp
    if (number < 0)
        number *= -1;
        
    return number;
}


sq(number) {    //sayinin karesini al
    return number * number;
}


main() {
    
    int num, i, max, min;
    int digits[4], results[3], min_sira[4], max_sira[4];
    
    printf("4 Basamakli bir sayi girin: ");
    scanf("%d", &num);
    
    for (i=0; i < 4; ++i) {
        digits[i] = num % 10;
        num /= 10;
    }
    
    results[0] = abs(sq(digits[0]) + sq(digits[1]) - sq(digits[2]) - sq(digits[3]));
    printf("\n%d, %d ve %d, %d => Sonuc: %d", digits[0], digits[1], digits[2], digits[3], results[0]);
    
    results[1] = abs(sq(digits[0]) + sq(digits[2]) - sq(digits[1]) - sq(digits[3]));
    printf("\n%d, %d ve %d, %d => Sonuc: %d", digits[0], digits[2], digits[1], digits[3], results[1]);
    
    results[2] = abs(sq(digits[0]) + sq(digits[3]) - sq(digits[1]) - sq(digits[2]));
    printf("\n%d, %d ve %d, %d => Sonuc: %d", digits[0], digits[3], digits[1], digits[2], results[2]);
    
    min = max = results[0];
    
    for (i=0; i < 4; ++i) {
        min_sira[i] = digits[i];
        max_sira[i] = digits[i];
    }
    
    if (results[1] > max) {
        max = results[1];
        max_sira[0] = digits[0];
        max_sira[1] = digits[2];
        max_sira[2] = digits[1];
        max_sira[3] = digits[3];
    }
        
    else if (results[1] < min) {
        min = results[1];
        min_sira[0] = digits[0];
        min_sira[1] = digits[2];
        min_sira[2] = digits[1];
        min_sira[3] = digits[3];
    }
    
    if (results[2] > max) {
        max = results[2];
        max_sira[0] = digits[0];
        max_sira[1] = digits[3];
        max_sira[2] = digits[1];
        max_sira[3] = digits[2];
    }
    else if (results[2] < min) {
        min = results[2];
        min_sira[0] = digits[0];
        min_sira[1] = digits[3];
        min_sira[2] = digits[1];
        min_sira[3] = digits[2];
    }
    
    printf("\n\nMinimum: %d, %d ve %d, %d => Sonuc: %d", min_sira[0], min_sira[1], min_sira[2], min_sira[3], min);
    printf("\nMaksimum: %d, %d ve %d, %d => Sonuc: %d", max_sira[0], max_sira[1], max_sira[2], max_sira[3], max);
    
}
