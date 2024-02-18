#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool is_prime(int num);

int main() {
    srand(time(NULL));
    int i, n, num;
    
    printf("N: ");
    scanf("%d", &n);
    
    i = 0;
    while (i<n) {
        num = rand();
        if (is_prime(num)) {
            printf("\n%d", num);
            i++;
        }
    }
}


bool is_prime(int num) {
    int i;
    bool is_prime = true;
    
    if (num < 2)
        is_prime = false;
    else
        for (i=2 ; i<=num/2 && is_prime ; i++) {
            if (num%i == 0)
                is_prime = false;
        }
    
    return is_prime;
}
