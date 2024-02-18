#include <stdio.h>

#define LINE_LENGTH 200


int main() {
    int midterm, final, query;
    char line[LINE_LENGTH], temp[20];
    FILE *file1 = fopen("Ogrenci.txt", "r");
    FILE *file2 = fopen("Ogrenci.txt", "r");
    FILE *targetFile = fopen("notlar2.txt", "w");
    printf("Notu giriniz: ");
    scanf("%d", &query);

    while(!feof(file1)) {
        fgets(line, LINE_LENGTH, file1);
        fscanf(file2, "%s\t%s\t%d\t%d", temp, temp, &midterm, &final);
        if(midterm >= query && final>= query) {
            fputs(line, targetFile);
        }
    }

    return 0;
}