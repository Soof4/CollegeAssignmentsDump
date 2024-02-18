#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0
#define MAX_WORD_COUNT 100

int main() {
    char str[2*MAX_WORD_COUNT], matrix[MAX_WORD_COUNT][2*MAX_WORD_COUNT], state;
    int word_count, i, j;

    printf("\nString: ");
    gets(str);

    word_count = 0;
    i = j = 0;
    state = OUT_WORD;
    while (str[i] != '\0') {
        if (str[i] != '_' && state == OUT_WORD) {
            word_count++;
            state = IN_WORD;
            matrix[word_count-1][j] = str[i];
            j++;
        }
        else if (str[i] == '_' && state == IN_WORD) {
            matrix[word_count-1][j] = '\0';
            state = OUT_WORD;
            j = 0;
        }
        else if (str[i] != '_' && state == IN_WORD){
            matrix[word_count-1][j] = str[i];
            j++;
        }
        i++;
    }

    for (i=0 ; i<word_count ; i++) {
        printf("\n%s", matrix[i]);
    }

}