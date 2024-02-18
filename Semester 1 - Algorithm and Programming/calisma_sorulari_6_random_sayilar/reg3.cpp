#include <stdio.h>
#include <stdlib.h>
#include <time.h>


bool is_prime(int num) {
    int i;
    bool is_prime = true;
    
    if (num<2)
        is_prime = false;
    
    for (i=2 ; is_prime && i<=num/2 ; i++) {
        if (num%i == 0)
            is_prime = false;
    }
    
    return is_prime;
}


int main() {
    srand(time(NULL));
    int i, n, num;
    printf("N: ");
    scanf("%d", &n);
    
    printf("\n");
    
    for (i=0 ; i<n ; i++) {
        while (!(is_prime( num=rand())));
        printf("\n%d", num);
    }
}

