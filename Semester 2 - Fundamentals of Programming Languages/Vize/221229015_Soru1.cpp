#include <stdio.h>

void ikilikTabandaGoster(int sayi) {
    for(int i=sizeof(int)*8-1; i>-1; i--) {
        if(i%4==3) {
            printf(" ");
        }
        printf("%d", (sayi>>i)&1);
    }
}


int main() {
    int sayi;
    printf("\nSayi girin: ");
    scanf("%d", &sayi);
    ikilikTabandaGoster(sayi);
    return 0;
}