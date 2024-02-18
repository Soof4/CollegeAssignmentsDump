#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool is_prime(int num);


int main() {
    srand(time(NULL));
    int i, n, num;
    
    printf("N: ");
    scanf("%d", &n);
    
    for (i=num=0 ; i<n ; i++) {
        num = rand()%100 +1;
        if (i%2==0) {
            while (!is_prime(num))
                num = rand()%100 +1;
        }
        else {
            while (is_prime(num))
                num = rand()%100 +1;
        }
        printf("\n%d", num);
    }
}


bool is_prime(int num) {
    bool is_prime = true;
    int i;
    
    if (num < 2)
        is_prime = false;
        
    for (i=2 ; is_prime && i<=num/2 ; i++) {
        if (num%i == 0) {
            is_prime = false;
            break;
        }
    }
    
    return is_prime;
}
