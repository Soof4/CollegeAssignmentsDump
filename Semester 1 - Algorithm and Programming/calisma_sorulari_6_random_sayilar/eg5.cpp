#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {    // n adet delta max 0.1  [0.2-1.2] arasinda
    srand(time(NULL));
    int i, n;
    double num1, num2;
    
    printf("N: ");
    scanf("%d", &n);
    
    
    for (i=num1=num2=0 ; i<n ; i++) {
        
        while (num2-num1 > 0.1 || num2-num1 == 0 || num2>1.2) {
            num2 = num1 + (rand()%10000)/10000.0 + 0.2;
        }
        num1 = num2;
        printf("\n%f", num2);
    }
}

