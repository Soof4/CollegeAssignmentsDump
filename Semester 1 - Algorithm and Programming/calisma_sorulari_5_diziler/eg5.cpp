#include <stdio.h>


main() {
    int sayilar[] = {10,15,20,33,22,11,9,8,48,47,12,25,12,21};
    int i, input_num;
    
    printf("Aranacak sayi: ");
    scanf("%d", &input_num);
    
    bool is_found = false;
    for(i=0 ; i<sizeof(sayilar)/sizeof(int) ; i++) {
        
        if(sayilar[i] == input_num) {
            printf("Sayi %d. siradadir", i+1);
            is_found = true;
            break;
        }
    }
    
    if(!is_found)
        printf("Bu sayi dizide bulunmamaktatir.");
    
}
