#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct NumNode {
    int num;
    struct NumNode *nextNode;
}NumNode;

typedef struct ListPointer {
    struct NumNode *list1;
    struct NumNode *list2;
}ListPointer;

void freeLists(ListPointer *lists) {
    NumNode *tempNode, *lastNode;

    if(lists->list1 == NULL && lists->list2 == NULL) {
        return;
    }

    if(lists->list1 != NULL) {
        tempNode = lists->list1->nextNode;
        while (tempNode!=NULL) {
            lastNode = tempNode;
            tempNode = tempNode->nextNode;
            free(lastNode);
        }
    }
    lists->list1 = NULL;

    if(lists->list2 != NULL) {
        tempNode = lists->list2->nextNode;
        while (tempNode!=NULL) {
            lastNode = tempNode;
            tempNode = tempNode->nextNode;
            free(lastNode);
        }
    }
    lists->list2 = NULL;
}

int countElements(ListPointer *lists) {
    int numAmount = 0;
    NumNode *tempNode;

    tempNode = lists->list1;
    while(tempNode != NULL) {
        numAmount++;
        tempNode = tempNode->nextNode;
    }
    tempNode = lists->list2;
    while (tempNode != NULL) {
        numAmount++;
        tempNode = tempNode->nextNode;
    }

    return numAmount;
}

void delNode(NumNode* initialNode, int index) {
    NumNode *tempNode, *lastNode;

    if(initialNode!=NULL && index>0) {
        lastNode = initialNode;
        tempNode = initialNode->nextNode;
        index--;
    }
    else if (initialNode != NULL){
        initialNode = NULL;
        return;
    }
    else { // if initialNode is NULL
        return;
    }

    while (index>0) {
        index--;
        lastNode=tempNode;
        tempNode=tempNode->nextNode;
    }
    lastNode->nextNode=tempNode->nextNode;
    free(tempNode);
}

ListPointer *createRandNums(ListPointer *lists, int amount) {
    freeLists(lists);
    NumNode *tempNode, *newNode;

    int i, num;
    printf("\nListe => ");

    for(i=0; i<amount; i++) {
        num = 20 + rand()%31;
        newNode = (NumNode*)malloc(sizeof(NumNode));
        newNode->num = num;
        newNode->nextNode = NULL;

        if(lists->list1 == NULL) {
            lists->list1 = newNode;
            tempNode = lists->list1;
        }
        else {
            tempNode->nextNode = newNode;
            tempNode = tempNode->nextNode;
        }

        printf("%d ", num);
    }

    return lists;
}

ListPointer *splitIntoLists(ListPointer *lists, int pivot) {
    NumNode *initialNode1, *initialNode2, *newNode, *tempNode, *tempNode1, *tempNode2;
    initialNode1 = initialNode2 = NULL;

    int i, elementCount;

    elementCount = countElements(lists);
    int *nums = (int*)malloc(sizeof(int)*elementCount);

    tempNode = lists->list1;
    i = 0;
    while(tempNode != NULL) {
        *(nums+i) = tempNode->num;
        tempNode = tempNode->nextNode;
        i++;
    }
    tempNode = lists->list2;
    while (tempNode != NULL) {
        *(nums+i) = tempNode->num;
        tempNode = tempNode->nextNode;
        i++;
    }


    for(i=0; i<elementCount; i++) {
        newNode = (NumNode*)malloc(sizeof(NumNode));
        newNode->num = nums[i];
        newNode->nextNode = NULL;
        if(nums[i]>pivot) {
            if(initialNode2==NULL) {
                initialNode2 = newNode;
                tempNode2 = initialNode2;
            }
            else {
                tempNode2->nextNode = newNode;
                tempNode2 = newNode;
            }
        }
        else {
            if(initialNode1==NULL) {
                initialNode1 = newNode;
                tempNode1 = initialNode1;
            }
            else {
                tempNode1->nextNode = newNode;
                tempNode1 = newNode;
            }
        }
    }

    printf("\nKucuk Sayi Listesi => ");
    tempNode1=initialNode1;
    while (tempNode1 != NULL) {
        printf("%d ", tempNode1->num);
        tempNode1 = tempNode1->nextNode;
    }

    printf("\nBuyuk Sayi Listesi => ");
    tempNode2=initialNode2;
    while (tempNode2 != NULL) {
        printf("%d ", tempNode2->num);
        tempNode2 = tempNode2->nextNode;
    }


    lists->list1=initialNode1;
    lists->list2=initialNode2;
    return lists;
}

ListPointer *deleteByMean(NumNode* initialNode1, NumNode* initialNode2, bool isSplit) {
    int count, index;
    float mean;
    NumNode *tempNode;

    mean=count=0;
    tempNode = initialNode1;


    while (tempNode!=NULL) {
        count++;
        mean+=tempNode->num;
        tempNode=tempNode->nextNode;
    }
    if(initialNode1 != NULL) {
        mean /= count;
    }


    if(!isSplit) {
        printf("\nListe => Ortalama: %.2f", mean);
    }
    else {
        printf("\nKucuk Sayi Listesi => Ortalama: %.2f", mean);
    }



    if(initialNode1 != NULL) {
        tempNode = initialNode1->nextNode;
    }

    if(initialNode1 != NULL && initialNode1->num>=mean) {
        printf("    %d silinecek...", initialNode1->num);
        delNode(initialNode1, 0);
        initialNode1=tempNode;
    }
    else {
        index=1;
        while (tempNode!=NULL) {
            if(tempNode->num>=mean) {
                printf("    %d silinecek...", tempNode->num);
                delNode(initialNode1, index);
                break;
            }
            index++;
            tempNode=tempNode->nextNode;
        }
    }
    printf("  Yeni Liste: ");
    tempNode = initialNode1;
    while (tempNode!=NULL) {
        printf("%d ", tempNode->num);
        tempNode=tempNode->nextNode;
    }

    if(!isSplit) {
        ListPointer *lists = (ListPointer*)malloc(sizeof(ListPointer));
        lists->list1 = initialNode1;
        lists->list2 = NULL;
        return  lists;
    }

    mean=count=0;
    tempNode = initialNode2;
    // -- calc the mean
    while (tempNode!=NULL) {
        count++;
        mean+=tempNode->num;
        tempNode=tempNode->nextNode;
    }
    if(initialNode2 != NULL) {
        mean /= count;
    }
    printf("\nBuyuk Sayi Listesi => Ortalama: %.2f", mean);


    if(initialNode2 != NULL) {
        tempNode = initialNode2->nextNode;
    }

    if(initialNode2 != NULL && initialNode2->num>=mean) {
        printf("    %d silinecek...", initialNode2->num);
        delNode(initialNode2, 0);
        initialNode2=tempNode;
    }
    else {
        index=1;
        while (tempNode!=NULL) {
            if(tempNode->num>=mean) {
                printf("    %d silinecek...", tempNode->num);
                delNode(initialNode2, index);
                break;
            }
            index++;
            tempNode=tempNode->nextNode;
        }
    }
    printf("  Yeni Liste: ");
    tempNode = initialNode2;
    while (tempNode!=NULL) {
        printf("%d ", tempNode->num);
        tempNode=tempNode->nextNode;
    }

    ListPointer *lists = (ListPointer*)malloc(sizeof(ListPointer));
    lists->list1 = initialNode1;
    lists->list2 = initialNode2;

    return  lists;
}

ListPointer *mergeLists(NumNode *initialNode1, NumNode *initialNode2) {
    NumNode *tempNode, *currentNode1, *currentNode2, *initialNode3, *newNode;
    ListPointer *lists = (ListPointer*)malloc(sizeof(ListPointer));

    lists->list1 = initialNode1;
    lists->list2 = initialNode2;

    initialNode3 = NULL;

    // -- setting initialNode3
    for(int i=20; i<51 && initialNode3==NULL ; i++) {
        tempNode=initialNode1;
        while(initialNode3==NULL && tempNode!=NULL) {
            if(tempNode->num==i) {
                initialNode3=(NumNode*)malloc(sizeof(NumNode));
                initialNode3->num=i;
                initialNode3->nextNode=NULL;
            }
            tempNode=tempNode->nextNode;
        }
    }

    for(int i=20; i<51 && initialNode3==NULL ; i++) {
        tempNode=initialNode2;
        while(initialNode3==NULL && tempNode!=NULL) {
            if(tempNode->num==i) {
                initialNode3=(NumNode*)malloc(sizeof(NumNode));
                initialNode3->num=i;
                initialNode3->nextNode=NULL;
            }
            tempNode=tempNode->nextNode;
        }
    }

    // -- placing rest of the list
    tempNode=initialNode3;
    bool isInitialFound = false;
    if(initialNode3==NULL) {
        printf("\nDiziler bos!");
        return lists;
    }

    for(int i=initialNode3->num; i<51; i++) {
        currentNode1=initialNode1;
        while (currentNode1 != NULL) {
            if(currentNode1->num==i) {
                if(currentNode1->num==initialNode3->num && !isInitialFound) {
                    isInitialFound = true;
                    currentNode1=currentNode1->nextNode;
                    continue;
                }
                newNode = (NumNode*)malloc(sizeof(NumNode));
                newNode->nextNode=NULL;
                newNode->num=i;
                tempNode->nextNode=newNode;
                tempNode=newNode;
            }
            currentNode1=currentNode1->nextNode;
        }

        currentNode2=initialNode2;
        while (currentNode2 != NULL) {
            if(currentNode2->num==i) {
                if(currentNode2->num==initialNode3->num && !isInitialFound) {
                    isInitialFound = true;
                    currentNode2=currentNode2->nextNode;
                    continue;
                }
                newNode = (NumNode*)malloc(sizeof(NumNode));
                newNode->nextNode=NULL;
                newNode->num=i;
                tempNode->nextNode=newNode;
                tempNode=newNode;
            }
            currentNode2=currentNode2->nextNode;
        }
    }


    NumNode *tempNode1, *tempNode2, *oddInitialNode, *evenInitialNode;

    tempNode = initialNode3;

    oddInitialNode = evenInitialNode = NULL;

    while (tempNode != NULL) {
        newNode = (NumNode*)malloc(sizeof(NumNode));
        newNode->num = tempNode->num;
        newNode->nextNode = NULL;
        if(tempNode->num%2==0) {
            if(evenInitialNode == NULL) {
                evenInitialNode = newNode;
                tempNode2 = newNode;
            }
            tempNode2->nextNode = newNode;
            tempNode2 = newNode;
        }
        else {
            if(oddInitialNode == NULL) {
                oddInitialNode = newNode;
                tempNode1 = newNode;
            }
            tempNode1->nextNode = newNode;
            tempNode1 = newNode;
        }

        tempNode=tempNode->nextNode;
    }

    if(oddInitialNode->nextNode==oddInitialNode) {
        oddInitialNode->nextNode = NULL;
    }
    if(evenInitialNode->nextNode==evenInitialNode) {
        evenInitialNode->nextNode = NULL;
    }

    lists->list1 = oddInitialNode;
    lists->list2 = evenInitialNode;

    tempNode = oddInitialNode;
    printf("\nOrtak ve Sirali Yeni Bagli Liste TEK => ");
    while (tempNode!=NULL) {
        printf("%d ", tempNode->num);
        tempNode = tempNode->nextNode;
    }

    tempNode = evenInitialNode;
    printf("\nOrtak ve Sirali Yeni Bagli Liste CIFT => ");
    while (tempNode!=NULL) {
        printf("%d ", tempNode->num);
        tempNode = tempNode->nextNode;
    }
    return lists;
}


int main() {
    srand(time(NULL));
    int option, numAmount, pivot;
    bool isSplit;
    ListPointer *lists = (ListPointer*)malloc(sizeof(ListPointer));
    lists->list1 = NULL;
    lists->list2 = NULL;


    printf("\nN: ");
    scanf("%d", &numAmount);
    while(numAmount<0) {
        printf("\nLutfen daha buyuk bir sayi giriniz: ");
        scanf("%d", &numAmount);
    }
    lists = createRandNums(lists, numAmount);

    printf("\nEsik degeri: ");
    scanf("%d", &pivot);
    lists = splitIntoLists(lists, pivot);
    isSplit = true;
    option=2;
    while(option > 0 && option < 5) {
        printf("\n\nMenu:"
               "\n1. Sayi Uret"
               "\n2. Bagli Liste Olustur"
               "\n3. Ortalamaya Gore Sil"
               "\n4. Sirali Birlestir"
               "\n5. Cikis"
               "\nSecim: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nN: ");
                scanf("%d", &numAmount);
                while(numAmount<0) {
                    printf("\nLutfen daha buyuk bir sayi giriniz: ");
                    scanf("%d", &numAmount);
                }
                lists = createRandNums(lists, numAmount);
                isSplit = false;
                break;
            case 2:
                printf("\nEsik degeri: ");
                scanf("%d", &pivot);
                lists = splitIntoLists(lists, pivot);
                isSplit = true;
                break;
            case 3:
                lists = deleteByMean(lists->list1, lists->list2, isSplit);
                break;
            case 4:
                lists = mergeLists(lists->list1, lists->list2);
                break;
        }
    }

    return 0;
}