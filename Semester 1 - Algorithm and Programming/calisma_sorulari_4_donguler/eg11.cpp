#include <stdio.h>


main() {
    int last_num, input, counter;
    
    printf("Sayi: ");
    scanf("%d", &last_num);
    input = last_num;
    counter = 0;
    
    while( input != 0 ) {
        printf("Sayi: ");
        scanf("%d", &input);
        
        if( input > last_num )
            counter++;
        
        last_num = input;
    }
    
    printf("\nKendisinden bir once girilen sayidan buyuk olan sayi adeti: %d", counter);
}
