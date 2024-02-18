#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int i;
    double num;
    
    for (i=0 ; i<10 ; i++) {
        num = rand()%10000/10000.0;
        printf("\n%.4f", num);
    }
}

