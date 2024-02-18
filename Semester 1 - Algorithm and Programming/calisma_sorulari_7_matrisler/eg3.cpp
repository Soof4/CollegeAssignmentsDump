#include <stdio.h>


int power(int base, int n) {
    int result = 1;
    
    for (int i=0 ; i<n ; i++)
        result *= base;
    
    return result;
}

int factorial(int num) {
    int result = 1;
    
    while (num>1) {
        result *= num--;
    }
        
    return result;
}


int main() {
    int i, j;
    int matrix[4][10];
    
    for (i=1 ; i<11 ; i++) {
        matrix[0][i-1] = i;
        matrix[1][i-1] = i*i;
        matrix[2][i-1] = factorial(i);
        matrix[3][i-1] = power(i, i);
    }
    
    for (i=0 ; i<4 ; i++) {
        printf("\n");
        for (j=0 ; j<10 ; j++) {
            printf("%12d", matrix[i][j]);
        }
    }
}

