#include <stdio.h>


main() {
    
    int i, start_num;
    int numbers[10];
    
    start_num = 100;
    
    for(i=9 ; i>=0 ;) {
        start_num--;
        
        if(start_num % 2 == 0 && start_num % 3 != 0) {
            numbers[i] = start_num;
            i--;
        }
    }
    
    for(i=0 ; i<10 ; i++)
        printf("%d  ", numbers[i]);

    return 0;
}
