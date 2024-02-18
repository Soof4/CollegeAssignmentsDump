#include <stdio.h>


int length(char string[]) {
    int i;
    for (i=0 ; string[i] != '\0' ; i++);
    return i;
}

int main() {
    int i, j, k, w, n;
    char temp;

    printf("Kac kisi girilecek: ");
    scanf("%d", &n);


    char matrix[n][3][50];    // number_of_people | name/space/surname | string
    char sorted_by_name[n][3][50];

    gets(matrix[0][0]);
    for (i=0 ; i<n ; i++) {
        printf("\n%d. Kisi isimi: ", i+1);

        gets(matrix[i][0]);
        matrix[i][1][0] = ' ';
        matrix[i][1][1] = '\0';

        printf("%d. Kisi soyismi : ", i+1);
        gets(matrix[i][2]);
    }

    // Sort by name
    for (i=1; i<n ; i++) {
        j=i;
        w = 0;

        while (matrix[j][0][w] == matrix[j-1][0][w]) {
            w++;
        }
        while (matrix[j][0][w] < matrix[j-1][0][w]) {
            for (k = 0; k < 50; k++) {
                temp = matrix[j][0][k];
                matrix[j][0][k] = matrix[j-1][0][k];
                matrix[j-1][0][k] = temp;

                temp = matrix[j][2][k];
                matrix[j][2][k] = matrix[j-1][2][k];
                matrix[j-1][2][k] = temp;
            }
            w = 0;
            j--;
        }
    }

    printf("\nIsme gore:");
    for (i=0 ; i<n ; i++) {
        printf("\n%s%s%s", matrix[i][0], matrix[i][1], matrix[i][2]);
    }

    // Sort by surnames
    for (i=1; i<n ; i++) {
        j=i;
        w = 0;

        while (matrix[j][2][w] == matrix[j-1][2][w]) {
            w++;
        }
        while (matrix[j][2][w] < matrix[j-1][2][w]) {
            for (k = 0; k < 50; k++) {
                temp = matrix[j][0][k];
                matrix[j][0][k] = matrix[j-1][0][k];
                matrix[j - 1][0][k] = temp;

                temp = matrix[j][2][k];
                matrix[j][2][k] = matrix[j - 1][2][k];
                matrix[j - 1][2][k] = temp;
            }
            j--;
        }
    }

    printf("\n\nSoyisme gore:");
    for (i=0 ; i<n ; i++) {
        printf("\n%s%s%s", matrix[i][0], matrix[i][1], matrix[i][2]);
    }


    /*
    // Swap names and surnames
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<50 ; j++) {
            temp = matrix[i][0][j];
            matrix[i][0][j] = matrix[i][2][j];
            matrix[i][2][j] = temp;
        }
    }

    printf("\n\nSoyisme gore:");
    for (i=0 ; i<n ; i++) {
        printf("\n%s%s%s", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
    */


    return 0;
}