#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node *nextNode;
};

int absolute(int num) {
    return num<0 ? -num: num;
}


int main() {
    int num, query, diff, index, closestIndex, closestNum;
    Node *initialNode = NULL;
    Node *tempNode = NULL;
    Node *newNode = NULL;

    while (true) {
        printf("\nSayi girin: ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        }

        newNode = (Node *)malloc(sizeof(Node));
        newNode->num = num;
        newNode->nextNode = NULL;

        if (initialNode == NULL) {
            initialNode = newNode;
            tempNode = initialNode;
        }
        else {
            tempNode->nextNode = newNode;
            tempNode = newNode;
        }
    }

    if(initialNode == NULL) {
        printf("\nHic sayi girilmedi.");
        return 0;
    }

    printf("\nListe: ");
    tempNode = initialNode;
    while (tempNode != NULL) {
        printf("%d ", tempNode->num);
        tempNode = tempNode->nextNode;
    }

    printf("\nAranacak sayi: ");
    scanf("%d", &query);

    diff=absolute(initialNode->num-query);
    closestIndex=index=1;
    closestNum=initialNode->num;

    tempNode=initialNode;
    while (tempNode!=NULL) {
        if(absolute(tempNode->num-query)<diff) {
            diff = absolute(tempNode->num-query);
            closestIndex=index;
            closestNum = tempNode->num;
        }
        index++;
        tempNode=tempNode->nextNode;
    }

    printf("\nEn yakin sayi %d. siradaki %d sayisidir.", closestIndex, closestNum);
    return 0;
}