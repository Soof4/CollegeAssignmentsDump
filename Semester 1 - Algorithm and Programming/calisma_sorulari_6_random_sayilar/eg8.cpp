#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int i, n;
    
    printf("N: ");
    scanf("%d", &n);
    
    int numbers[n];
    
    for (i=0 ; i<n ; i++) {
        printf("\n%d", 2*(rand()%50) + i%2 + 1);
    }
    
}

