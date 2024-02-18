#include <stdlib.h>
#include <stdio.h>


typedef struct Node {
    double num;
    struct Node *nextNode;
}Node;

void sortLinkedList(Node *initialNode) {
    Node *tempNode, *tempNode2;
    double temp;
    tempNode = initialNode;
    while (tempNode != NULL) {
        tempNode2 = initialNode;
        while(tempNode2 != NULL) {
            if(tempNode2->num<tempNode->num) {
                temp = tempNode->num;
                tempNode->num = tempNode2->num;
                tempNode2->num = temp;
            }
            tempNode2 = tempNode2->nextNode;
        }
        tempNode = tempNode->nextNode;
    }
}

int countLinkedList(Node *initialNode) {
    int count = 0;
    while(initialNode != NULL) {
        count++;
        initialNode = initialNode->nextNode;
    }
    return count;
}

void printLinkedList(Node *initialNode) {
    printf("\n");

    while(initialNode != NULL) {
        printf("%.1f ", initialNode->num);
        initialNode = initialNode->nextNode;
    }
}

Node* delNode(Node *initialNode, int index) {
    Node *tempNode, *lastNode;

    if(initialNode == NULL) {
        return NULL;
    }

    if(index == 0) {
        tempNode = initialNode->nextNode;
        free(initialNode);
        return tempNode;
    }

    int maxIndex = countLinkedList(initialNode)-1;
    if(index>maxIndex) {
        printf("\nError: Index is out of bound.");
        return initialNode;
    }

    lastNode = initialNode;
    tempNode = initialNode->nextNode;
    index--;

    while(index>0) {
        lastNode = tempNode;
        tempNode = tempNode->nextNode;
        index--;

    }
    lastNode->nextNode = tempNode->nextNode;
    free(tempNode);
    return initialNode;
}

void swapNodeValues(Node* initialNode, int i, int j) {
    Node *iNode, *jNode;
    double temp;

    iNode = initialNode;
    while(i>0) {
        iNode = iNode->nextNode;
        i--;
    }
    jNode = initialNode;
    while(j>0) {
        jNode = jNode->nextNode;
        j--;
    }

    temp = iNode->num;
    iNode->num = jNode->num;
    jNode->num = temp;
}

Node *delBySteps(Node *initialNode, int step) {
    Node *tempNode, *lastNode;
    if(step<=0 || initialNode == NULL) {
        return initialNode;
    }

    if(step==1) {
        while((initialNode = delNode(initialNode,0)) != NULL);
        return initialNode;
    }

    lastNode = initialNode;
    tempNode = initialNode->nextNode;
    int i=2;

    while(tempNode != NULL) {
        if(i%step == 0) {
            lastNode->nextNode = tempNode->nextNode;
            free(tempNode);
            tempNode = lastNode->nextNode;
        }
        else {
            lastNode = tempNode;
            tempNode = tempNode->nextNode;
        }

        i++;
    }

    return initialNode;
}

int main() {
    // eg1: start
    double inputNum;
    Node *initialNode, *newNode, *tempNode;
    initialNode = NULL;

    printf("\nSayi gir: ");
    scanf("%lf", &inputNum);

    if(inputNum == -1) {
        printf("\nSayi girilmedi.");
        return 0;
    }

    initialNode = (Node*)malloc(sizeof(Node));
    initialNode->num = inputNum;
    initialNode->nextNode = NULL;

    tempNode = initialNode;
    while(true) {
        printf("\nSayi gir: ");
        scanf("%lf", &inputNum);

        if(inputNum == -1) {
            break;
        }

        newNode = (Node*)malloc(sizeof(Node));
        newNode->num = inputNum;
        newNode->nextNode = NULL;
        tempNode->nextNode = newNode;
        tempNode = tempNode->nextNode;
    }

    //sortLinkedList(initialNode);
    printLinkedList(initialNode);

    // eg1: end

    /////////////////////////////////////////////////////////

    // eg2: start
    /*
    printf("\nHangi sayi guncellenecek: ");
    scanf("%lf", &inputNum);

    tempNode = initialNode;
    while(tempNode != NULL) {
        if(tempNode->num == inputNum) {
            printf("\nYeni sayiyi girin: ");
            scanf("%lf", &inputNum);
            tempNode->num = inputNum;
        }
        tempNode = tempNode->nextNode;
    }

    sortLinkedList(initialNode);
    printLinkedList(initialNode);

    */
    // eg2: end

    /////////////////////////////////////////////////////////

    // eg3: start
    /*
    int count = countLinkedList(initialNode);
    double nums[count];

    tempNode = initialNode;
    for(int i=0; i<count; i++) {
        nums[i] = tempNode->num;
        tempNode = tempNode->nextNode;
    }


    tempNode = initialNode;
    while(tempNode->nextNode != NULL) {
        tempNode = tempNode->nextNode;
    }

    for(int i=0; i<count-1; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->num = (nums[i]+nums[i+1])/2.0;
        newNode->nextNode = NULL;
        tempNode->nextNode = newNode;
        tempNode = tempNode->nextNode;
    }

    sortLinkedList(initialNode);
    printLinkedList(initialNode);
    */
    // eg3: end

    //////////////////////////////////////////////////

    // eg4: start
    /*
    tempNode = initialNode;
    while (tempNode != NULL) {
        if((int)tempNode->num%2 != 0) {
            tempNode->num++;
        }
        tempNode = tempNode->nextNode;
    }

    printLinkedList(initialNode);
    */
    // eg4: end

    /////////////////////////////////////////////////

    // eg5: start
    /*
    int index = 0;
    double lastNum = -1;
    tempNode = initialNode;
    while (tempNode != NULL) {
        while(tempNode != NULL && lastNum == tempNode->num) {
            tempNode = tempNode->nextNode;
            initialNode = delNode(initialNode, index);
        }

        if(tempNode != NULL) {
            lastNum = tempNode->num;
            tempNode = tempNode->nextNode;
        }
        index++;
    }

    printf("\nresult: ");
    printLinkedList(initialNode);
    */
    // eg5: end

    //////////////////////////////////////////////////

    // eg6: start
    /*
    MOVE
    */
    // eg6: end

    /////////////////////////////////////////////////

    // eg7: start
    /*
    initialNode = delBySteps(initialNode, 3);
    printLinkedList(initialNode);
    */
    // eg7: end

    /////////////////////////////////////////////////

    // eg8: start
    /*
    swapNodeValues(initialNode, 0, 3);
    printLinkedList(initialNode);
    */
    // eg8: end

    /////////////////////////////////////////////////

    // eg9: start
    /*
    double mean, count;
    Node *lastNode;

    mean = count = 0;
    tempNode = initialNode;
    while (tempNode != NULL) {
        mean += tempNode->num;
        count++;
        tempNode = tempNode->nextNode;
    }
    mean /= count;

    if(initialNode->num < mean) {
        initialNode = delNode(initialNode, 0);
    }
    else {
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
    }
    printf("\nOrtalama: %lf", mean);
    printLinkedList(initialNode);
    */
    // eg9: end

    /////////////////////////////////////////////////

    // eg10: start
    /*
    int sum, input;
    Node *lastNode;

    printf("\nYeni sayi girin: ");
    scanf("%d", &input);


    sum = initialNode->num;
    if(sum > input) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->num = input;
        newNode->nextNode = initialNode;
        initialNode = newNode;

    }
    else {
        lastNode = initialNode;
        tempNode = initialNode->nextNode;

        while(tempNode != NULL) {
            sum += tempNode->num;
            if(sum > input) {
                newNode = (Node*)malloc(sizeof(Node));
                newNode->num = input;
                newNode->nextNode = tempNode;
                lastNode->nextNode = newNode;
                break;
            }

            lastNode = tempNode;
            tempNode = tempNode->nextNode;
        }
    }

    if (sum<input) {
        tempNode = initialNode;
        while (tempNode->nextNode != NULL) {
            tempNode = tempNode->nextNode;
        }
        newNode = (Node*)malloc(sizeof(Node));
        newNode->num = input;
        newNode->nextNode = NULL;
        tempNode->nextNode = newNode;
    }

    printf("\nSonuc: ");
    printLinkedList(initialNode);
    */
    // eg10: end

    return 0;
}