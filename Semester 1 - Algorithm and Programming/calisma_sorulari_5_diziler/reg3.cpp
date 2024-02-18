#include <stdio.h>


int main() {
    int i, num;
    int nums[5];

    for (i=0, num=11 ; i<5 ; num++) {
        if (num%3 == 0) {
            nums[i] = num;
            i++;
        }
    }
    
    for (i-- ; i>-1 ; i--)
        printf("%d ", nums[i]);
    
}

