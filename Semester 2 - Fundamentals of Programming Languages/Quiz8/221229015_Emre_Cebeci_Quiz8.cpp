#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node {
    int num;
    Node *nextNode;
    Node *prevNode;
}Node;

Node *SwapNodes(Node *initialNode, Node *endNode, int count) {
    if (initialNode == NULL || endNode == NULL) {
        return initialNode;
    }

    Node *left, *right, *temp;
    left = initialNode;
    right = endNode;

    for (int i = 0; i < count / 2; i++) {
        if (right->num > left->num) {
            temp = right;
            right = left;
            left = temp;

            if (left->prevNode != NULL) {
                left->prevNode->nextNode = right;
            } else {
                initialNode = right;
            }

            if (right->prevNode != NULL) {
                right->prevNode->nextNode = left;
            } else {
                initialNode = left;
            }

            if (left->nextNode != NULL) {
                left->nextNode->prevNode = right;
            }

            if (right->nextNode != NULL) {
                right->nextNode->prevNode = left;
            }

            temp = left->nextNode;
            left->nextNode = right->nextNode;
            right->nextNode = temp;

            temp = left->prevNode;
            left->prevNode = right->prevNode;
            right->prevNode = temp;
        }

        if (left->nextNode == right) {
            break;
        }

        left = left->nextNode;
        right = right->prevNode;
    }

    return initialNode;
}


Node *AddNode(Node *initialNode, int num) {

    if(initialNode == NULL) {
        initialNode = (Node*)malloc(sizeof(Node));
        initialNode->nextNode = NULL;
        initialNode->prevNode = NULL;
        initialNode->num = num;
        return initialNode;
    }

    Node *tempNode = initialNode;
    while(tempNode->nextNode != NULL) {
        tempNode = tempNode->nextNode;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));

    tempNode->nextNode = newNode;
    newNode->prevNode = tempNode;
    newNode->nextNode = NULL;
    newNode->num = num;

    return initialNode;
}

Node *GetEndNode(Node *initialNode) {
    while (initialNode->nextNode != NULL) {
        initialNode = initialNode->nextNode;
    }
    return initialNode;
}

void PrintLL(struct Node *initialNode) {
    printf("\n");
    while (initialNode != NULL) {
        printf("%d ", initialNode->num);
        initialNode = initialNode->nextNode;
    }
}


int main() {
    srand(time(NULL));

    int amount;
    Node *initialNode, *endNode;

    initialNode = endNode = NULL;

    printf("\nListede kac tane sayi olsun?: ");
    scanf("%d", &amount);

    for(int i=0; i<amount; i++) {
        initialNode = AddNode(initialNode, rand()%101);
    }

    endNode = GetEndNode(initialNode);

    printf("\nListenin ilk hali:");
    PrintLL(initialNode);

    SwapNodes(initialNode, endNode, amount);

    printf("\nListenin son hali:");
    PrintLL(initialNode);


    return 0;
}
