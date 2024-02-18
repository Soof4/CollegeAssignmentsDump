#include <stdio.h>


int main() {
    int i, n, negative_counter, positive_counter;
    
    printf("Kac sayi girilecek (N): ");
    scanf("%d", &n);
    int nums[n];
    
    printf("Sayilari giriniz.\n");
    
    
    for (i = positive_counter = negative_counter = 0 ; i<n ; i++) {
        scanf("%d", &nums[i]);
        if (nums[i]>0)
            positive_counter++;
        if (nums[i]<0)
            negative_counter++;
    }
    
    int positive_nums[positive_counter];
    int negative_nums[positive_counter];
    
    int pos_i, neg_i;
    for (i=0, pos_i = 0, neg_i = 0; i<n ; i++) {
        if (nums[i]>0) {
            positive_nums[pos_i] = nums[i];
            pos_i++;
        }
        if (nums[i]<0) {
            negative_nums[neg_i] = nums[i];
            neg_i++;
        }
    }
    
    
    printf("\nPozitif sayilar: ");
    for (i=0 ; i<positive_counter ; i++)
        printf("%d ", positive_nums[i]);
    
    printf("\nNegatif sayilar: ");
    for (i=0 ; i<negative_counter ; i++)
        printf("%d ", negative_nums[i]);
    
}

