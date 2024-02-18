#include <stdio.h>
#define NUMBER_AMOUNT 20


main() {
    
    int i, num, counter;
    int numbers[NUMBER_AMOUNT];
    
    counter = 0;
    num = 10;
    while(counter < NUMBER_AMOUNT) {
        num++;
        
        if(num % 3 == 0 && num % 2 != 0) {
            numbers[counter] = num;
            counter++;
        }
    }
    for(counter-- ; counter>=0 ; counter--)
        printf("%10d ", numbers[counter]);
}
