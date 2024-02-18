#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int i, j, k, n, delta;
    char string[] = ".NET_CORE";

    printf("N: ");
    scanf("%d", &n);

    char matrix[n][n];

    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            matrix[i][j] = ' ';
        }
    }
    j = k = 0;
    matrix[j][k] = '.';
    for (i=1 ; i<sizeof(string)-1 ; i++) {
        while (matrix[j][k] != ' ' || j>=n || k>=n || j<0 || k<0) {
            if (rand()%2 == 0) {
                delta = rand()%3 - 1;
                if (j+delta < n && j+delta>-1 && matrix[j+delta][k] == ' ') {
                    j += delta;
                }
            }
            else {
                delta = rand() % 3 - 1;
                if (k+delta < n && k+delta>-1 && matrix[j][k+delta] == ' ') {
                    k += delta;
                }
            }
        }
        matrix[j][k] = string[i];
    }

    for (i=0 ; i<n ; i++) {
        printf("\n");
        for (j=0 ; j<n ; j++) {
            printf(" %c ", matrix[i][j]);
        }
    }
}