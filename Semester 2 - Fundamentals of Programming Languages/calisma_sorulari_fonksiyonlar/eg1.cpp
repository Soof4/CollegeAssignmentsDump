#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000

int find_item_location(int array[], int query) {
    int location = -1;
    int i;

    for (i=0 ; i<8 ; i++) {
        if (array[i] == query) {
            location = i+1;
            break;
        }
    }
    return location;
}    // eg1

float find_mean(int num1, int num2) {
    float mean = 0;
    int temp, num_of_3x;

    if (num2 < num1) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    num_of_3x = 0;
    num1++;
    while (num1 < num2) {
        if (num1%3 == 0) {
            mean += num1;
            num_of_3x++;
        }
        num1++;
    }
    if (num_of_3x != 0) {
        mean /= num_of_3x;
    }

    return mean;
}    // eg2

int find_prime(int num) {
    num--;
    int i;

    while (num>2) {

        for (i=2 ; i<=num; i++) {
            if (i == num) {
                return num;
            }
            if (num%i == 0) {
                break;
            }

        }
        num--;
    }

    return -1;
}    // eg3

int find_char_reversed(char array[], char query) {
    int i, size;
    size = strlen(array);
    i=1;
    while (i<=size) {
        if (array[size-i] == query) {
            return i;
        }
        i++;
    }

    return -1;
}     // eg4

char* replace_char(char string[], char oldc, char newc) {
    int i;

    for (i=0 ; string[i] != '\0' ; i++) {
        if (string[i] == oldc) {
            string[i] = newc;
        }
    }

    return &string[0];
}    //eg5

char* replace(char mains[], char oldp[], char newp[]) {
    int i, j, k, w, main_size, found_count;
    char news[MAX_ARRAY_SIZE];
    main_size = strlen(mains);
    found_count = 0;

    for (i=j=0 ; i<main_size ; i++) {    //mains -> i, news -> j
        for (k=w=0 ; k<strlen(oldp) ; k++) {
            if (mains[i+k] == oldp[k]) {
                w++;
            }
        }
        if (w == strlen(oldp)) {
            for (k=0 ; k<strlen(newp) ; k++) {
                news[j++] = newp[k];
            }
            i += strlen(oldp)-1;
        }
        else {
            news[j++] = mains[i];
        }
    }

    for (i=0 ; i<strlen(news) ; i++) {
        mains[i] = news[i];
    }
    mains[i] = '\0';

    return &mains[0];
}    //eg6

/* int* eg9(int n1, int n2) {
    srand(time(NULL));
    int array1[n1], array2[n2];
    int i, j, temp;

    for (i=0 ; i<n1 ; i++) {
        array1[i] = rand()%100;
    }
    for (i=0 ; i<n2 ; i++) {
        array2[i] = rand()%100;
    }

    for (i=1 ; i<n1 ; i++) {
        j=i;
        while (j>0 && array1[j-1] > array1[j]) {
            temp = array1[j-1];
            array1[j-1] = array1[i];
            array1[j] = temp;
            j--;
        }
    }

    for (i=1 ; i<n1 ; i++) {
        j=i;
        while (j>0 && array2[j-1] > array2[j]) {
            temp = array2[j-1];
            array2[j-1] = array2[i];
            array2[j] = temp;
            j--;
        }
    }






    return &merged_array[0];
}
*/    // eg9    (f-up eg)

char* substring(char string[], int start_index, int length) {
    static char new_string[MAX_ARRAY_SIZE];
    int i;
    for (i=0 ; i<length ; i++) {
        new_string[i] = string[start_index+i];
    }
    new_string[i] = '\0';

    return &new_string[0];
}

char* upper(char string[]) {
    for (int i=0 ; i<strlen(string) ; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 32;
        }
    }
    return &string[0];
}

char* lower(char string[]) {
    for (int i=0 ; i< strlen(string) ; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 32;
        }
    }
    return &string[0];
}

char* reverse(char string[]) {
    int i, size, temp;
    size = strlen(string);

    for (i=0 ; i<size/2 ; i++) {
        temp = string[i];
        string[i] = string[size-i-1];
        string[size-i-1] = temp;
    }

    return &string[0];
}

int obeb(int num1, int num2) {
    int temp;
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    while (num1 > 0) {
        temp = num1;
        num1 = num2%num1;
        num2 = temp;
    }
    return num2;
}

int okek(int num1, int num2) {
    return (num1*num2)/obeb(num1,num2);
}

int combination(int num1, int num2) {
    int result = 1;
    for (int i=0 ; i<num2 ; i++) {
        result *= num1 - i;
        result /= i+1;
    }
    return result;
}

int* sort(int array[], int size) {
    int i,j, temp;
    for (i=1 ; i<size ; i++) {
        j=i;
        while (j>0 && array[j-1] > array[j]) {
            temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;
            j--;
        }
    }
    return &array[0];
}





int main() {

    /*
    int dizi[8]={1, 2, 5, 12, 20, 50, 4, 30};

    printf("Sonuc: %d", find_item_location(dizi, 12));
    */

    // // // // // // // // // // // // // // // // // //

    /*
    int num1, num2;

    printf("\nnum1: ");
    scanf("%d", &num1);

    printf("\nnum2: ");
    scanf("%d", &num2);

    float mean = find_mean(num1, num2);

    printf("\nmean: %f", mean);
    */

    // // // // // // // // // // // // // // // // // //

    /*
    int num;
    printf("num: ");
    scanf("%d", &num);

    printf("\nsonuc: %d", find_prime(num));
    */

    // // // // // // // // // // // // // // // // // //

    /*
    char charDizi[]="Programlamanin Temeli";
    char q = 'P';

    printf("\nsonuc: %d", find_char_reversed(charDizi, q));
    */

    // // // // // // // // // // // // // // // // // //

    /*
    char str[] = "MERHABA";
    printf("%s", replace_char(str, 'A', 'X'));
    */

    // // // // // // // // // // // // // // // // // //

    /*
    char str[] = "yazilimcilar yazilim yazar yaz aylarinda";

    printf("%s", replace(str, "yaz", "ABCD"));
    */

    // // // // // // // // // // // // // // // // // //

    /*
    char strin[] = "yazilimcilar";

    printf("%s", substring(strin, 3, 4));
    */

    // // // // // // // // // // // // // // // // // //

    /*
    printf("%d", combination(17, 4));
    */

    // // // // // // // // // // // // // // // // // //

    /*
    int dizi[] = {1, -5,5,8,5,6,54,3,3,-3,0,10,9,98,54};
    sort(dizi, 14);
    for (int i=0 ; i<14 ; i++) {
        printf("%3d", dizi[i]);
    }
    */

    // // // // // // // // // // // // // // // // // //
    char str1[] = "yazilimcilar yazilim yazar yaz aylarindaj";
    char olds[] = "yaz";
    char news[] = "ABCD";

    printf("%s", replace(str1, olds, news ));


}