#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int i, j;

    printf("\nStr1: ");
    gets(str1);

    i = 0;
    while (str1[i++] != '\0');
    i -= 2;

    for (j=0 ; i>-1 ; i--, j++) {
        str2[j] = str1[i];
    }
    str2[j] = '\0';
    printf("\nStr2: %s", str2);
}