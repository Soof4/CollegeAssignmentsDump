#include<stdio.h>
#include<stdlib.h>

typedef struct Dugum
{
	int sayi;
	struct Dugum *sonraki;
}Dugum;

const int boyut=10;
Dugum *ilk1=NULL;

Dugum* Ekle( int dizi[], int boyut)
{
	Dugum *geciciDugum=NULL;
	Dugum *ilk=NULL;

	for(int i=0; i< boyut ; i++)
	{
	  Dugum *yeniDugum=(Dugum *)malloc(sizeof(Dugum));
	  yeniDugum->sayi= dizi[i];

	 if(ilk==NULL)
	 {
	 	ilk= yeniDugum;
	 }
	 else
	 {
	  	geciciDugum->sonraki= yeniDugum;
     }

	  geciciDugum=yeniDugum ;
	  yeniDugum->sonraki=NULL;

	}

	return ilk;
}

void Listele(Dugum *ilk)
{ 	Dugum *geciciDugum= ilk;
	printf("\n");

    while(geciciDugum!=NULL)
	{
      printf("%d ", geciciDugum->sayi);
      geciciDugum= geciciDugum->sonraki;
	}
}
////////////// Kodlari bu alan icinde gerceklestiriniz. //////////////

Dugum *ilk3=NULL; //gerekli kodlamalari yapiniz.

void ListeleriSiraliBirlestir(Dugum *ilk1, Dugum *ilk2)
{
    struct Dugum *temp, *temp2;

    if (ilk1->sayi <= ilk2->sayi) {
        temp = (Dugum *) malloc(sizeof(Dugum));
        temp->sayi = ilk1->sayi;
        temp->sonraki = NULL;
        ilk3 = temp;
    }
    temp = ilk3;
    while (ilk1 != NULL && ilk2 != NULL) {
        if (ilk1->sayi <= ilk2->sayi) {
            temp2 = (Dugum*)malloc(sizeof(Dugum));
            temp2->sayi = ilk1->sayi;
            temp2->sonraki = NULL;
            temp->sonraki = temp2;
            temp = temp2;
            ilk1 = ilk1->sonraki;
        } else {
            temp2 = (Dugum*)malloc(sizeof(Dugum));
            temp2->sayi = ilk2->sayi;
            temp2->sonraki = NULL;
            temp->sonraki = temp2;
            temp = temp2;
            ilk2 = ilk2->sonraki;
        }

    }
}

////////////// Kodlari bu alan icinde gerceklestiriniz. //////////////

int main()
{
	Dugum *ilk1=NULL;
	int dizi1[]={10, 50, 100, 200};
	ilk1=Ekle(dizi1, sizeof(dizi1)/sizeof(int));
	Listele(ilk1);

	Dugum *ilk2=NULL;
	int dizi2[]={15, 30, 125, 250, 350, 500  };
	ilk2=Ekle(dizi2, sizeof(dizi2)/sizeof(int));
	Listele(ilk2);

   ListeleriSiraliBirlestir( ilk1,  ilk2);
   Listele(ilk3);

}
