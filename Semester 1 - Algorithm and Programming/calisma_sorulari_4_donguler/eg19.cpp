#include <stdio.h>
#define NUMBER 10000


main() {
    
    int i, j, num;
    int digits[4];
    
    for( i=NUMBER-1; i>0 ; i--) {
        num = i;
        j = 0;
        while(num>0) {
            digits[j] = num % 10;
            num /= 10;
            j++;
        }
        
        if(digits[0] != digits[1] && digits[0] != digits[2] && digits[0] != digits[3] && digits[1] != digits[2] && digits[1] != digits[3] && digits[2] != digits[3]) {
            printf("%d", i);
            break;
        }
    }
    
    
    
    
    
}
