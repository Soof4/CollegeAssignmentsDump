#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void print_matrix(char *ip, int n) {
    for (int i=0 ; i<n ; i++) {
        printf("\n");
        for (int j=0 ; j<n ; j++, ip++) {
            if (*(ip) > 3) {
                printf("%2c ", *ip);
            }
            else {
                printf("%2d ", *ip);
            }
        }
    }

}
void reverse_word(char *ip, int word_length) {
    int i;
    char temp;
    i=0;
    while (i < word_length/2) {
        temp = *ip;
        *ip = *(ip+word_length-1-2*i);
        *(ip+word_length-1-2*i) = temp;
        ip++;
        i++;
    }
}
void generate_matrix(char *ip, int n) {
    n *= n;
    for (int i=0 ; i<n ; i++, ip++) {
        *ip = 1 + rand()%3;
    }
}


int main() {
    srand(time(NULL));
    int i, j, k, l, m, i_max, j_max, j_start, i_start;
    int n, placement_type, word_length, word_index, fail_count;

    printf("\nN: ");
    scanf("%d", &n);
    while (n<9) {
        printf("N>8 olmali");
        printf("\n\nN: ");
        scanf("%d", &n);
    }
    char matrix[n][n];
    char temp_layer[n][n];

    printf("\nYerlestirme Tipi (1/2): ");
    scanf("%d", &placement_type);


    while (placement_type == 1) {    // Classic placement
        /* Take the words in random order and place them  */
        char words[][9] = { "SOFTWARE", "COMPILER", "FLUTTER", "REACT" };
        char use_list[] = {1, 1, 1, 1 };    // if not used -> 1 , else -> 0
        generate_matrix(&matrix[0][0], n);

        // -- Place the first and second words (left/right)
        fail_count = 0;
        for (k=0 ; k<2 && fail_count<16 ; k++) {
            while ( use_list[word_index = rand()%4] == 0);
            word_length = strlen(words[word_index]);
            j_max = n-word_length;
            i = rand()%n;
            j_start = rand()%(j_max+1);

            if (k==0) {    // first (right)
                for (j=0 ; words[word_index][j] != '\0' ; j++) {
                    matrix[i][j_start+j] = words[word_index][j];
                }
                use_list[word_index] = 0;
            }
            else {    // second (left)
                generate_matrix(&temp_layer[0][0], n);
                reverse_word(&words[word_index][0], word_length);    // reverse the word
                for (j=0 ; words[word_index][j] != '\0' ; j++) {
                    if (matrix[i][j_start+j] < 4 || words[word_index][j] == matrix[i][j_start+j]) {
                        temp_layer[i][j_start+j] = words[word_index][j];
                    }
                    else {
                        fail_count++;
                        k--;
                        reverse_word(&words[word_index][0], word_length);
                        break;
                    }
                }
                if (k == 1) {    // copy-pasting the word from temp to matrix
                    use_list[word_index] = 0;
                    for (m=0 ; m<n ; m++) {
                        for (l=0 ; l<n ; l++) {
                            if (temp_layer[m][l] > 3) {
                                matrix[m][l] = temp_layer[m][l];
                            }
                        }
                    }
                }
            }
        }

        // -- Place the third and forth words (down/up)
        fail_count = 0;
        for (k=0 ; k<2 && fail_count<16 ; k++) {
            while ( use_list[word_index = rand()%4] == 0);
            word_length = strlen(words[word_index]);
            i_max = n-word_length;
            j = rand()%n;
            i_start = rand()%(i_max+1);
            generate_matrix(&temp_layer[0][0], n);

            if (k==0) {    // third (down)
                for (i=0 ; words[word_index][i] != '\0' ; i++) {
                    if (matrix[i_start+i][j] < 4 || words[word_index][i] == matrix[i_start+i][j]) {
                        temp_layer[i_start+i][j] = words[word_index][i];
                    }
                    else {
                        fail_count++;
                        k--;
                        break;
                    }
                }
                if (k == 0) {    // copy-pasting the word from temp to matrix
                    use_list[word_index] = 0;
                    for (m=0 ; m<n ; m++) {
                        for (l=0 ; l<n ; l++) {
                            if (temp_layer[m][l] > 3) {
                                matrix[m][l] = temp_layer[m][l];
                            }
                        }
                    }
                }
            }
            else {    // forth (up)
                reverse_word(&words[word_index][0], word_length);
                for (i=0 ; words[word_index][i] != '\0' ; i++) {
                    if (matrix[i_start+i][j] < 4 || words[word_index][i] == matrix[i_start+i][j]) {
                        temp_layer[i_start+i][j] = words[word_index][i];
                    }
                    else {
                        reverse_word(&words[word_index][0], word_length);
                        k--;
                        fail_count++;
                        break;
                    }
                }
                if (k == 1) {    // copy-pasting the word from temp to matrix
                    use_list[word_index] = 0;
                    for (m=0 ; m<n ; m++) {
                        for (l=0 ; l<n ; l++) {
                            if (temp_layer[m][l] > 3) {
                                matrix[m][l] = temp_layer[m][l];
                            }
                        }
                    placement_type = 0;
                    }
                }
            }
        }
    }

    while (placement_type == 2) {    // Diagonal placement
        /* Take the words in random order and place them  */
        char words[][9] = { "SOFTWARE", "COMPILER", "FLUTTER", "REACT" };
        char use_list[] = {1, 1, 1, 1 };    // if not used -> 1 , else -> 0
        generate_matrix(&matrix[0][0], n);

        // -- Place the first and second words (right d/u)
        fail_count = 0;
        for (k=0 ; k<2 && fail_count<8 ; k++) {
            while ( use_list[word_index = rand()%4] == 0);
            word_length = strlen(words[word_index]);

            if (k==0) {    // right-down
                i_max = j_max = n-word_length;
                i_start = rand()%(i_max+1);
                j_start = rand()%(j_max+1);
                for (l=0 ; words[word_index][l] != '\0' ; l++) {
                    matrix[i_start+l][j_start+l] = words[word_index][l];
                }
                use_list[word_index] = 0;
            }
            else {    // right-up
                i_start = word_length -1 + rand()%(n-word_length+1);
                j_start = rand()%(n-word_length+1);
                generate_matrix(&temp_layer[0][0], n);
                for (l=0 ; words[word_index][l] != '\0' ; l++) {
                    if (matrix[i_start-l][j_start+l] < 4 || words[word_index][l] == matrix[i_start-l][j_start+l]) {
                        temp_layer[i_start-l][j_start+l] = words[word_index][l];
                    }
                    else {
                        k--;
                        fail_count++;
                        break;
                    }
                }
                if (k == 1) {    // copy-pasting the word from temp to matrix
                    use_list[word_index] = 0;
                    for (m=0 ; m<n ; m++) {
                        for (l=0 ; l<n ; l++) {
                            if (temp_layer[m][l] > 3) {
                                matrix[m][l] = temp_layer[m][l];
                            }
                        }
                    }
                }
            }
        }

        // -- Place the third and forth words (left d/u)
        for (k=0 ; k<2 && fail_count<8 ; k++) {
            while ( use_list[word_index = rand()%4] == 0);
            word_length = strlen(words[word_index]);

            if (k==0) {    // left-down
                i_start = rand()%(n-word_length+1);
                j_start = word_length-1 + rand()%(n-word_length+1);
                generate_matrix(&temp_layer[0][0], n);
                for (l=0 ; words[word_index][l] != '\0' ; l++) {
                    if (matrix[i_start+l][j_start-l] < 4 || words[word_index][l] == matrix[i_start+l][j_start-l]) {
                        temp_layer[i_start+l][j_start-l] = words[word_index][l];
                    }
                    else {
                        k--;
                        fail_count++;
                        break;
                    }
                }
                if (k == 0)  {    // copy-pasting the word from temp to matrix
                    use_list[word_index] = 0;
                    for (m=0 ; m<n ; m++) {
                        for (l=0 ; l<n ; l++) {
                            if (temp_layer[m][l] > 3) {
                                matrix[m][l] = temp_layer[m][l];
                            }
                        }
                    }
                }
            }
            else {    // left-up
                i_start = word_length-1 + rand()%(n-word_length+1);
                j_start = word_length-1 + rand()%(n-word_length+1);
                generate_matrix(&temp_layer[0][0], n);
                for (l=0 ; words[word_index][l] != '\0' ; l++) {
                    if (matrix[i_start-l][j_start-l] < 4 || words[word_index][l] == matrix[i_start-l][j_start-l]) {
                        temp_layer[i_start-l][j_start-l] = words[word_index][l];
                    }
                    else {
                        k--;
                        fail_count++;
                        //printf(" fail ");
                        break;
                    }
                }
                if (k == 1) {    // copy-pasting the word from temp to matrix
                    use_list[word_index] = 0;
                    for (m=0 ; m<n ; m++) {
                        for (l=0 ; l<n ; l++) {
                            if (temp_layer[m][l] > 3) {
                                matrix[m][l] = temp_layer[m][l];
                            }
                        }
                        placement_type = 0;
                    }
                }
            }
        }
    }

    print_matrix(&matrix[0][0], n);
}