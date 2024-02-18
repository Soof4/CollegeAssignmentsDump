#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 297

void filler(char matrix[MAX_SIZE][MAX_SIZE], int n, int x=0, int y=0) {
    
    int i, j, rand_num;
    char set[9][2] = {1,0,2,0,3,0,4,0,5,0,
                      6,0,7,0,8,0,9,0};

    for (i=x ; i<x+3 ; i++) {
        for (j=y ; j<y+3 ; j++) {
            do {
                rand_num = rand()%9;
            } while (set[rand_num][1] == 1);
            matrix[i][j] = set[rand_num][0];
            set[rand_num][1] = 1;
        }
    }

    if (y != n-3) {
        return filler(matrix, n, x, y+3);
    }
    else if (x != n-3) {
        return filler(matrix, n,x+3, 0);
    }
}


int main() {
    srand(time(NULL));
    int i, j, n;
    char matrix[MAX_SIZE][MAX_SIZE];


    printf("\nN: ");
    scanf("%d", &n);
    if (n%3 != 0 || n<3) {
        printf("N, 3 veya 3'un kati olmali.");
        return main();
    }
    if (n > MAX_SIZE) {
        printf("Girilen sayi cok buyuk.");
        return main();
    }

    filler(matrix, n);

    for (i=0 ; i<n ; i++) {
        printf("\n");
        for (j=0 ; j<n ; j++) {
            printf("%2d", matrix[i][j]);
        }
    }
    return 0;
}
