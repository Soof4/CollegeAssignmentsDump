#include <stdio.h>

int main(){
	int nums[4];
	int i;
	double ort;
	
	for (i=0; i < 4; ++i) {
	    printf("Sayi girin: ");
	    scanf("%d", &nums[i]);
	}
	
	for (i=0; i < 4; ++i) {
	    ort += nums[i];
	}
	
	ort /= i;
	printf("Ort: %f", ort);
	
	for (i=0; i < 4; ++i) {
	    if (nums[i] > ort)
	        printf("\nOrt.dan buyuk: %d", nums[i]);
	    
	    else if (nums[i] < ort)
	        printf("\nOrt.dan kucuk: %d", nums[i]);
	    
	    else
	        printf("\nOrt.ya esit: %d", nums[i]);
	        
	}
	
}