#include <stdio.h>


main() {
    int sayilar[]= { 1, 6, 5, 2, 1, 4, 2 };
    int i, input_num, check_counter;
    int counter = 0;
    
    bool is_counting = true;
    bool counted_this_round;
    
    while(is_counting) {
        
        printf("Bir sayi girin: ");
        scanf("%d", &input_num);
        
        counted_this_round = false;
        
        for(i=0 ; i<sizeof(sayilar)/sizeof(int) ; i++) {
            if(sayilar[i] == input_num) {
                sayilar[i] = -1;
                if(!counted_this_round) {
                    counter++;
                    counted_this_round = true;
                }
            }
        }
        
        
        for(i=0, check_counter=0 ; i<sizeof(sayilar)/sizeof(int) ; i++) {
            if(sayilar[i] == -1)
                check_counter++;
        }
        
        if(check_counter == sizeof(sayilar)/sizeof(int))
            is_counting = false;
        
    }
    
    printf("Sonuc: %d", counter);
    
    
    
    
    
    return 0;
}
