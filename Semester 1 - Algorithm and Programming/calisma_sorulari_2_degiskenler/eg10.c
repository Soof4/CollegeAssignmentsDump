#include <stdio.h>

main(){
	int num, digit_amount, s_num;
	
	printf("Bir tam sayı giriniz: ");
	scanf("%d", &num);
	
	if (num < 0)
	    num *= -1;
	    
	s_num = num;
	
	if (num == 0)
	    printf("1. Basamak: 0");
	    
	else {
	    digit_amount = 0;
	    
	    while (s_num > 0) {
            s_num /= 10;
	        digit_amount += 1;
	    }
	    
	    ++digit_amount;
	    
    	while (num > 0) {
    	    printf("\n%d. Basamak = %d", --digit_amount, num % 10);
    	    num /= 10;
    	    
    	}
	}
	
	
}