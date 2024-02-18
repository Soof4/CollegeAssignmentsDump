#include <stdio.h>


main() {
    int total, num, num_count, i;
    num = num_count = total = 0;
    
    int numbers[10000];
    
    while(num != -1) {
        printf("Bir sayi girin: ");
        scanf("%d", &num);
        
        if(num > 0) {
            numbers[num_count] = num;
            num_count++;
            total += num;
        }   
    }
    printf("Girilen pozitif sayilarin ortalamasi: %f", (double)total/num_count);
}
