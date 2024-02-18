#define MIN_PRIORITY 1
#define MAX_PRIORITY 3

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int num;
    int priority;
    Node *nextNode;
}Node;

void printll(Node *initialNode) {
    printf("\n");
    while(initialNode != NULL) {
        printf("%d ", initialNode->num);
        initialNode = initialNode->nextNode;
    }
}

Node* createNewNode(int num, int priority, Node *nextNode) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->priority = priority;
    newNode->nextNode = nextNode;
    return newNode;
}

Node* buildll(int nums[], int prs[], int size) {
    if(size < 1) {
        return NULL;
    }
    Node *initialNode, *tempNode, *newNode;
    initialNode = createNewNode(nums[0], prs[0], NULL);    // set initialNode

    // add new nodes
    for(int i=1; i<size; i++) {
        if(nums[i] < initialNode->num && prs[i] <= initialNode->priority) {
            initialNode = createNewNode(nums[i], prs[i], initialNode);
            continue;
        }

        tempNode = initialNode;
        while(tempNode->nextNode != NULL && prs[i] > tempNode->nextNode->priority) {
            tempNode = tempNode->nextNode;
        }
        while(tempNode->nextNode != NULL  && prs[i] == tempNode->nextNode->priority && nums[i] > tempNode->nextNode->num) {
            tempNode = tempNode->nextNode;
        }

        tempNode->nextNode = createNewNode(nums[i], prs[i], tempNode->nextNode);
    }
    return initialNode;
}

Node* swapByPriority(Node *initialNode, int pr1, int pr2) {
    if(pr1 == pr2) {
        return initialNode;
    }
    else if(pr1 > pr2) {
        int temp = pr1;
        pr1 = pr2;
        pr2 = temp;
    }

    Node *tempNode, *tempNode1, *tempNode2;

    // find the nodes
    tempNode1 = initialNode;
    while(tempNode1 != NULL && tempNode1->nextNode->priority < pr1) {
        tempNode1 = tempNode1->nextNode;
    }
    tempNode2 = initialNode;
    while(tempNode2 != NULL && tempNode2->nextNode->priority < pr2) {
        tempNode2 = tempNode2->nextNode;
    }

    if(tempNode1 == initialNode) {
        tempNode = initialNode;
        initialNode = tempNode2->nextNode;
        tempNode2->nextNode = tempNode;

        tempNode = initialNode->nextNode;
        initialNode->nextNode = tempNode2->nextNode->nextNode;
        tempNode2->nextNode->nextNode = tempNode;
        tempNode1 = initialNode;
        tempNode2 = tempNode2->nextNode;
    }
    else {
        tempNode = tempNode1->nextNode;
        tempNode1->nextNode = tempNode2->nextNode;
        tempNode2->nextNode = tempNode;

        tempNode = tempNode1->nextNode->nextNode;
        tempNode1->nextNode->nextNode = tempNode2;
        tempNode2->nextNode->nextNode = tempNode;

        tempNode1 = tempNode1->nextNode;
        tempNode2 = tempNode2->nextNode;
    }

    //swap priorities
    tempNode1->priority = pr1;
    tempNode2->priority = pr2;

    return initialNode;
}


int main() {
    int sayiDizisi[] = {21, 40, 30, 25, 50, 24, 14, 6, 27};
    int oncelikDizisi[] = {1, 2, 3, 1, 1, 2, 3, 1, 3};

    int inputPrs[2];
    Node *initialNode;

    // build linked list
    initialNode = buildll(sayiDizisi, oncelikDizisi, sizeof(sayiDizisi)/sizeof(int));
    printf("\nListe:");
    printll(initialNode);

    while(true) {
        for(int i=0; i<2; i++) {
            printf("\nDegistirme islemi icin %d. onceligi girin: ", i+1);
            scanf("%d", &inputPrs[i]);
            if(inputPrs[i] < MIN_PRIORITY || inputPrs[i] > MAX_PRIORITY) {
                printf("\n%d girildigi icin cikiliyor.", inputPrs[i]);
                return 0;
            }
        }

        initialNode = swapByPriority(initialNode, inputPrs[0], inputPrs[1]);
        printf("\nYeni liste:");
        printll(initialNode);
    }
}