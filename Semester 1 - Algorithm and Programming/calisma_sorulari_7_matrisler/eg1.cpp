#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int i, j, n, max_num, min_num, sum;
    float mean;
    
    printf("N: ");
    scanf("%d", &n);
    int matrix[n][n];
    
    for (i=sum=0 ; i<n ; i++) {
        printf("\n\n");
        for (j=0 ; j<n ; j++) {
            sum += matrix[i][j] = rand()%100;
            printf("%6d", matrix[i][j]);
            if (i == 0 && j == 0) {
                max_num = min_num = matrix[i][j];
                continue;
            }
            if (matrix[i][j] > max_num) {
                max_num = matrix[i][j];
            }
            else if (matrix[i][j] < min_num) {
                min_num = matrix[i][j];
            }
        }
    }
    
    mean = (float)sum/(n*n);
    printf("\n\n Min number: %d\n Max number: %d\n Mean: %f", min_num, max_num, mean);
}