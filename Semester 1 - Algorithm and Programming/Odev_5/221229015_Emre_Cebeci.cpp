#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int i, j, n, num;
    
    printf("Kac tane sayi girilecek (N): ");
    scanf("%d", &n);
    
    int numbers[n];
    
    printf("Girilen sayilar:");
    for (i=0 ; i<n ; i++) {
        num = rand()%101 - 50;
        printf("  %d", num);
        
        if (i==0)
            numbers[i] = num;
        else {
            for (j=i ; j>0 && numbers[j-1]>num ; j--)
                numbers[j] = numbers[j-1];
                
            numbers[j] = num;
        }
    }
    
    printf("\n\na) ");
    for (i=0 ; i<n ; i++)
        if (numbers[i]%2!=0)
            printf("%d  ", numbers[i]);
    
    printf("\nb) ");
    for (i=n-1 ; i>-1 ; i--)
        if (numbers[i]%2!=0)
            printf("%d  ", numbers[i]);
    
    printf("\nc) ");
    for (i=0 ; i<n ; i++)
        printf("%d  ", numbers[i]);
    
    printf("\nd) ");
    for (i=n-1 ; i>-1 ; i--)
        printf("%d  ", numbers[i]);
}

