#include <stdio.h>


int main() {
    int matris[10][10];
    int i, j, num;
    
    num = 7;
    for (i = 0 ; i<10 ; i++) {
        for (j=0 ; j<10 ; j++) {
            matris[i][j] = num;
            num += 7;
        }
    }
    
    for (i=9 ; i>-1 ; i--) {
        for (j=9 ; j>-1 ; j--) {
            printf("%d\t", matris[i][j]);
        }
        printf("\n");
    }
}

