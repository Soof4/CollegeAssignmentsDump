#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node *nextNode;
};

void printReverse(Node* addresses[], int size) {
    size--;
    printf("%d ", addresses[size]->num);
    if(size>0) {
        printReverse(addresses, size);
    }
}

int absolute(int num) {
    return num<0 ? -num: num;
}






int main() {
    // start: 1

    int num;
    Node *initialNode = NULL;
    Node *tempNode = NULL;
    Node *newNode = NULL;

    tempNode = (Node*)malloc(sizeof(Node));
    while (true) {
        printf("\nSayi girin: ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        newNode = (Node*)malloc(sizeof(Node));
        newNode->num = num;
        newNode->nextNode = NULL;
        tempNode->nextNode = newNode;

        if (initialNode == NULL) {
            initialNode = newNode;
            tempNode = initialNode;
        } else {
            tempNode = newNode;
        }
    }

    printf("\n");
    if (initialNode != NULL) {
        tempNode = initialNode;
        while (tempNode != NULL) {
            printf("%d ", tempNode->num);
            tempNode = tempNode->nextNode;
        }
    }

    // end: 1

    // start: 2
    /*
    double mean, count;

    mean=count=0;
    if(initialNode!=NULL) {
        tempNode=initialNode;
        while (tempNode!=NULL) {
            mean+=tempNode->num;
            count++;
            tempNode=tempNode->nextNode;
        }
    }
    mean /= count;
    printf("\nMean: %.2f", mean);
     */
    // end: 2

    // start: 3
    /*
    Node *newInitialNode = (Node*)malloc(sizeof(Node));
    Node *lastNode = (Node*)malloc(sizeof(Node));

    newInitialNode = NULL;
    tempNode = initialNode;
    while (tempNode != NULL) {
        while(newInitialNode == NULL) {
            if(tempNode->num>mean) {
                newInitialNode=tempNode;
                lastNode=newInitialNode;
            }
            tempNode = tempNode->nextNode;
        }
        if(tempNode->num>mean) {
            newNode=(Node*)malloc(sizeof(Node));
            newNode->num=tempNode->num;
            newNode->nextNode=NULL;
            lastNode->nextNode=newNode;
            lastNode=newNode;
        }
        tempNode = tempNode->nextNode;
    }

    printf("\n");
    if(newInitialNode!=NULL) {
        tempNode=initialNode;
        while (tempNode!=NULL) {
            printf("%d ", tempNode->num);
            tempNode=tempNode->nextNode;
        }
    }
     */
    // end: 3

    // start: 4
    /*
    int count;
    tempNode = initialNode;
    count=0;
    while (tempNode!=NULL) {
        count++;
        tempNode=tempNode->nextNode;
    }

    Node* nodeAddresses[count];

    tempNode = initialNode;
    for(int i=0; tempNode!=NULL ;i++) {
        nodeAddresses[i] = tempNode;
        tempNode=tempNode->nextNode;
    }
    printf("\n");
    printReverse(nodeAddresses, count);
    */
    // end: 4

    // start: 5
    /*
    int index;

    printf("\nKacinci eleman: ");
    scanf("%d", &index);
    index--;
    tempNode=initialNode;
    while(index>0) {
        tempNode=tempNode->nextNode;
        index--;
    }
    printf("\nSonuc: %d", tempNode->num);
    */
    // end: 5

    // start: 6
    /*
    int query, index;
    printf("\nIstenen sayi: ");
    scanf("%d", &query);

    index=1;
    tempNode=initialNode;
    while (tempNode->num != query) {
        index++;
        tempNode=tempNode->nextNode;
    }
    printf("\nIstenen sayi %d. siradadir.", index);
     */
    // end: 6

    // start: 7
    /*
    printf("\n");
    tempNode = initialNode;
    while (tempNode->nextNode!=NULL) {
        if(tempNode->num%2==0 && tempNode->nextNode->num%2==0) {
            printf("%d-%d  ", tempNode->num, tempNode->nextNode->num);
            tempNode=tempNode->nextNode;
        }
        tempNode=tempNode->nextNode;
    }
    */
    // end: 7

    // start: 8
    /*
    int step;
    printf("\nArtis miktari: ");
    scanf("%d", &step);

    tempNode=initialNode;
    for(int i=1; i<step; i++) {
        tempNode=tempNode->nextNode;
    }
    printf("\n");
    while (tempNode!=NULL) {
        printf("%d ", tempNode->num);
        for(int i=0; i<step; i++) {
            tempNode=tempNode->nextNode;
        }
    }
    */
    // end: 8

    // start: 9
    /*
    int last;
    tempNode=initialNode;
    printf("\n");

    while (tempNode->nextNode!=NULL) {
        if(tempNode->num<tempNode->nextNode->num || last<tempNode->num) {
            printf("%d ", tempNode->num);
        }
        last = tempNode->num;
        tempNode=tempNode->nextNode;
    }
    */
    // end: 9

    // start: 10
    
    int index, query, diff, closestIndex, closestNum;

    printf("\nAranacak sayi: ");
    scanf("%d", &query);

    index=closestIndex=closestNum=-1;
    tempNode=initialNode;

    if(tempNode!=NULL) {
        diff=absolute(tempNode->num-query);
        index=closestIndex=0;
        closestNum=tempNode->num;
    }

    while (tempNode!=NULL) {
        index++;
        if(absolute(tempNode->num-query)<diff) {
            diff = absolute(tempNode->num-query);
            closestIndex=index;
            closestNum = tempNode->num;
        }
        tempNode=tempNode->nextNode;
    }

    printf("\nEn yakin sayi %d. siradaki %d sayisidir.", closestIndex, closestNum);
    // end: 10


    return 0;
}