#include <stdio.h>
#include <stdlib.h>
#include <time.h>


bool searchNumInArray(int num, int array[], int sizeOfArray) {

    for(int i=0; i<sizeOfArray; i++) {
        if(array[i] == num) {
            return true;
        }
    }
    return false;
}

int *createAndMergeArrays(int n, int numbers1[], int numbers2[]) {
    int num, i, j;
    static int mergedArray[202];

    for (int i=0; i<n; i++) {
        while (searchNumInArray((num=rand()%101), numbers1, i));
        *(numbers1+i) = num;

        while (searchNumInArray((num=rand()%101), numbers2, i));
        *(numbers2+i) = num;
    }


    for (i=0; i<n; i++) {
        *(mergedArray+i) = *(numbers1+i);
    }
    for (j=0; j<n; i++, j++) {
        *(mergedArray+i) = *(numbers2+j);
    }

    printf("\ndizi1[]={");
    for (int i=0; i<n; i++) {
        printf("%d", *(numbers1+i));
        if (i+1<n) {
            printf(", ");
        }
    }
    printf("};");

    printf("\ndizi2[]={");
    for (int i=0; i<n; i++) {
        printf("%d", *(numbers2+i));
        if (i+1<n) {
            printf(", ");
        }
    }
    printf("};");

    printf("\nBirlesmis dizi: ");
    for (i=0, n*=2; i<n; i++) {
        printf("%d ", *(mergedArray+i));
    }

    return mergedArray;
}

void lesserToGreater(int *ptr, int sizeOfArray) {
    for (int i=0; i<101; i++) {
        for (int j=0; j<sizeOfArray; j++) {
            if (*(ptr+j) == i) {
                printf("%d ", *(ptr+j));
            }
        }
    }
}

void greaterToLesser(int *ptr, int sizeOfArray) {
    for (int i=100; i>-1; i--) {
        for (int j=0; j<sizeOfArray; j++) {
            if (*(ptr+j) == i) {
                printf("%d ", *(ptr+j));
            }
        }
    }
}


int main() {
    srand(time(NULL));

    while (true) {
        int n, *ptr, choice;
        printf("\nDizi buyuklugu: ");
        scanf("%d", &n);
        while (n<1 || n>101) {
            printf("\nn=%d olamaz (1 ile 101 arasinda olmali)\nTekrar giriniz: ", n);
            scanf("%d", &n);
        }

        int numbers1[n], numbers2[n];
        ptr = createAndMergeArrays(n, numbers1, numbers2);

        choice = 0;
        // MENU
        while (choice != 3) {
            printf("\n\nMENU\n1: Kucukten buyuge\n2: Buyukten kucuge\n3: Yeni dizi olustur\n");
            scanf("%d", &choice);

            if (choice == 0) {
                break;
            }
            else if (choice == 1) {
                lesserToGreater(ptr, 2*n);
            }
            else if (choice == 2) {
                greaterToLesser(ptr, 2*n);
            }
        }
        if (choice == 0) {
            break;
        }
    }

    return 0;
}