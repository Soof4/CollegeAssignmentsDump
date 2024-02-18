#define READ_FORMAT "%d\t%s\t%d\t%d\n"
#define PRINT_FORMAT "%d\t%s\t%d\t%d\t%.1lf\n"
#define PASS_PIVOT 60

#include <stdlib.h>
#include <stdio.h>


typedef struct Node {

    int number;
    char *name;
    int midterm;
    int final;
    double mean;
    Node *previous;
    Node *next;

}Node;

void printll(Node *initialNode) {
    printf("\n");
    while (initialNode != NULL) {
        printf(PRINT_FORMAT,
               initialNode->number,
               initialNode->name,
               initialNode->midterm,
               initialNode->final,
               initialNode->mean);
        initialNode = initialNode->next;
    }
}

char *newStr(char *name) {
    char *newStr = (char*)malloc(sizeof(name));
    char c;
    int i;
    for(i=0; (c=*(name+i)) != '\0'; i++) {
        *(newStr+i) = c;
    }
    *(newStr+i) = c;
    return newStr;
}

bool equals(char *str1, char *str2) {
    char c;

    while ((c=*str1) != '\0') {
        if(*str1 != *str2) {
            return false;
        }
        str2++;
        str1++;
    }
    if(*str2 == '\0') {
        return true;
    }

    return false;
}

Node *createStudent(int number, char *name, int midterm, int final) {
    Node *newStudent = (Node*)malloc(sizeof(Node));
    newStudent->number = number;
    newStudent->name = newStr(name);
    newStudent->midterm = midterm;
    newStudent->final = final;
    newStudent->mean = midterm*0.4 + final*0.6;
    newStudent->previous = NULL;
    newStudent->next = NULL;
    return newStudent;
}

Node *addNewNode(Node *initialNode, Node *newNode, Node *connectedNode, char connectType) {

    if (connectType == 'b') {
        newNode->next = connectedNode;
        connectedNode->previous = newNode;
        return newNode;
    }
    else {
        newNode->previous = connectedNode;
        connectedNode->next = newNode;
        return initialNode;
    }
}

Node *createll(const char *directory) {

    int number, midterm, final;
    char name[30];
    Node *initialNode, *endNode, *tempNode, *newNode;
    FILE *file;

    file = fopen(directory, "r");
    if(file == NULL) {
        printf("\nHata: Dosya bulunamadi.");
        return NULL;
    }

    fscanf(file, READ_FORMAT, &number, name, &midterm, &final);
    initialNode = createStudent(number, name, midterm, final);
    endNode = initialNode;

    while(fscanf(file, READ_FORMAT, &number, name, &midterm, &final) != EOF) {
        newNode = createStudent(number, name, midterm, final);
        if(newNode->mean >= PASS_PIVOT) {
            addNewNode(initialNode, newNode, initialNode, 'b');
            initialNode = initialNode->previous;
        }
        else {
            addNewNode(initialNode, newNode, endNode, 's');
            endNode = endNode->next;
        }
    }

    return initialNode;
}

Node *getEndNode(Node *initialNode) {
    if(initialNode == NULL) {
        return NULL;
    }

    while (initialNode->next != NULL) {
        initialNode = initialNode->next;
    }
    return initialNode;
}

Node *update(Node *initialNode, char *name, int midterm, int final) {
    Node *tempNode = initialNode;
    double preMean = -1;

    while (tempNode != NULL) {
        if(equals(tempNode->name,name)) {
            preMean = tempNode->mean;
            tempNode->midterm = midterm;
            tempNode->final = final;
            tempNode->mean = 0.4*midterm + 0.6*final;
            break;
        }
        tempNode = tempNode->next;
    }

    if(preMean == -1) {
        printf("\nIsim bulunamadi.");
        return initialNode;
    }

    Node *endNode = getEndNode(initialNode);

    if(preMean < PASS_PIVOT && tempNode->mean >= PASS_PIVOT) {    // send to start
        if(tempNode == endNode) {
            endNode->previous->next = NULL;
            initialNode->previous = tempNode;
            tempNode->previous = NULL;
            tempNode->next = initialNode;
            initialNode = tempNode;
        }
        else if (tempNode != initialNode) {
            tempNode->previous->next = tempNode->next;
            tempNode->next->previous = tempNode->previous;

            initialNode->previous = tempNode;
            tempNode->previous = NULL;
            tempNode->next = initialNode;
            initialNode = tempNode;
        }

    }
    else if(preMean >= PASS_PIVOT && tempNode->mean < PASS_PIVOT) {    // send to end
        if (tempNode == initialNode) {
            initialNode = tempNode->next;
            initialNode->previous = NULL;

            tempNode->previous = endNode;
            endNode->next = tempNode;
            tempNode->next = NULL;
        }
        else if (tempNode != endNode) {
            tempNode->previous->next = tempNode->next;
            tempNode->next->previous = tempNode->previous;

            endNode->next = tempNode;
            tempNode->next = NULL;
            tempNode->previous = endNode;
        }
    }
    printf("\nListe guncellendi.");
    return initialNode;
}

Node *delNode(Node *initialNode, char delType) {
    if(delType != 'b' && delType != 's') {
        printf("\nBastan mi, sondan mi oldugu belirtilmedi.");
        return initialNode;
    }

    Node *tempNode, *endNode;
    endNode = getEndNode(initialNode);

    if(delType == 'b') {
        tempNode = initialNode;
        while(tempNode != NULL && (tempNode->number%2 != 0 || tempNode->mean >= PASS_PIVOT)) {
            tempNode = tempNode->next;
        }
    }
    else {
        tempNode = endNode;

        while(tempNode != NULL && (tempNode->number%2 != 0 || tempNode->mean >= PASS_PIVOT)) {
            tempNode = tempNode->previous;
        }
    }

    if(tempNode == NULL) {
        printf("\nDersten kalan ogrenci bulunamadi.");
    }
    else {
        if(initialNode == endNode) {
            free(tempNode->name);
            free(tempNode);
            return NULL;
        }
        if(tempNode == initialNode) {
            initialNode = initialNode->next;
            initialNode->previous = NULL;
            free(tempNode->name);
            free(tempNode);
        }
        else if(tempNode == endNode) {
            endNode->previous->next = NULL;
            free(tempNode->name);
            free(tempNode);
        }
        else {
            tempNode->previous->next = tempNode->next;
            tempNode->next->previous = tempNode->previous;

            free(tempNode->name);
            free(tempNode);
        }
        printf("\nOgrenci silindi.");
    }

    return initialNode;
}

int main() {

    Node *list;

    int option, midterm, final;
    char name[30], delType;

    do {
        printf("\n1) Liste olustur\n"
               "2) Listele\n"
               "3) Guncelle\n"
               "4) Sil\n"
               "0) Cikis\n"
               "Secim: ");

        scanf("%d", &option);

        if(option == 1) {
            list = createll("ogrenci.txt");
            printf("\nListe olusturuldu.");
        }
        else if ( option == 2) {
            printll(list);
        }
        else if (option == 3) {
            printf("\nKim guncellenecek: ");
            scanf("%s", name);
            getchar();
            printf("\nYeni vize puani: ");
            scanf("%d", &midterm);
            printf("\nYeni final puani: ");
            scanf("%d", &final);
            list = update(list, name, midterm, final);

        }
        else if (option == 4) {
            printf("\n Bastan mi, sondan mi silinecek? (b/s): ");
            scanf(" %c", &delType);
            getchar();
            list = delNode(list, delType);
        }
        else if (option != 0){
            printf("\nMenude olmayan bir secenek secildi.");
        }

    } while(option != 0);

    return 0;
}
