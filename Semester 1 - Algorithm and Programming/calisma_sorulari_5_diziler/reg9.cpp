#include <stdio.h>


int main() {
    int sayilar[]= { 1, 6, 5, 2, 1, 4, 2 };
    int input_num, counter, add_amount, i;
    bool is_done = false;
    
    counter = 0;
    
    while (!is_done) {
        scanf("%d", &input_num);
        add_amount = 1;
        
        for (i=0 ; i<sizeof(sayilar)/sizeof(int) ; i++) {
            if (sayilar[i] == input_num) {
                sayilar[i] = -1;
                counter += add_amount;
                add_amount = 0;
            }
        }
        
        is_done = true;
        for (i=0 ; i<sizeof(sayilar)/sizeof(int) ; i++) {
            if (sayilar[i] != -1) {
                is_done = false;
                break;
            }
        }
    }
    printf("\n%d farkli sayi vardir.", counter);
}

