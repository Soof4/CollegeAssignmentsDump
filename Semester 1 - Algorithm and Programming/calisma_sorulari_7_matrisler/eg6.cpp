#include <stdio.h>


int main() {
    int n, i, j, counter;
    
    printf("N: ");
    scanf("%d", &n);
    int matrix[n][n];
    
    for (i=0, counter = i+1 ; i<n ; i++) {
        printf("\n\n");
        for (j=0 ; j<n ; j++) {
            matrix[i][j] = counter++;
            printf("%4d", matrix[i][j]);
        }
    }
    
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            if (j > i) {
                matrix[i][j] += matrix[j][i];
                matrix[j][i] = matrix[i][j] - matrix[j][i];
                matrix[i][j] -= matrix[j][i];
            }
        }
    }
    
    printf("\n");
    for (i=0 ; i<n ; i++) {
        printf("\n\n");
        for (j=0 ; j<n ; j++)
            printf("%4d", matrix[i][j]);
    }
}

