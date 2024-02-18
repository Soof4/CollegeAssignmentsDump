#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int i, n, total;
    double mean;
    
    printf("N: ");
    scanf("%d", &n);
    
    int numbers[n];
    
    for (i=total=0 ; i<n ; i++) {
        numbers[i] = rand()%101;
        printf("%3d ", numbers[i]);
        total += numbers[i];
    }
    
    mean = (float)total/n;
    
    for (i=0 ; i<n ; i++) {
        while (numbers[i] < mean) {
            numbers[i] = rand()%101;
        }
    }
    printf("\n\nMean: %f", mean);
    printf("\n\nNew numbers:\n");
    for (i=0 ; i<n ; i++)
        printf("%3d ", numbers[i]);
}

