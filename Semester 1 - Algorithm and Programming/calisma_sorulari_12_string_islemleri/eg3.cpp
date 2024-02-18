#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0


int main() {
    char str[200], state;
    int word_count, i;

    printf("\nString: ");
    gets(str);

    word_count = 0;
    i = 0;
    state = OUT_WORD;
    while (str[i] != '\0') {
        if (str[i] != '_' && state == OUT_WORD) {
            word_count++;
            state = IN_WORD;
        }
        else if (str[i] == '_' && state == IN_WORD) {
            state = OUT_WORD;
        }
        i++;
    }
    printf("\nKelime sayisi: %d", word_count);
}