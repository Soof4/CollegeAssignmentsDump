#include <stdio.h>
#include <string.h>

int main() {
    int i, j, n;
    char str[50];
    bool isPalindrom;

    printf("String: ");
    gets(str);
    printf("N: ");
    scanf("%d", &n);

    isPalindrom = true;
    for (i=n-1, j = strlen(str)-n; i< strlen(str)/2 ; i++, j--) {
        if (str[i] != str[j]) {
            isPalindrom = false;
            break;
        }
    }

    if (isPalindrom) {
        printf("Palindromdur.");
    }
    else {
        printf("Palindrom degildir.");
    }
}