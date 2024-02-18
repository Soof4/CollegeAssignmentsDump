#include <stdio.h>


const int OGR_SAYISI=12;
const int SUTUN_SAYISI=4;

int matris[OGR_SAYISI][SUTUN_SAYISI]={
        {2101, 70, 60},
        {2102, 50, 35},
        {2103, 60, 75},
        {2104, 70, 90},
        {2105, 75, 50},
        {2106, 50, 35},
        {2107, 10, 55},
        {2108, 20, 40},
        {2109, 75, 90},
        {2110, 12, 85},
        {2111, 53, 75},
        {2112, 12, 30}};


void OrtlariHesapla() {
    for (int i=0; i<OGR_SAYISI; i++) {
        matris[i][3] = (int)(matris[i][1]*0.4 + matris[i][2]*0.6);
    }
}

void InsertionSort(int array[OGR_SAYISI][SUTUN_SAYISI], int size) {
    for (int i=1; i<size; i++) {
        int j=i;
        while ( array[j-1][3] < array[j][3] && j>0) {


            for(int k=0; k<SUTUN_SAYISI; k++) {
                int temp = array[j-1][k];
                array[j-1][k] = array[j][k];
                array[j][k] = temp;
            }

            j--;
        }
    }
}



void EnBasariliOgrencileriBul(int[OGR_SAYISI][SUTUN_SAYISI], int N) {
    OrtlariHesapla();
    InsertionSort(matris, OGR_SAYISI);


    for(int i=0; i<N; i++) {
        printf("\n%d  %d  %d  %d", matris[i][0], matris[i][1], matris[i][2], matris[i][3]);
    }

}


int main() {

    int N;
    printf("\nN: ");
    scanf("%d", &N);
    EnBasariliOgrencileriBul(matris, N);

    return 0;
}