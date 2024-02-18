#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int i, n;
    double min, max, num;
    
    printf("N: ");
    scanf("%d", &n);
    
    for (i=0, min=max=rand()%10001/10000.0 ; i<n ; i++) {
        num = rand()%10001/10000.0;
        
        printf("%6f ", num);
        if (num > max) {
            max = num;
        }
        else if (num < min) {
            min = num;
        }
    }
    
    
    printf("\nMin: %f", min);
    printf("\nMax: %f", max);
}

