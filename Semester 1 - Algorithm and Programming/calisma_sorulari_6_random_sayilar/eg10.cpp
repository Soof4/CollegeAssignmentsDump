#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int i, j, n, rand_index, max, total, record_i;
    
    printf("N: ");
    scanf("%d", &n);
    
    int numbers[n];
    
    for (i=0 ; i<n ; i++)
        numbers[i] = 0;
    
    for (i=0 ; i<n ; i++) {
        if (i%2==0) {
            while ( numbers[(rand_index = rand()%n)] != 0);
            numbers[rand_index] = -1 * (rand()%10 + 1);
        }
        else {
            while ( numbers[(rand_index = rand()%n)] != 0);
            numbers[rand_index] = (rand()%10 + 1);
        }
    }
    
    for (i=record_i=0 ; i<=n/2 ; i++) {
        total = 0;
        if (i==0) {
            for (j=0 ; j<n/2 ; j++)
                total += numbers[j];
            max = total;
            continue;
        }
        
        for (j=i ; j<n/2 ; j++) {
            total += numbers[j];
        }
        
        if (total > max) {
            max = total;
            record_i = i;
        }  
    }
    
    printf("\n\nDizi: ");
    for(i=0 ; i<n ; i++)
        printf("%d  ", numbers[i]);
    printf("\n\nEn yuksek ort verenler: ");
    for (i=0 ; i<n/2 ; i++)
        printf("%d  ", numbers[record_i+i]);
}

