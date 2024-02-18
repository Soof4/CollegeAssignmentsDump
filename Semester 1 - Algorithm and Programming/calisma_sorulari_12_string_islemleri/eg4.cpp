#include <stdio.h>


int main() {
    int i;
    int size1, size2;
    char str1[200], str2[200];

    printf("str1: ");
    gets(str1);
    printf("str2: ");
    gets(str2);


    for (i=size1=0 ; str1[i] != '\0' ; i++) {
        size1 += str1[i];
    }

    for (i=size2=0 ; str2[i] != '\0' ; i++) {
        size2 += str2[i];
    }

    if (size1 > size2) {
        printf("str1 > str2");
    }
    else if (size2 > size1) {
        printf("str1 < str2");
    }
    else {
        printf("str1 = str2");
    }
}