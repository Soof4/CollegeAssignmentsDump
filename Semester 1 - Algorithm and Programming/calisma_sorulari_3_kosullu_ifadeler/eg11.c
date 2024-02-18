#include <stdio.h>


int main(){
	int nums[6];
	int i, max, under_max;
	
	for (i=0; i < 6; ++i) {
	    printf("%d. Sayi: ", i+1);
	    scanf("%d", &nums[i]);
	}
	
	max = nums[0];
	
	for (i=0; i < 6; ++i) {
        if (nums[i] > max) {
            under_max = max;
	        max = nums[i];
        }
        
	    else if (nums[i] > under_max && nums[i] < max)
            under_max = nums[i];
    }
    
	printf("\nEn buyuk ikinci sayi: %d", under_max);
}
