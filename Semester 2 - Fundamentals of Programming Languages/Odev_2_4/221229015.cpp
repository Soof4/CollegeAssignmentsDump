#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

int main() {
    srand(time(NULL)*91);
    int i, n, m, num, cur_index;
    char name[MAX_NAME_LENGTH];

    printf("N: ");
    scanf("%d", &n);
    getchar();

    int nameIndexes[n];

    FILE *studentsFile = fopen("Ogrenciler.txt", "w");
    FILE *numbersFile = fopen("Sayilar.txt", "w");

    for(i=0; i<n; i++) {
        printf("%d. Ogrenci adi: ", i+1);
        gets(name);
        nameIndexes[i] = ftell(studentsFile);
        fprintf(studentsFile, "%s\n", name);
        fprintf(numbersFile, "%2d\n", rand()%9+2);
    }

    printf("Yazdirma sayisi: ");
    scanf("%d", &m);

    fclose(studentsFile);
    fclose(numbersFile);

    studentsFile = fopen("Ogrenciler.txt", "r+");
    numbersFile = fopen("Sayilar.txt", "r+");

    /* // different solution [without fseek() and ftell()]
    while(m>0) {
        fscanf(studentsFile, "%s\n", name);
        printf("\n%s", name);
        fscanf(numbersFile, "%d\n", &jumpLineAmount);

        if(jumpLineAmount%n == 0) {
            jumpLineAmount++;
        }
        jumpLineAmount--;

        while(jumpLineAmount>0) {
            if(fscanf(studentsFile, "%s\n", name) == EOF) {
                rewind(studentsFile);
                rewind(numbersFile);
                fscanf(studentsFile, "%s\n", name);
                fscanf(numbersFile, "%d\n", &num);
            }
            else {
                fscanf(numbersFile, "%d\n", &num);
            }
            jumpLineAmount--;
        }
        m--;
    }
    */

    num = 0;
    while(m>0) {
        cur_index = num;
        fscanf(studentsFile, "%s\n", name);
        printf("%s\n", name);
        fscanf(numbersFile, "%2d\n", &num);

        if(num%n==0) {
            num=1;
        }
        num +=cur_index;
        while(num>=n) {
            num-=n;
        }

        fseek(studentsFile, nameIndexes[num], SEEK_SET);
        fseek(numbersFile, num*strlen("%2d\n"), SEEK_SET);

        m--;
    }

    fclose(studentsFile);
    fclose(numbersFile);
    return 0;
}
