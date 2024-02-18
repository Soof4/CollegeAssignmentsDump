#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FORWARD 1
#define BACKWARD 0

void report_round(int array1[][2], int size1, int array2[][2], int size2);


int main() {
    srand(time(NULL));
    int i, j, n1, n2, skip_num, direction;
    
    printf("N1: ");
    scanf("%d", &n1);
    int numbers1[n1][2];  // numbers[i][0] sayiyi temsil ederken, 
                          // numbers[i][1] durumu temsil edecek (oyunda mi, degil mi)
    printf("N2: ");
    scanf("%d", &n2);
    int numbers2[n2][2];
    
    // -------- Generate numbers
    for (i=0 ; i<n1 ; i++)
        do {
            numbers1[i][0] = rand()%21 - 10;
            numbers1[i][1] = 1;
        } while (numbers1[i][0] == 0);  // eger sayilardan biri 0 gelirse oyun 
                                        // ilerlemeyecegi icin 0 gelmesini engelledim
    
    for (i=0 ; i<n2 ; i++)
        do {
            numbers2[i][0] = rand()%21 - 10;
            numbers2[i][1] = 1;
        } while (numbers2[i][0] == 0);
    
    // -------- Game logic
    for (i=j=0 ; i < n1+n2 ; i++) {
        report_round(numbers1, n1, numbers2, n2);
        
        // ---- Find the number of steps
        if (j<n1)
            skip_num = numbers1[j][0];
        else
            skip_num = numbers2[j-n1][0];
        
        
        if (i>0 && j<n1 && i<n1+n2-1) {
            printf("\n%d cikti. ", skip_num);
        }
        else if (i>0 && i<n1+n2-1) {
            printf("\n%d cikti. ", skip_num);
        }
        else if (i<n1+n2-1)
            printf("\n");
        
        // ---- Find the direction
        if (skip_num>0) {
            direction = FORWARD;
            if (i<n1+n2-1)
                printf("%d oldugu icin, %d adim ileri.", skip_num, skip_num);
        }
        else {
            direction = BACKWARD;
            skip_num *= -1;
            if (i<n1+n2-1)
                printf("%d oldugu icin, %d adim geri.", -1*skip_num, skip_num);
        }
            
        do {
            // ---- Adjustment of j
            if (direction == FORWARD) {
                j++;
                while (j>=n1+n2)
                    j -= n1+n2;
            }
                
            else {
                j--;
                while (j<0)
                    j = n1+n2-1;
            }
            
            // ---- Check and skip
            if (j<n1 && numbers1[j][1] == 1) {
                skip_num--;
            }
            
            if (j >= n1 && numbers2[j-n1][1] == 1) {
                skip_num--;
            }
            
        } while (skip_num != 0);
        
        // ---- End of round
        if (j<n1)
                numbers1[j][1] = 0;
            else
                numbers2[j-n1][1] = 0;
                
    }
    
    // -------- Game end
    if (j < n1)
        printf("\n\nSonuc olarak ilk dizinin %d sayili %d. Elemani oyunu kazanmistir.", numbers1[j][0], j+1);
    else
        printf("\n\nSonuc olarak ikinci dizinin %d sayili %d. Elemani oyunu kazanmistir.", numbers2[j-n1][0], j-n1+1);
        
}


void report_round(int array1[][2], int size1, int array2[][2], int size2) {
    int i;
    printf("\n|");
    for (i=0 ; i<size1 ; i++) {
        if (array1[i][1] == 1)
            printf("%3d    ", array1[i][0]);
        else
            printf("%3d(X) ", array1[i][0]);
    }
    
    printf("||   ");
    
    for (i=0 ; i<size2 ; i++) {
        if (array2[i][1] == 1)
            printf("%3d     ", array2[i][0]);
        else
            printf("%3d(X)  ", array2[i][0]);
    }
    printf("|\n");
}

