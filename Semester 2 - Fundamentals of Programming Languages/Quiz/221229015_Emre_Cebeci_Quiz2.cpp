#include <stdio.h>

int pow(int base, int n) {
    if(n==0) {
        return 1;
    }
    return pow(base, n-1)*base;
}

void binary_print(char num) {
    for(int i=sizeof(char)*8-1; i>-1; i--) {
        if(i%4==3) {
            printf(" ");
        }
        printf("%d", (num>>i)&1);
    }
}
                                           // 7654 3210
unsigned char swapper(unsigned char num) { // 1100 1011
    unsigned char part1, part2;
    part1=part2=0;

    part1 += num&3;
    part1 <<=2;
    part1 += (num&12)>>2;

    num>>=4;
    part2 += num&3;
    part2 <<=2;
    part2 += (num&12)>>2;


    return part1|(part2<<4);

}

int main() {
    unsigned char num;
    printf("Sayi: ");
    scanf("%d", &num);

    printf("\nGirilen sayi: ");
    binary_print(num);
    printf("\nSonuc: ");
    binary_print(swapper(num));
    return 0;
}