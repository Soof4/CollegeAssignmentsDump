#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int i, j, n, m, sum, success;
    
    printf("N: ");
    scanf("%d", &n);
    printf("M: ");
    scanf("%d", &m);
    float grades[n+1][m];
    
    printf("      ");
    for (i=0 ; i<m ; i++)
        printf(" %4d.Ders", i+1);
    printf("    Ortalama");
    
    for (i=success=0 ; i<n ; i++) {
        printf("\n%d.Og.:", i+1);
        for (j=sum=0 ; j<m ; j++) {
            grades[i][j] = rand()%101;
            sum += grades[i][j];
            printf("%10.f", grades[i][j]);
            if (j == m-1) {
                grades[i][++j] = (float)sum/m;
                printf("%12.2f", grades[i][j]);
                if (grades[i][j] > 50) {
                    success++;
                }
            }
        }
    }
    
    printf("\nGecen kisi sayisi: %d", success);
}