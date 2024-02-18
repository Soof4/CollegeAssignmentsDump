#include <stdio.h>


main() {
    int i, j, num, counter;
    int digits[4];
    
    for(i=1000, counter=0 ; i<10000 ; i++) {
        num = i;
        
        j=0;
        while(num>0) {
            digits[j] = num % 10;  //digits[0] = birler basamagi
            j++;
            num /= 10;
        }
        
        if((digits[0] + digits[1]) == (digits[2] + digits[3]))
            counter++;
    }
    
    printf("%d", counter);
}
