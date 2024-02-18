#include <stdio.h>

int main() {
    int i, j;
    int n, counter;
    
    printf("N: ");
    scanf("%d", &n);
    
    int matrix[n][n];
    counter = n*n;
    
    int LEFT_DOWN, RIGHT_UP;
    LEFT_DOWN = 1;
    RIGHT_UP = 0;
    
    // -------- Logic
    i=0;
    int x, y;
    x = y = (n-1);
    
    while (i<n) {
        if (i==0) {
            for (j=0 ; j<n-1 ; j++) {
                matrix[x--][y] = counter--;
            }
            i++;
            continue;
        }
        
        if (i%2 == LEFT_DOWN) {
            for (j=0 ; j<n-i ; j++) {
                matrix[x][y--] = counter--;
            }
            for (j=0 ; j<n-i ; j++) {
                matrix[x++][y] = counter--;
            }
        }
        
        if (i%2 == RIGHT_UP) {
            for (j=0 ; j<n-i ; j++) {
                matrix[x][y++] = counter--;
            }
            for (j=0 ; j<n-i ; j++) {
                matrix[x--][y] = counter--;
            }
        }
        
        i++;
    }
    
    matrix[n/2][(n-1)/2] = 1;
    
    // -------- Print
    for (i=0 ; i<n ; i++) {
        printf("\n");
        for (j=0 ; j<n ; j++) {
            printf("%4d", matrix[i][j]);
        }
    }
}
