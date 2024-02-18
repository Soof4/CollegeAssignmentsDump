#include <stdio.h>

#define READ_FORMAT "%d\t%s\t%d\t%d\n"

void YeniDosyaOlustur(int secim) {
    if(secim != 0 && secim != 1) {
        printf("\nHatali secim girildi.");
        return;
    }
    FILE *rfile = fopen("ogrenci.txt", "r");
    FILE *wfile = fopen("sonuc.txt", "w");
    char name[50];
    int numara, vize, final;
    if(secim == 0) {
        while(fscanf(rfile, READ_FORMAT, &numara, name, &vize, &final) != EOF) {
            if (numara%2 == 0) {
                fprintf(wfile, READ_FORMAT, numara, name, vize, final);
            }
        }
    }
    else {
        while(fscanf(rfile, READ_FORMAT, &numara, name, &vize, &final) != EOF) {
            if (numara%2 != 0) {
                fprintf(wfile, READ_FORMAT, numara, name, vize, final);
            }
        }
    }

}




int main() {
    int secim;
    printf("\nSecim (0/1): ");
    scanf("%d", &secim);
    YeniDosyaOlustur(secim);

    return 0;
}