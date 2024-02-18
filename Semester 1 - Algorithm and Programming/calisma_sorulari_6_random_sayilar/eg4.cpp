#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {  // [10, 70] arasi n tane sayi ancak aralarindaki fark min 5 olacak
    srand(time(NULL));
    int i, n, num, delta;
    
    printf("N: ");
    scanf("%d", &n);
    
    num = 10 + rand()%(61/(2*n-1));
    for (i=0 ; i<n ; i++) {
        printf("\n%d", num);
        delta = 5 + rand()%(61/(n+2));
        num += delta;
        
        if (num>70) {
            i--;
            continue;
        }
    }
}

