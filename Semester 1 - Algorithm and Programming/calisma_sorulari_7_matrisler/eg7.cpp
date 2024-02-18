#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int i, j, k, n;
    
    printf("N: ");
    scanf("%d", &n);
    
    int data[n*n];
    int matrix[n][n];
    
    // -------- Generate numbers
    
    for (j=i=0 ; j<n ; j++) {
        if (j%2 == 0) {
            for (k=0 ; k<n ; k++) {
                data[i] = 1 + rand()%10;
                i++;
            }
        }
        else {
            for (k=0 ; k<n ; k++) {
                data[i] = rand()%10 - 10;
                i++;
            }
        }
    }
           
    // -------- Place the data into matrix
    for (i=0 ; i<n*n ;) {
        for (j=0 ; j<n ; j++) {
            for (k=0 ; k<n ; k++) {
                matrix[j][k] = data[i];
                i++;
            }
        }
    }
    
    // -------- Print the matrix
    for (i=0 ; i<n ; i++) {
        printf("\n\n");
        for (j=0 ; j<n ; j++) {
            printf("%4d", matrix[i][j]);
        }
    }
}

