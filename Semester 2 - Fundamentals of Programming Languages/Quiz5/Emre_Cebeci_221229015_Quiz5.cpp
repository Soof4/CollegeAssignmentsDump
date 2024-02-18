#include <stdio.h>

int main() {
    int nums[]= { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
    int *ptr, *endPtr, counter;

    endPtr = &nums[sizeof(nums)/sizeof(int)-1];
    ptr = nums;
    counter = 0;

    while(ptr < endPtr) {
        if(*ptr%2==0 && *(ptr+1)%2==0) {
            printf("%d-%d  ", *ptr, *(ptr+1));
            counter++;
        }
        ptr++;
    }
    printf("\nToplam %d adet cift bulunmustur.", counter);

    return 0;
}

