#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int i, n, min, max, num;
    
    printf("N: ");
    scanf("%d", &n);
    
    for (i=0 ; i<n ; i++) {
        num = rand()%2;
        if (i==0) {
            min = max = num;
            continue;
        }
        if (num>max)
            max = num;
        if (num<min)
            min = num;
    }
    
    printf("\nMin: %d\nMax: %d", min, max);
}

