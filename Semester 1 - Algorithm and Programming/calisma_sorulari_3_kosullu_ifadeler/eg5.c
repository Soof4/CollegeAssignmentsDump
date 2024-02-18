#include <stdio.h>

int main() {
	double x, y;
	
	printf("X: ");
	scanf("%lf", &x);
	
	
	if (x < 0)
	    y = 3*x*x;
	    
	else if (x < 10)
	    y = 1/(x*x);
	    
	else
	    y = 5*x*x - x*x*x;
	
	
	printf("y = %f", y);
	
}