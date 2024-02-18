#include <stdio.h>

int pow(int base, int n) {
    if (n == 0) {
       return 1;
    }
    return pow(base, n-1)*base;
}

int eg1(int array[10], int sample_max, int i) {
    i++;
    if (i<10 && array[i] >= sample_max) {
        return eg1(array, array[i], i);
    }
    else if (i<10) {
        return eg1(array, sample_max, i);
    }
    else {
        return sample_max;
    }
}

int eg2(int array[10], int second_max, int max, int i) {
    i++;
    if (i<10 && array[i] >= max) {
        return eg2(array, max, array[i], i);
    }
    else if (i<10) {
        return eg2(array, second_max, max, i);
    }
    else {
        return second_max;
    }
}

int eg3(int num) {
    int i, sum;
    num--;

    for (i=1, sum=0 ; i<num ; i++) {
        if (num%i == 0) {
            sum += i;
        }
    }
    if (sum == num) {
        return num;
    }
    else {
        return eg3(num);
    }
}

int eg4(int num1, int num2, int prime_count=0) {
    int i;
    bool is_prime = true;
    num2--;

    if (num2 < num1) {
        return eg4(num2, num1);
    }
    else if (num1 == num2) {
        return prime_count;
    }
    for (i=2 ; i<=num2/2 ; i++) {
        if (num2%i == 0) {
            is_prime = false;
            break;
        }
    }
    if (num2 == 1) {
        is_prime = false;
    }

    if (is_prime) {
        return eg4(num1, num2, prime_count+1);
    }
    else {
        return eg4(num1, num2, prime_count);
    }
}

int eg5(int array[10], int min, int max, int i=0) {
    i++;
    if (min > array[i]) {
        min = array[i];
    }
    if (max < array[i]) {
        max = array[i];
    }
    if (i<10) {
        return eg5(array, min, max, i);
    }
    return max-min;
}

int eg6(int num, int digit=0) {
    num /= 10;
    digit++;
    if (num != 0) {
        return eg6(num, digit);
    }

    return digit;
}

int eg7(int num, int digit, int loop=1) {
    int numl, numr;
    if (loop > digit/2) {
        return num;
    }
    numl = (num/pow(10, digit-loop))%10;
    numr = num%pow(10, loop)/pow(10, loop-1);

    num += -numl*pow(10,digit-loop) + numr*pow(10, digit-loop);
    num += -numr*pow(10, loop-1) + numl*pow(10, loop-1);

    return eg7(num, digit, loop+1);
}

int eg8(int num, int digit=0) {
    if (num == 0) {
        do {
            num += 9* pow(10, --digit);
        } while(digit>0);
        return num;
    }
    return eg8(num/10, digit+1);
}

int eg9(int array[], int size_of_array, int i=1, int count=0) {
    if (i >= size_of_array) {
        return count;
    }
    if (array[i-1] < array[i]) {
        count++;
    }
    return eg9(array, size_of_array, i+1, count);
}

void eg10(int rows, int i=1) {
    printf("\n");
    for(int j=0 ; j<i ; j++) {
        printf("*");
    }
    if (rows > 1) {
        eg10(rows-1, i+2);
    }
}

void eg11(int rows, int i=1) {
    int j;
    printf("\n");

    for(j=rows-1 ; j>0 ; j--) {
        printf(" ");
    }

    for(j=0 ; j<i ; j++) {
        printf("*");
    }
    if (rows > 1) {
        eg11(rows-1, i+2);
    }
}


int main() {
    int list[10] = {1000,452,33,14,-555,63,-70000,8,900000,10};

    printf("\neg1: %d", eg1(list, list[0],0));
    printf("\neg2: %d", eg2(list, list[0], list[0], 0));
    printf("\neg3: %d", eg3(500));
    printf("\neg4: %d", eg4(0,10));    //2,3,5,7,11
    printf("\neg5: %d", eg5(list, list[0], list[0]));
    printf("\neg6: %d", eg6(1));
    printf("\neg7: %d", eg7(15200, 5));
    printf("\neg8: %d", eg8(1234542));
    printf("\neg9: %d", eg9(list, 10));
    eg10(5);
    eg11(6);
    
    return 0;
}
