#include<stdio.h>
#include <stdlib.h>

typedef struct Agac
{
    struct Agac *sol;
    struct Agac *sag;
    int sayi;
    char adi[15];

}Agac;

Agac * Ekle( Agac *dugum, int sayi)
{

    if(dugum==NULL)
    {
        Agac *kok= (Agac *)malloc(sizeof(Agac));
        kok->sayi= sayi;
        kok->sol=NULL;
        kok->sag=NULL;
        return kok;
    }

    if(sayi < dugum->sayi)
    {
        dugum->sol= Ekle(dugum->sol, sayi);
        return dugum;
    }

    dugum->sag= Ekle(dugum->sag, sayi);
    return dugum;

}

void InOrder(Agac *kok)
{
    if(kok==NULL)
    {
        return;
    }

    InOrder(kok->sol);
    printf("\n %d", kok->sayi);
    InOrder(kok->sag);
}

////////////// Kodlari bu alan icinde gerceklestiriniz. //////////////
//Gereken T�m ek fonksiyonlari da buraya yaziniz.

int GetSum(Agac *root) {
    if (root == NULL) {
        return 0;
    }

    int sum = root->sayi;
    sum += GetSum(root->sol);
    sum += GetSum(root->sag);
    return sum;
}

int GetElementCount(Agac *root) {
    if (root == NULL) {
        return 0;
    }

    int count = 1;
    count += GetElementCount(root->sol);
    count += GetElementCount(root->sag);

    return count;
}

double GetMean(Agac *root) {
    return (double)GetSum(root)/GetElementCount(root);
}


void OrtalamadanBuyukleriYazdir(Agac *kok, double ort)
{
    if(kok == NULL) {
        return;
    }

    OrtalamadanBuyukleriYazdir(kok->sol, ort);
    if (kok->sayi > ort) {
        printf("\n->%d", kok->sayi, ort);
    }
    OrtalamadanBuyukleriYazdir(kok->sag, ort);
}

////////////// Kodlari bu alan icinde gerceklestiriniz. //////////////


int main()
{
    Agac *kok=NULL;
    kok= Ekle(kok, 10);
    Ekle(kok, 5);
    Ekle(kok, 40);
    Ekle(kok, 20);
    Ekle(kok, 35);
    Ekle(kok, 70);
    Ekle(kok, 100);
    InOrder(kok);

    OrtalamadanBuyukleriYazdir( kok, GetMean(kok)); // Ek fonksiyon kullanabilirsiniz.
}
