#include <stdio.h>
#include <string.h>

void stepByStepRead(FILE *file, long startingByte, int step) {
    int c;
    fseek(file, startingByte, SEEK_SET);
    step--;
    while((c= getc(file)) != EOF) {
        printf("%c", c);
        fseek(file, step, SEEK_CUR);
    }
}



int main() {
    // eg1
    /*
    char string[100];
    printf("String girin: ");
    gets(string);

    FILE *file = fopen("dosya.txt", "w");
    fputs(string, file);
    fclose(file);
    */

    // eg2
    /*
    int c;
    FILE *file1 = fopen("dosya.txt", "r");
    FILE *file2 = fopen("dosya2.txt", "w");

    while((c=getc(file1)) != EOF) {
        if(c>='A' && c<='Z') {
            c += 32;
        }
        else if (c>='a' && c<='z'){
            c -= 32;
        }
        fputc(c, file2);
    }

    fclose(file1);
    fclose(file2);
    */

    // eg3
    /*
    file = fopen("dosya.txt", "r");
    stepByStepRead(file, 0, 3);
    fclose(file);
    */

    // eg4
    /*
    file = fopen("dosya.txt", "r");
    fseek(file, -1, SEEK_END);
    while((c=getc(file)) != EOF) {
        printf("%c", c);
        fseek(file, -2, SEEK_CUR);
    }
    */

    // eg5
    /*
    file = fopen("dosya.txt", "r");
    fseek(file, -1, SEEK_END);
    if(ftell(file)%2!=0) {
        fseek(file, -1, SEEK_CUR);
    }

    while((c=getc(file)) != EOF) {
        printf("%c", c);
        fseek(file, -3, SEEK_CUR);
    }
    fclose(file);
    */

    // eg6

    FILE *file = fopen("string.dat", "w");
    char string[200];
    int indexList[6], lenList[6];
    for(int i=0; i<sizeof(indexList)/sizeof(int); i++) {
        gets(string);
        lenList[i] = strlen(string);
        indexList[i] = ftell(file);
        fprintf(file, "%s\n", string);
    }
    fclose(file);


    // eg7
    /*
    int i;
    file = fopen("string.dat", "rb");
    fseek(file, -1, SEEK_END);

    for(i=4; i>-1; i--) {
        fseek(file, indexList[i], SEEK_SET);
        fgets(string, 200, file);
        printf("%s", string);
    }
    fclose(file);
    */

    // eg8
    /*
    int lineNum;
    printf("Kacinci sira: ");
    scanf("%d", &lineNum);
    printf("Yeni string girin: ");
    scanf("%s\n", string);

    file = fopen("string.dat", "r+b");
    fseek(file, indexList[lineNum-1], SEEK_SET);
    fputs(string, file);
    fclose(file);
    */

    // eg9
    /*
    int type, i;
    file = fopen("string.dat", "rb");
    FILE *newfile = fopen("string2.dat", "wb");

    printf("Tek icin 1, cift icin 2 girin: ");
    scanf("%d", &type);
    if(type==2) {
        i=1;
    }
    else {
        i=0;
    }

    for(;i<5 ; i+=2) {
        fseek(file, indexList[i], SEEK_SET);
        fscanf(file, "%s", string);
        fprintf(newfile, "%s\n", string);
    }

    fclose(newfile);
    newfile = fopen("string2.dat", "r");

    int c;
    while((c= getc(newfile)) != EOF) {
        printf("%c", c);
    }
    */

    // eg10
    /*
    int i;

    file = fopen("string.dat", "rb");
    FILE *newfile = fopen("string2.dat", "wb");

    i = 0;
    while (i<sizeof(indexList)/sizeof(int)/2) {
        fseek(file, indexList[i], SEEK_SET);
        fscanf(file, "%s", string);
        fprintf(newfile, "%s\n", string);
        fseek(file, indexList[sizeof(indexList)/sizeof(int)-i-1], SEEK_SET);
        fscanf(file, "%s", string);
        fprintf(newfile, "%s\n", string);
        i++;
    }
    if((sizeof(indexList)/sizeof(int))%2==1) {
        fseek(file, indexList[i], SEEK_SET);
        fscanf(file, "%s", string);
        fprintf(newfile, "%s\n", string);
    }


    fclose(newfile);
    newfile = fopen("string2.dat", "r");

    int c;
    while((c= getc(newfile)) != EOF) {
        printf("%c", c);
    }
    */

    file = fopen("string.dat", "r+b");
    char nameList[6][200];
    for(int i=0; i< sizeof(indexList)/sizeof(int); i++) {
        fscanf(file, "%s\n", nameList[i]);
    }
    rewind(file);
    for(int i=0; i< sizeof(indexList)/sizeof(int); i++) {
        fprintf(file, "%d %s\n", lenList[i], nameList[i]);
    }

    fclose(file);
    file = fopen("string.dat", "rb");

    int c;
    while((c= getc(file)) != EOF) {
        printf("%c", c);
    }

    return 0;
}