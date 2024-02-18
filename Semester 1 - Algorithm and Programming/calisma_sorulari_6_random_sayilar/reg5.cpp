#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double abs(double n1, double n2) {
    double result = n1 - n2;
    if (result < 0)
        result *= -1;
    
    return result;
}


int main() {
    srand(time(NULL));
    int i, j, n;
    
    printf("N: ");
    scanf("%d", &n);
    
    double numbers[i];
    
    for (i=0 ; i<n ; i++) {
        numbers[i] = rand()*.00001 + 0.2;
        for (j=0 ; j<i ; j++) {
            if (abs(numbers[j], numbers[i]) > 0.1) {
                numbers[i] = rand()%10001/10000.0 + 0.2;
                j=0;
            }
        }
            
        printf("\n%f", numbers[i]);
    }
}

