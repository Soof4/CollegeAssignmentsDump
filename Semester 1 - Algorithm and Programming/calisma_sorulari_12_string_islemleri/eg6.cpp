#include <stdio.h>


int main() {
    int i, n;
    char str1[200], str2[200];

    printf("String: ");
    gets(str1);

    printf("N: ");
    scanf("%d", &n);

    for (i=n ; str1[i] != '\0' ; i++) {
        str2[i-n] = str1[i];
    }
    str2[i-n] = '\0';
    str1[n] = '\0';

    printf("\nstr1 = %s\nstr2 = %s", str1, str2);



}