#include <stdio.h>


int pow(int base, int n) {
    if(n==0) {
        return 1;
    }
    return pow(base, n-1)*base;
}

void binary_print(long long num) {
    for(int i=sizeof(long long)*8-1; i>-1; i--) {
        if(i%4==3) {
            printf(" ");
        }
        printf("%lld", (num>>i)&1);
    }
}

void count_bits(int num, int i=sizeof(int)*8-1, int ones=0, int zeros=0) {
    if(i==-1) {
        printf("\n0 sayisi: %d\n1 sayisi: %d", zeros, ones);
        return;
    }
    if(((num>>i)&1) == 1) {
        count_bits(num, --i, ++ones, zeros);
    }
    else {
        count_bits(num, --i, ones, ++zeros);
    }
}

int complement(int num, int i=0) {
    if(i>31) {
        return num;
    }
    if(((num>>i)&1) == 1) {
        num -= pow(2, i);
    }
    else {
        num += pow(2,i);
    }
    return complement(num, i+1);
}

int diff_couple(int num, int count=0, int i=1) {
    if(i>31) {
        return count; // 0000 0000 0000 0000   0000 0000 0000 0101
    }
    if((num>>i&1) != (num>>(i-1)&1)) {
        count++;
    }
    return diff_couple(num, count, i+1);
}

char swap_quadriple(char num) {
    char res =  num&(pow(2,4)-1);
    res <<= 4;
    res += num>>4&(pow(2,4)-1);
    return res;
}

int min_encode(char num1, char num2) {
    int res = num1;
    res <<= 8;
    res += num2;
    return res;
}


long long encode(int array[8]) {
    long long res;
    for(int i=res=0; i<8; i++) {
        res <<= 8;
        res += array[i];
    }
    return res;
};

int decode(long long encoded_num) {
    for(int i=0; i<8; i++) {
        printf("%lld ", encoded_num&(pow(2,8)-1));
        encoded_num >>= 8;
    }
}

int main() {
    int numbers[8]={10, 20 , 30 , 40, 50 , 60 , 70, 80};

    for(int i=0; i<8; i++) {
        binary_print(numbers[i]);
        printf("\n");
    }

    binary_print(encode(numbers));
    printf("\n");
    decode(encode(numbers));


    return 0;
}
