#include<stdio.h>
#include<stdlib.h>

typedef struct Dugum
{
    int deger;
    int tur;
    struct Dugum *sonraki;
}Dugum;

Dugum *ilk=NULL;

int BagliListeHazirla()
{
    Dugum *gecici=NULL;

    for(int i=0; i< 3 ; i++)
    {
        Dugum *yeni=(Dugum *)malloc(sizeof(Dugum));
        yeni->tur= (i+1);
        yeni->deger= 0;

        if(ilk==NULL)
        {
            ilk= yeni;
            gecici=ilk;
            ilk->sonraki=NULL;
        }
        else
        {
            gecici->sonraki= yeni;
            gecici=gecici->sonraki;
            gecici->sonraki=NULL;
        }
    }
}

 int Listele()
{
    Dugum *gecici= ilk;

    while(gecici!=NULL)
    {
        printf("\n gecici->deger= %d\t gecici->tur= %d", gecici->deger, gecici->tur);
        gecici= gecici->sonraki;
    }
}

void YeniDugumEkle(Dugum *ilk, int deger) {
    Dugum *geciciDugum = ilk;
    while(geciciDugum != NULL) {
        geciciDugum = geciciDugum->sonraki;
    }

    geciciDugum->sonraki = (Dugum*)malloc(sizeof(Dugum));
    geciciDugum->sonraki->sonraki = NULL;
    geciciDugum->sonraki->deger = deger;
    geciciDugum->sonraki->tur = 1;
}

int main()
{

    BagliListeHazirla();// Ilk durum olusturuldu
    Listele();   // genel gosterim i�in

}
