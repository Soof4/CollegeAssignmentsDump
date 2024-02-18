#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_matrix(char *ip, int n) {
    int i, j;
    for (i=0 ; i<n ; i++) {
        printf("\n");
        for (j=0 ; j<n ; j++) {
            printf(" %c ", *ip);
            ip++;
        }
    }
}



int main() {
    srand(time(NULL));
    int i, j, n;
    char char_sheet[] = {'J', 'A', 'V'};

    printf("N: ");
    scanf("%d", &n);

    char matrix[n][n];
    char result_matrix[n][n];

    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            matrix[i][j] = char_sheet[rand()%3];
            result_matrix[i][j] = '_';
        }
    }

    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            if (matrix[i][j] == 'J' && matrix[i][j+1] == 'A' && matrix[i][j+2] == 'V' && matrix[i][j+3] == 'A' && j+3<n) {
                result_matrix[i][j] = 'J';
                result_matrix[i][j+1] = 'A';
                result_matrix[i][j+2] = 'V';
                result_matrix[i][j+3] = 'A';
            }

            if (matrix[i][j+3] == 'J' && matrix[i][j+2] == 'A' && matrix[i][j+1] == 'V' && matrix[i][j] == 'A' && j+3<n) {
                result_matrix[i][j+3] = 'J';
                result_matrix[i][j+2] = 'A';
                result_matrix[i][j+1] = 'V';
                result_matrix[i][j] = 'A';
            }

            if (matrix[i][j] == 'J' && matrix[i+1][j] == 'A' && matrix[i+2][j] == 'V' && matrix[i+3][j] == 'A' && i+3<n) {
                result_matrix[i][j] = 'J';
                result_matrix[i+1][j] = 'A';
                result_matrix[i+2][j] = 'V';
                result_matrix[i+3][j] = 'A';
            }

            if (matrix[i][j+3] == 'J' && matrix[i+2][j] == 'A' && matrix[i+1][j] == 'V' && matrix[i][j] == 'A' && i+3<n) {
                result_matrix[i+3][j] = 'J';
                result_matrix[i+2][j] = 'A';
                result_matrix[i+1][j] = 'V';
                result_matrix[i][j] = 'A';
            }

            if (matrix[i][j] == 'J' && matrix[i+1][j+1] == 'A' && matrix[i+2][j+2] == 'V' && matrix[i+3][j+3] == 'A' && i+3<n && j+3<n) {
                result_matrix[i][j] = 'J';
                result_matrix[i+1][j+1] = 'A';
                result_matrix[i+2][j+2] = 'V';
                result_matrix[i+3][j+3] = 'A';
            }

            if (matrix[i+3][j+3] == 'J' && matrix[i+2][j+2] == 'A' && matrix[i+1][j+1] == 'V' && matrix[i][j] == 'A' && i+3<n && j+3<n) {
                result_matrix[i+3][j+3] = 'J';
                result_matrix[i+2][j+2] = 'A';
                result_matrix[i+1][j+1] = 'V';
                result_matrix[i][j] = 'A';
            }

            if (matrix[i+3][j] == 'J' && matrix[i+2][j+1] == 'A' && matrix[i+1][j+2] == 'V' && matrix[i][j+3] == 'A' && i+3<n && j+3<n) {
                result_matrix[i+3][j] = 'J';
                result_matrix[i+2][j+1] = 'A';
                result_matrix[i+1][j+2] = 'V';
                result_matrix[i][j+3] = 'A';
            }

            if (matrix[i][j+3] == 'J' && matrix[i+1][j+2] == 'A' && matrix[i+2][j+1] == 'V' && matrix[i+3][j] == 'A' && i+3<n && j+3<n) {
                result_matrix[i][j+3] = 'J';
                result_matrix[i+1][j+2] = 'A';
                result_matrix[i+2][j+1] = 'V';
                result_matrix[i+3][j] = 'A';
            }


        }
    }

    print_matrix(&result_matrix[0][0], n);
}