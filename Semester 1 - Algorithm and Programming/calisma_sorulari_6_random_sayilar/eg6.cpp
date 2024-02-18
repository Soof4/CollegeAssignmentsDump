#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int i, j, n, container;
    
    printf("N: ");
    scanf("%d", &n);
    
    int numbers[n];
    
    for (i=0 ; i<n ; i++)
        numbers[i] = rand()%101;
    
    for (i=1 ; i<n ; i++) {
        j = i;
        while (j>0 && numbers[j-1] > numbers[j]) {
            container = numbers[j-1];
            numbers[j-1] = numbers[j];
            numbers[j] = container;
            j--;
        }
    }
    
    for (i=0 ; i<n ; i++)
        printf("\n%d", numbers[i]);
}

