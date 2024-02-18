#include <stdio.h>

main() {
    
    int i, num, total;
    
    printf("Bir sayi girin: ");
    scanf("%d", &num);
    
    total = 0;
    for( i=1 ; i <= num/2.0 ; i++ ) {
        
        if( num % i == 0 ) {
            total += i;
        }
    }
    
    if( total == num )
        printf("%d bir mukemmel sayidir.\n\n", num);
    else
        printf("%d bir mukemmel sayi degildir.\n\n", num);
    
    
    main();
    return 0;
}
