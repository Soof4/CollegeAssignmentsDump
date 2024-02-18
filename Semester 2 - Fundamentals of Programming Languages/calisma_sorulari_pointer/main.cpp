#include <stdio.h>

/*
bool check(int *array, int size) {
    for(int i=0; i<size; i++) {
        if(*array != -1) {
            return false;
        }
        array++;
    }
    return true;
}
*/// part of eg9

int main() {
    /*
    int n, num, n_index, p_index, i;
    printf("N: ");
    scanf("%d", &n);
    int pos[n], neg[n];

    for(i=p_index=n_index=0; i<n; i++) {
        printf("%d. Sayi: ", i+1);
        scanf("%d", &num);

        if(num<0) {
            *(neg+n_index) = num;
            n_index++;
        }
        else {
            *(pos+p_index) = num;
            p_index++;
        }
    }

    printf("\n Neg sayilar: ");
    for(i=0; i<n_index; i++) {
        printf("%d ", neg[i]);
    }
    printf("\nPos Sayilar: ");
    for(i=0; i<p_index; i++) {
        printf("%d ", pos[i]);
    }
    */// eg1

    /*
    int num, counter;
    int array[200];
    int *ptr = array;

    num = counter = 0;

    while (num != -1) {
        printf("\nSayi: ");
        scanf("%d", &num);
        if(num>0) {
            *ptr = num;
            ptr++;
        }
    }

    double mean = 0;
    int *ip;
    for(ip = array; ip<ptr; ip++) {
        mean += *ip;
        counter++;
    }

    mean /= counter;

    printf("\nMean: %f", mean);
    */// eg2

    /*
    int array[5], num;
    int *ptr = array;

    num = 11;
    for(int i=0; i<5; num++) {
        if(num%3==0) {
            *ptr = num;
            i++;
            ptr++;
        }
    }
    ptr--;

    while(ptr!=array-1) {
        printf("%d ", *ptr);

        ptr--;
    }
    */// eg3

    /*
    int array[10], *ptr=array, num=99;

    for(int i=0; i<10; num--) {
        if(num%2 == 0 && num%3 != 0) {
            *ptr = num;
            ptr++;
            i++;
        }
    }

    ptr--;
    while(ptr!=array-1) {
        printf("%d ", *ptr);
        ptr--;
    }
    */// eg4

    /*
    int nums[] = { 10,15,20,33,22,11,9,8,48,47,12,25,12,21 };
    int *ptr = nums, query, elementCount;
    elementCount = sizeof(nums)/sizeof(int);

    printf("\nQuery: ");
    scanf("%d", &query);

    while(ptr != nums+elementCount-1) {
        if(*ptr == query) {
            printf("\n%d. siradadir.", ptr-nums+1);
            return 0;
        }
        ptr++;
    }
    printf("\nBulunamadi.");
    */// eg5

    /*
    int nums[]= { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
    int *ptr, counter;
    ptr = &nums[13];
    counter = 0;

    while(ptr != nums) {
        if(*ptr%2==0 && *(ptr-1)%2==0) {
            counter++;
        }
        ptr--;
    }
    printf("\nSonuc: %d", counter);
    */// eg6

    /*
    int nums[]= { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
    int i, *ptr;

    for(ptr=nums; ptr<nums+sizeof(nums)/sizeof(int); ptr++) {
        if(*ptr%2==0) {
            (*ptr)++;
        }
    }

    for(ptr=nums; ptr<nums+sizeof(nums)/sizeof(int); ptr++) {
        printf("%d ", *ptr);
    }
    */// eg7

    /*
    int nums[]= { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
    int *ptr, counter;
    double mean = counter = 0;

    for(ptr=nums+1; ptr<nums+ sizeof(nums)/sizeof(int); ptr+=2) {
        mean += *ptr;
        counter++;
    }
    mean /= counter;
    printf("\nOrtalama: %.2f\n", mean);

    for(ptr=nums+1; ptr<nums+ sizeof(nums)/sizeof(int); ptr+=2) {
        if(*ptr>mean) {
            printf("%d ", *ptr);
        }
    }
    */// eg8

    /*
    int nums[]= { 1, 6, 5, 2, 1, 4, 2 };
    int num, arraySize, numVariety;
    bool found;

    numVariety = 0;
    arraySize = sizeof(nums)/sizeof(int);
    while(!check(nums, arraySize)) {
        printf("\nSayi girin: ");
        scanf("%d", &num);

        found = false;
        for(int i=0; i<arraySize; i++) {
            if(*(nums+i) == num) {
                *(nums+i) = -1;
                found = true;
            }
        }
        if(found) {
            numVariety++;
        }
    }

    printf("\n Farkli sayi adeti: %d", numVariety);
    */// eg9

    /*
    int matrix[10][10];
    int *ptr = matrix[0];

    for(int i=1; i<101; i++) {
        *ptr = 7*i;
        ptr++;
    }

    ptr = &matrix[9][9];
    for(int i=0; i<10; i++) {
        printf("\n");
        for(int j=0; j<10; j++) {
            printf("%4d", *ptr);
            ptr--;
        }
    }
    */// eg10

    return 0;
}