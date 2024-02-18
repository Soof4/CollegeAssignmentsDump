#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *ogrenciler = fopen("Ogrenciler.txt", "r+");
    FILE *tekler = fopen("tekler.txt", "w+");

    int ogrenciNo, vize, final;
    char isim[50];
    while(fscanf(ogrenciler,"%d %s %d %d", &ogrenciNo, &isim, &vize, &final) != EOF) {
        if(vize*0.4 + final*0.6 >= 70) {
            fprintf(tekler, "%d %s %d %d", ogrenciNo, isim, vize, final);
        }
    }

    return 0;
}