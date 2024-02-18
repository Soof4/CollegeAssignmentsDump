#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY -1

int main() {
    srand(time(NULL));
    int i, j, n, container;
    
    printf("N: ");
    scanf("%d", &n);
    
    int matrix[n][n];
    
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            if (i==j) {
                matrix[i][j] = rand()%10;
                matrix[n-i-1][j] = rand()%10;
                matrix[i][n-j-1] = rand()%10;
            }
            else
                matrix[i][j] = EMPTY;
        }
    }
    
    printf("\nMatrix 1:");
    for (i=0 ; i<n ; i++) {
        printf("\n");
        for (j=0 ; j<n ; j++) {
            if (matrix[i][j] == EMPTY)
                printf(" . ");
            else
                printf("%2d ", matrix[i][j]);
        }
    }
    
    for (i=j=0 ; i<n ; i++, j++) {
        container = matrix[i][j];
        matrix[i][j] = matrix[n-i-1][j];
        matrix[n-i-1][j] = container;
    }
    
    printf("\nMatrix 2:");
    for (i=0 ; i<n ; i++) {
        printf("\n");
        for (j=0 ; j<n ; j++) {
            if (matrix[i][j] == EMPTY)
                printf(" . ");
            else
                printf("%2d ", matrix[i][j]);
        }
    }
}

