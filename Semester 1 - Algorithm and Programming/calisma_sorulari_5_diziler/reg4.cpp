#include <stdio.h>


int main() {
    int i, num;
    int numbers[10];
    
    for (i=0, num=99 ; i<10 ; num--) {
        if (num%2 == 0 && num%3 != 0) {
            numbers[i] = num;
            i++;
        }
    }
    
    for (i-- ; i>-1 ; i--)
        printf("%d ", numbers[i]);
}
