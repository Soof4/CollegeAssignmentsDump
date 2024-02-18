#include <stdio.h>


int main() {
    int sayilar[] = { 10,15,20,33,22,11,9,8,48,47,12,25,12,21 };
    int i, query;
    
    printf("Aranacak sayi: ");
    scanf("%d", &query);
    
    for (i=0 ; i<sizeof(sayilar)/sizeof(int) && sayilar[i] != query ; i++);
    
    if (i == sizeof(sayilar)/sizeof(int))
        printf("Bu sayi dizide bulunmamaktadir.");
    else
        printf("Bu sayi %d. siradadir.", ++i);
    
}
