#include <stdio.h>


main() {
    int matris[10][10];
    int i, j, num;
    num = 7;
    
    for(i=0 ; i<10 ; i++) {
        for(j=0 ; j<10 ; j++) {
            matris[i][j] = num;
            num += 7;
        }
    }
    
    for(i--; i>=0 ; i--) {
        for(j=9; j>=0 ; j--)
            printf("%d  ", matris[i][j]);
    }
    
    return 0;
}
