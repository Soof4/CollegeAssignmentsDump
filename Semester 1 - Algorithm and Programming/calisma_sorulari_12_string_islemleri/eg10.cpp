#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int i, j, n;

    printf("N: ");
    scanf("%d", &n);

    char matrix[n][n];

    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ;) {

            if (rand()%2 == 0) {
                matrix[i][j++] = 'B';
                matrix[i][j++] = '2';
                matrix[i][j++] = 'B';
                matrix[i][j++] = 'C';
                matrix[i][j++] = '2';
                matrix[i][j++] = 'C';

            }
            else {
                matrix[i][j++] = 'B';
                matrix[i][j++] = '2';
                matrix[i][j++] = 'B';
            }
        }
    }
    for (i=0 ; i<n ; i++) {
        printf("\n");
        for (j=0 ; j<n ; j++) {
            printf(" %c ", matrix[i][j]);
        }
    }
}