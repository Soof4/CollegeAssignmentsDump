#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node {
    int num;
    struct Node *nextNode;
}Node;

void printLinkedList(Node *initialNode) {
    printf("\n");
    while(initialNode != NULL) {
        printf("%d ", initialNode->num);
        initialNode = initialNode->nextNode;
    }
}

int main() {
    srand(time(NULL));
    int N;
    double mean;
    Node *initialNode, *newNode, *tempNode, *lastNode;
    initialNode = NULL;

    printf("\nSayi gir: ");
    scanf("%d", &N);

    if(N < 1) {
        printf("\nSayi girilmedi.");
        return 0;
    }

    initialNode = (Node*)malloc(sizeof(Node));
    initialNode->num = 10 + rand()%41;
    initialNode->nextNode = NULL;

    mean = initialNode->num;
    tempNode = initialNode;
    for(int i=1; i<N; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->num = 10 + rand()%41;
        mean += newNode->num;
        newNode->nextNode = NULL;
        tempNode->nextNode = newNode;

        tempNode = tempNode->nextNode;
    }

    printf("\nListenin ilk hali:");
    printLinkedList(initialNode);

    mean /= N;

    while(initialNode->num < mean) {
        tempNode = initialNode->nextNode;
        free(initialNode);
        initialNode = tempNode;
    }

    lastNode = initialNode;
    tempNode = initialNode->nextNode;
    while (tempNode != NULL) {
        if(tempNode->num < mean) {
            lastNode->nextNode = tempNode->nextNode;
            free(tempNode);
            tempNode = lastNode->nextNode;
            continue;
        }
        lastNode = tempNode;
        tempNode = tempNode->nextNode;
    }

    printf("\n\nOrtalama: %lf\n", mean);
    printf("\nListenin son hali:");
    printLinkedList(initialNode);

    return 0;
}