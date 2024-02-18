#include <stdio.h>

int main() {
    int n, i;
    char name[50], line[50];

    FILE *file = fopen("string.dat", "r+b");
    if (file == NULL) {
        fclose(file);
        printf("\nDosya bulunamadigi icin yeniden uretilecek.");
        file = fopen("string.dat", "wb");
        printf("Kac tane isim girilecek: ");
        scanf("%d", &n);
        i = 0;
        getchar();
        while (i < n) {
            printf("%d. Isim: ", i + 1);
            getchar();
            gets(name);
            fprintf(file, "%s\n", name);
            i++;
        }
        fclose(file);
    }

    printf("\nYeni ogrenci kacinci siraya yazilacak: ");
    scanf("%d", &n);
    getchar();
    printf("Yeni isimi giriniz: ");
    fgets(name, sizeof(name), stdin);

    file = freopen("string.dat", "r+b", file);

    n--;
    while (n > 0) {
        fgets(line, sizeof(line), file);
        n--;
    }
    int pos = ftell(file);
    fclose(file);
    file = fopen("string.dat", "r+b");
    fseek(file, pos, SEEK_SET);
    fprintf(file, "%s", name);
    fclose(file);

    file = fopen("string.dat", "rb");

    int c;
    while ((c = getc(file)) != EOF) {
        printf("%c", c);
    }
    fclose(file);
    return 0;
}

