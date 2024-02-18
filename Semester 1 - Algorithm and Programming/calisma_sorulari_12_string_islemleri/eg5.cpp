#include <stdio.h>


int main() {
    int i, counter;
    char str[200];

    printf("String: ");
    gets(str);

    counter = 0;
    for (i=1 ; str[i] != '\0' ; i++) {
        if (str[i-1] < str[i]) {
            counter++;
            printf(" %c>%c ", str[i], str[i-1]);
        }
    }
    printf("\n\nSonuc: %d", counter);
}