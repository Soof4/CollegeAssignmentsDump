#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    
    int i, n, total, num;
    float mean;
    
    printf("N: ");
    scanf("%d", &n);
    
    int numbers[n];
    
    for (i=total=0 ; i<n ; i++) {
        num = rand()%101;
        total += num;
        numbers[i] = num;
    }
    
    mean = (float)total/n;
    printf("mean: %f", mean);
    
    for (i=0 ; i<n ; i++) {
        if (numbers[i] < mean)
            numbers[i] = mean + rand()%(int)(101-mean)+1;
        printf("\n%d", numbers[i]);
    }
    
    printf("\n\n");
}

