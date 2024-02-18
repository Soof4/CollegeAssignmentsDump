#include <stdio.h>


main() {
    
    int i, n, num;
    int positive_num_count;
    
    printf("Kac tane sayi girilecek: ");
    scanf("%d", &n);
    
    int numbers[n];
    
    for(i=n ; i>0 ; i--) {
        printf("Sayi girin: ");
        scanf("%d", &num);
        if(num != 0)
            numbers[i-1] = num;
        else {
            i++;
            printf("\n0 girilemez.");
        }
    }
    
    for(i=0, positive_num_count=0 ; i<n ; i++) {
        if(numbers[i] > 0)
            positive_num_count++;
    }
    
    int positive_nums[positive_num_count];
    int negative_nums[n-positive_num_count];
    
    int pos = 0;
    int neg = 0;
    
    for(i=0 ; i<n ; i++) {
        if(numbers[i] > 0) {
            positive_nums[pos] = numbers[i];
            pos++;
        }
        else {
            negative_nums[neg] = numbers[i];
            neg++;
        }
    }
    
    printf("\nPozitif sayilar:");
    for(i=positive_num_count-1 ; i>=0 ; i--)
        printf("  %d", positive_nums[i]);
        
    printf("\nNegatif sayilar:");
    for(i=n-positive_num_count-1 ; i>=0 ; i--)
        printf("  %d", negative_nums[i]);
    
    
    return 0;
}

