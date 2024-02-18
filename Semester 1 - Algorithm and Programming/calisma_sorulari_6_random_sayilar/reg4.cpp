#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int i, n, num;
    double delta_max, delta;  // delta_min = 5;
    bool in_range;
    
    printf("N: ");
    scanf("%d", &n);
    
    if (n>13)
        printf("There is no possible series of numbers for n");
    
    else {
        if (n > 1)
            delta_max = 65/n;
        
        for (i=delta=0 ; i<n ; i++) {
            if (i == 0) {
                num = 10 + rand()%(int)delta_max;
            }
            
            else {
                in_range = false;
                while (!in_range) {
                    delta = 5 + rand()%61;
                    if (delta > 5 && delta < delta_max)
                        in_range = true;
                }
            }
            
            num += delta;
            printf("\n%d", num);
        }     
    }
    
    
}

