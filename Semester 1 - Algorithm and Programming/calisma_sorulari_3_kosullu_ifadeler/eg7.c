#include <stdio.h>

int main() {
	
	int sides[3];
	int i;
	
	for (i=0; i < 3; ++i) {
	    printf("%d. Kenar: ", i+1);
	    scanf("%d", &sides[i]);
	}
	
	if ((sides[0] == sides[1]) && (sides[0] == sides[2]))
	    printf("Eskenar ucgendir.\n");
	    
	else if ((sides[0] == sides[1]) || (sides[0] == sides[2]) || (sides[1] == sides[2]))
	    printf("Ikizkenar ucgendir.\n");
	    
	else
	    printf("Cesitkenar ucgendir.\n");
	
	return 0;
	
}