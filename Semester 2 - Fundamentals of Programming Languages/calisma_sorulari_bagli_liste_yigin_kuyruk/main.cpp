#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define QUEUE_LENGTH 8


 /*
 typedef struct CharNode {
    char c;
    CharNode *nextNode;
    CharNode *prevNode;
}CharNode;
*/

typedef struct NumNode {
    int num;
    NumNode *nextNode;
    NumNode *prevNode;
}Node;


/*
CharNode *AddNode(CharNode *initialNode, char c) {

    if(initialNode == NULL) {
        initialNode = (CharNode*)malloc(sizeof(CharNode));
        initialNode->nextNode = NULL;
        initialNode->prevNode = NULL;
        initialNode->c = c;
        return initialNode;
    }

    CharNode *tempNode = initialNode;
    while(tempNode->nextNode != NULL) {
        tempNode = tempNode->nextNode;
    }

    CharNode *newNode = (CharNode*)malloc(sizeof(CharNode));

    tempNode->nextNode = newNode;
    newNode->prevNode = tempNode;
    newNode->nextNode = NULL;
    newNode->c = c;

    return initialNode;
}

CharNode *GetEndNode(CharNode *initialNode) {
    while (initialNode->nextNode != NULL) {
        initialNode = initialNode->nextNode;
    }

    return initialNode;
}

bool CheckForPalindrome(CharNode *initialNode, CharNode *endNode) {
    if (initialNode == NULL) {
        return true;
    }

    while (initialNode != endNode) {

        if(initialNode->c != endNode->c) {
            return false;
        }

        initialNode = initialNode->nextNode;
        endNode = endNode->prevNode;
    }

    return true;
}
*/

NumNode *AddSortedNode(NumNode *initialNode, int num) {

    if(initialNode == NULL) {
        initialNode = (NumNode*)malloc(sizeof(NumNode));
        initialNode->nextNode = NULL;
        initialNode->prevNode = NULL;
        initialNode->num = num;
        return initialNode;
    }

    if(num < initialNode->num) {
        NumNode *newNode = (NumNode*)malloc(sizeof(NumNode));

        newNode->num = num;
        newNode->prevNode = NULL;
        newNode->nextNode = initialNode;

        initialNode->prevNode = newNode;
        return newNode;
    }

    NumNode *tempNode = initialNode;
    while(tempNode->nextNode != NULL) {
        if(tempNode->nextNode->num > num) {
            break;
        }

        tempNode = tempNode->nextNode;
    }

    NumNode *newNode = (NumNode*)malloc(sizeof(NumNode));

    newNode->num = num;
    newNode->prevNode = tempNode;
    newNode->nextNode = tempNode->nextNode;
    tempNode->nextNode = newNode;

    if(newNode->nextNode != NULL) {
        newNode->nextNode->prevNode = newNode;
    }

    return initialNode;
}

NumNode *AddSortedNodeFromEnd(NumNode *endNode, int num) {
    if(endNode == NULL) {
        endNode = (NumNode*)malloc(sizeof(NumNode));
        endNode->nextNode = NULL;
        endNode->prevNode = NULL;
        endNode->num = num;
        return endNode;
    }

    if(num > endNode->num) {
        NumNode *newNode = (NumNode*)malloc(sizeof(NumNode));

        newNode->num = num;
        newNode->prevNode = endNode;
        newNode->nextNode = NULL;
        endNode->nextNode = newNode;

        return newNode;
    }

    NumNode *tempNode = endNode;
    while(tempNode->prevNode != NULL) {
        if(tempNode->prevNode->num < num) {
            break;
        }

        tempNode = tempNode->prevNode;
    }

    NumNode *newNode = (NumNode*)malloc(sizeof(NumNode));

    newNode->num = num;
    newNode->nextNode = tempNode;
    newNode->prevNode = tempNode->prevNode;

    if(tempNode->prevNode != NULL) {
        tempNode->prevNode->nextNode = newNode;
    }

    tempNode->prevNode = newNode;
    return endNode;
}

NumNode *AddNode(NumNode *initialNode, int num) {

    if(initialNode == NULL) {
        initialNode = (NumNode*)malloc(sizeof(NumNode));
        initialNode->nextNode = NULL;
        initialNode->prevNode = NULL;
        initialNode->num = num;
        return initialNode;
    }

    NumNode *tempNode = initialNode;
    while(tempNode->nextNode != NULL) {
        tempNode = tempNode->nextNode;
    }

    NumNode *newNode = (NumNode*)malloc(sizeof(NumNode));

    tempNode->nextNode = newNode;
    newNode->prevNode = tempNode;
    newNode->nextNode = NULL;
    newNode->num = num;

    return initialNode;
}

bool IsPrime(int num) {

    if(num<2) {
        return false;
    }

    for(int i=2; i<=num/2; i++) {
        if(num%i == 0) {
            return false;
        }
    }

    return true;
}

void PrintLL(NumNode* initialNode) {
    printf("\n");
    while(initialNode != NULL) {
        printf("%d ", initialNode->num);
        initialNode = initialNode->nextNode;
    }
}

NumNode *GetEndNode(NumNode *initialNode) {
    while (initialNode->nextNode != NULL) {
        initialNode = initialNode->nextNode;
    }
    return initialNode;
}

NumNode *GetInitialNode(NumNode *endNode) {
    while (endNode->prevNode != NULL) {
        endNode = endNode->prevNode;
    }
    return endNode;
}

int FindIndexFromEnd(NumNode* endNode, int query) {
    for(int i=1; endNode != NULL; i++, endNode = endNode->prevNode) {
        if(endNode->num == query) {
            return i;
        }
    }

    return -1;
}


NumNode *AddCircularNode(NumNode *initialNode, int num) {

    if (initialNode == NULL) {
        initialNode = (NumNode*)malloc(sizeof(NumNode));
        initialNode->num = num;
        initialNode->nextNode = initialNode;
        initialNode->prevNode = initialNode;
        return initialNode;
    }

    Node *newNode = (NumNode*)malloc(sizeof(NumNode));

    newNode->num = num;
    newNode->nextNode = initialNode;
    newNode->prevNode = initialNode->prevNode;

    initialNode->prevNode->nextNode = newNode;
    initialNode->prevNode = newNode;


    if(initialNode->nextNode == initialNode) {
        initialNode->nextNode = newNode;
    }

    return initialNode;
}

void PrintCL(NumNode *initialNode) {

    printf("\n%d ", initialNode->num);
    Node *tempNode = initialNode->nextNode;

    while(tempNode != initialNode) {
        printf("%d ", tempNode->num);
        tempNode = tempNode->nextNode;
    }
}


void AddOrder(char queue[QUEUE_LENGTH][5][200]) {

}

void SendOrder(char queue[QUEUE_LENGTH][5][200]) {

}

void ShiftQueue(char queue[QUEUE_LENGTH][5][200]) {
    
}

int main() {

    // eg1: start
    /*
    NumNode *initialNode, *endNode;
    int inputNum;

    initialNode = endNode = NULL;

    while(true) {
        printf("\nSayi girin: ");
        scanf("%d", &inputNum);
        if(IsPrime(inputNum)) {
            break;
        }
        initialNode = AddNode(initialNode, inputNum);
    }

    PrintLL(initialNode);
    */
    // eg1:end

    ////////////////////////////////////////////////////

    // eg2: start
    /*
    printf("\nAranacak sayiyi girin: ");
    scanf("%d", &inputNum);

    endNode = GetEndNode(initialNode);
    printf("\n %d", FindIndexFromEnd(endNode, inputNum));
    */
    // eg2: end

    ////////////////////////////////////////////////////

    // eg3: start
    /*
    CharNode *initialNode, *endNode;
    char inputString[100];
    int i;

    printf("\nString girin: ");
    scanf("%[^\n]s", inputString);

    for(i=0; inputString[i] != '\0'; i++) {
        initialNode = AddNode(initialNode, inputString[i]);
    }

    endNode = GetEndNode(initialNode);

    if(CheckForPalindrome(initialNode, endNode)) {
        printf("\nPalindromdur.");
    }
    else {
        printf("\nPalinrom degildir.");
    }
    */
    // eg3: end

    ////////////////////////////////////////////////////

    // eg4: start
    /*
    srand(time(NULL));

    NumNode *initialNode, *endNode;
    int i, num;

    endNode = NULL;

    for(i=0; i<20; i++) {
        num = rand()%201;
        endNode = AddSortedNodeFromEnd(endNode, num);
    }

    initialNode = GetInitialNode(endNode);

    PrintLL(initialNode);

    printf("\nYeni sayi girin: ");
    scanf("%d", &num);

    endNode = AddSortedNodeFromEnd(endNode, num);

    initialNode = GetInitialNode(endNode);

    PrintLL(initialNode);
    */
    // eg4: end

    ////////////////////////////////////////////////////

    // eg5: start

    /*
    srand(time(NULL));

    NumNode *initialNode;
    int i, num;

    initialNode = NULL;

    for(i=0; i<20; i++) {
        num = rand()%201;
        initialNode = AddCircularNode(initialNode, num);
    }

    PrintCL(initialNode);

     this part is not done

    */

    // eg5: end

    ////////////////////////////////////////////////////

    // eg9: start
    char orderQueue[QUEUE_LENGTH][5][200];






    // eg9: end

    ////////////////////////////////////////////////////
    return 0;
}