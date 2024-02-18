#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LINE_LENGTH 100

int pow(int base, int n) {
    if(n==0) {
        return 1;
    }
    return pow(base, n-1)*base;
}


bool find_string(char *ip, char string[]) {
    int i;
    i = 0;
    while (*ip != '\0') {
        if (*ip == string[i]) {

            i++;
            if (i == strlen(string)) {
                return true;
            }
        }
        else {
            i = 0;
        }
        ip++;
    }
    return false;
}

int main() {
    /*
    srand(time(NULL));
    int i, j;
    int list[20], nums[4];

    for(i=0; i<20; i++) {
        list[i] = rand();
    }

    FILE *ikiliDosya = fopen("ikiliDosya.dat", "w+b");

    for(i=0; i<20; i++) {
        fwrite(&list[i], sizeof(int), 1, ikiliDosya);
    }

    rewind(ikiliDosya);

    for(i=0; i<5; i++) {
        fread(&nums[0], sizeof(int), 4, ikiliDosya);
        printf("\n%d\t%d\t%d\t%d\t=> %.2f", nums[0], nums[1], nums[2], nums[3], (nums[0]+nums[1]+nums[2]+nums[3])/4.0);

    }
    fclose(ikiliDosya);
    */ // eg1-2

    /*
    int i;
    int nums[3];
    char format[] = "%d\t%d\t%d\n";
    FILE *file = fopen("ornek2.txt", "w+");

    for(i=1; i<9; i++) {
        fprintf(file, format, i, i+1, i+2);
    }

    rewind(file);
    for(i=1; i<9; i++) {
        fscanf(file, format, &nums[0], &nums[1], &nums[2]);
        printf(format, nums[0], nums[1], nums[2]);
    }
    fclose(file);
    */ // eg3

    /*
    srand(time(NULL));
    char format1[200] = "%d\t%d\t%d\t%d\t%d\n";
    char format2[200] = "%d\t%d\t%d\t%d\t%d\tmin=%d\tmax=%d\tmean=%.2f\n";
    int i, j, nums[5], min, max, db[10][5];
    float mean;

    FILE *file = fopen("randomNumber.txt", "w+");
    for(i=0; i<10; i++) {
        fprintf(file, format1, rand(), rand(), rand(), rand(), rand());
    }

    fclose(file);


    file = fopen("randomNumber.txt", "r+");

    for(i=0; i<10; i++) {
        fscanf(file, format1, &db[i][0], &db[i][1], &db[i][2], &db[i][3], &db[i][4]);
    }

    rewind(file);
    for(i=0; i<10; i++) {
        min = max = db[i][0];
        mean = 0;
        for(j=0; j<5; j++) {
            if(db[i][j]>max) {
                max = db[i][j];
            }
            if(db[i][j]<min) {
                min = db[i][j];
            }
            mean += db[i][j];
        }
        fprintf(file, format2, db[i][0], db[i][1], db[i][2], db[i][3], db[i][4], min, max, mean/5.0);
    }

    rewind(file);

    FILE *oddFile = fopen("tek.txt", "w");
    FILE *evenFile = fopen("cift.txt", "w");

    char line[200];
    char c;
    for(i=0; i<10; i++) {
        fgets(line, 200, file);

        if(i%2==1) {
            fputs(line, evenFile);
        }
        else {
            fputs(line, oddFile);
        }
    }
    fcloseall();

    */ // eg4-5-6-7

    /*
    int i, j;
    char query[LINE_LENGTH], line[LINE_LENGTH];
    FILE *file = fopen("OgrenciNotlar.txt", "r");
    printf("Aranacak stringi giriniz: ");
    gets(query);

    while(!feof(file)) {
        fgets(line, LINE_LENGTH, file);
        if(find_string(line, query)) {
            printf("%s", line);
        }
    }
    */ // eg8

    /*
    int i, j, midterm, final, query;
    char line[LINE_LENGTH], temp[20];
    FILE *file1 = fopen("OgrenciNotlar.txt", "r");
    FILE *file2 = fopen("OgrenciNotlar.txt", "r");
    printf("Notu giriniz: ");
    scanf("%d", &query);

    while(!feof(file1)) {
        fgets(line, LINE_LENGTH, file1);
        fscanf(file2, "%s\t%s\t%d\t%d", temp, temp, &midterm, &final);
        if(midterm > query || final> query) {
            printf("%s", line);
        }
    }
    */ //eg9

    /*
    int i, j, no, num, mid, fin;
    char newLine[LINE_LENGTH], nos[20], temp[50];
    FILE *file = fopen("OgrenciNotlar.txt", "r+");
    printf("\"OgrenciNo\tIsim\tvizeNOt\tfinalNot\" seklinde veriyi giriniz: ");
    gets(newLine);

    for(i=0; newLine[i] != '\t'; i++) {
        nos[i] = newLine[i];
    }

    no = 0;

    for(i--, j=0; i>-1; i--, j++) {
        no += (nos[i] - '0')*pow(10,j);
    }

    rewind(file);

    while(fscanf(file, "%d\t%s\t%d\t%d\n", &num, temp, &mid, &fin) != EOF) {
        if(num==no) {
            printf("\nNumara zaten kayitli.");
            return 0;
        }
    }
    fseek(file, 0, SEEK_END);
    fputc('\n', file);
    fputs(newLine, file);

    fclose(file);
    */ //eg10

    return 0;
}