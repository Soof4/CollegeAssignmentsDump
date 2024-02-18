#include<stdio.h>
#include<stdlib.h>

typedef struct Dugum
{
	int sayi;
	struct Dugum *sonraki;
	struct Dugum *onceki;
}Dugum;

const int boyut=10;
Dugum *ilk=NULL, *son=NULL;

void ListeOlustur()
{
	int dizi[] ={10, 50, 100, 200, 251, 25, 28 };

	for(int i=0; i< sizeof(dizi)/sizeof(int); i++)
	{
		 Dugum *yeni=(Dugum *)malloc(sizeof(Dugum));
	     yeni->sayi= dizi[i];

	     if(ilk==NULL)
	     {
	       ilk=yeni;
		   son=yeni;
		   yeni->sonraki=NULL;
		   yeni->onceki=NULL;
		 }
		 else
		 {
		 	son->sonraki=yeni;
			yeni->onceki=son;
			son=yeni;
			son->sonraki=NULL;
		 }

	}
}

void Listele()
{
	Dugum *gecici=ilk;
	printf("\n\n son durum: ");
	while(gecici!=NULL)
    {
		printf("%d  -> ",gecici->sayi);
		gecici=gecici->sonraki;
   	}
}

////////////// Kodlari bu alan icinde gerceklestiriniz. //////////////

void Sil()
{ // ilk ve son degi�kenlerini kullanmaniz gerekmektedir.
    if (ilk == NULL) {
        return;
    }
    Dugum *temp = son;
    while (temp != NULL) {
        if(temp->sayi%2 == 0) {
            break;
        }
        temp = temp->onceki;
    }

    if(temp->onceki == NULL) {
        ilk = ilk->sonraki;
        return;
    }
    if(temp->sonraki == NULL) {
        temp->onceki->sonraki = NULL;
        return;
    }

    temp->onceki->sonraki = temp->sonraki;
    temp->sonraki->onceki = temp->onceki;



}
////////////// Kodlari bu alan icinde gerceklestiriniz. //////////////


int main()
{
	ListeOlustur();
    Listele();
    Sil();
    Listele();
}
