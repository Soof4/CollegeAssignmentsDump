#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define USED -10


int pow(int base, int n) {
    if(n == 0) {
        return 1;
    }
    return pow(base, n-1)*base;
}
void binary_print(int num) {
    int i, bit, bits[32];
    for(i=0; i<32; i++) {
        bit = num&1;
        num = num>>1;
        bits[i] = bit;
    }

    i--;
    while(i>-1) {
        if(i%4 == 3) {
            printf(" ");
        }
        printf("%d", bits[i]);
        i--;
    }
}


int encode(int array[], int array_size) {
    int i, j, k, max;
    unsigned encoded_data;
    encoded_data = 0;

    for(i=0; i<array_size; i++) {
        max = -8;
        for(j=k=0; j<array_size; j++) {
            if (array[j] > max) {
                max = array[j];
                k = j;
            }
        }
        encoded_data <<= 4;

        if(max<0) {
            encoded_data -= max;
            encoded_data = encoded_data|0x8;
        }
        else {
            encoded_data += max;
        }
        array[k] = USED;
    }
    return encoded_data;
}


void decode(int encoded_data, int num_count, int convert_type) {
    int i;
    if(convert_type==2) {
        for(i=num_count-1; i>-1; i--) {
            printf("\n");
            if((encoded_data>>(i*4)&8) > 0) {
                binary_print(encoded_data>>(i*4)&0x7| pow(2,31));
            }
            else {
                binary_print(encoded_data>>(i*4));
            }
            encoded_data<<=4*(8-i);
            encoded_data>>=4*(8-i);
        }
    }
    else {
        for(i=num_count-1; i>-1; i--) {
            if((encoded_data>>(i*4)&8) > 0) {
                printf("-");
            }
            printf("%d ", encoded_data>>(i*4)&0x7);
            encoded_data<<=4*(8-i);
            encoded_data>>=4*(8-i);
        }
    }

    // ilk versiyon
    /*int i;
    if(convert_type==2) {
        for(i=0; i<num_count; i++) {
            printf("\n");
            if((encoded_data>>3&1) == 1) {
                binary_print((encoded_data&0x7)|pow(2,32));
            }
            else {
                binary_print(encoded_data&0x7);
            }

            encoded_data >>= 4;
        }
    }
    else {
        for(i=0; i<num_count; i++) {
            if((encoded_data>>3&1) == 1) {
                printf("-");
            }
            printf("%d ", encoded_data&0x7);
            encoded_data >>= 4;
        }
    }*/
}


int main() {
    srand(time(NULL));
    int n, i, result;

    printf("\nKac sayi uretilecek: ");
    scanf("%d", &n);
    if(n>8 | n<=0) {
        printf("\nN, 1-8 yalnizca arasi degerler olabilir.");
        return main();
    }
    int nums[n];

    printf("Uretilen dizi: ");
    for(i=0; i<n; i++) {
        nums[i] = rand()%15 -7;
        printf("%d ", nums[i]);

    }

    result = encode(nums, n);

    printf("\n\nOnluk tabanda sonuc: %d", result);
    printf("\n\nIkilik tabanda sonuc: ");
    binary_print(result);
    printf("\n\nIkilik tabanda buyukten kucuge: ");
    decode(result, n, 2);
    printf("\n\nOnluk tabanda buyukten kucuge: ");
    decode(result, n, 10);
    return 0;
}
