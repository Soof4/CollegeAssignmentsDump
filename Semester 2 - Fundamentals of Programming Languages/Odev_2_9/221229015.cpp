#define READ_FORMAT "%d\t%s\t%d\t%d\n"
#define PRINT_FORMAT "%d\t%s\t%d\t%d\t%.1lf\n"
#define NAME_LIMIT 200

#include <stdlib.h>
#include <stdio.h>


typedef struct TreeNode {
    int number;
    char *name;
    int midterm;
    int final;
    double mean;
    TreeNode *leftNode;
    TreeNode *rightNode;

}TreeNode;

char *newString(const char *name) {
    char *newString, c;
    newString = (char*)malloc(sizeof(name));
    int i;
    for(i=0; (c=*(name+i)) != '\0'; i++) {
        *(newString+i) = c;
    }
    *(newString+i) = c;
    return newString;
}

bool isEqual(const char *str1, const char *str2) {
    while (*str1 != '\0') {
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

TreeNode *newNode(int number, const char *name, int midterm, int final) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->number = number;
    newNode->name = newString(name);
    newNode->midterm = midterm;
    newNode->final = final;
    newNode->mean = midterm*0.4 + final*0.6;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    return newNode;
}

TreeNode *AddNode(TreeNode *root, int number, const char *name, int midterm, int final, char addType) {
    if(root == NULL) {
        return newNode(number, name, midterm, final);
    }

    double mean = midterm*0.4 + final*0.6;

    switch (addType) {
        case 'n':    // add by number
            if(number <= root->number) {
                root->leftNode = AddNode(root->leftNode, number, name, midterm, final, addType);
            }
            else {
                root->rightNode = AddNode(root->rightNode, number, name, midterm, final, addType);
            }
            return root;

        case 'o':    // add by mean
            if(mean <= root->mean) {
                root->leftNode = AddNode(root->leftNode, number, name, midterm, final, addType);
            }
            else {
                root->rightNode = AddNode(root->rightNode, number, name, midterm, final, addType);
            }
            return root;

        default:
            printf("\nBilinmeyen ekleme formati girildi.");
            return root;
    }
}

TreeNode *AddTreeFromFile(FILE *file, const char *format, TreeNode *root, char addType) {
    int number, midterm, final;
    char name[NAME_LIMIT];

    while(fscanf(file, format, &number, name, &midterm, &final) != EOF) {
        root = AddNode(root, number, name, midterm, final, addType);
    }

    return root;
}

TreeNode* FindNode(TreeNode *root, const char* qName) {
    if (root == NULL) {
        return NULL;
    }

    if (isEqual(root->name, qName)) {
        return root;
    }

    TreeNode *tNode = FindNode(root->leftNode, qName);
    if (tNode != NULL) {
        return tNode;
    }

    return FindNode(root->rightNode, qName);
}

TreeNode *GetParent(TreeNode *root, TreeNode *node) {
    if (root == NULL) {
        return NULL;
    }

    if (root->leftNode == node || root->rightNode == node) {
        return root;
    }

    TreeNode *tNode = GetParent(root->leftNode, node);
    if (tNode != NULL) {
        return tNode;
    }

    return GetParent(root->rightNode, node);
}

TreeNode *shiftRight(TreeNode *root) {
    if(root->rightNode == NULL) {
        return root;
    }

    shiftRight(root->rightNode)->leftNode = root->leftNode;

    return root->rightNode;
}

TreeNode *shiftLeft(TreeNode *root) {
    if(root->leftNode == NULL) {
        return root;
    }

    shiftLeft(root->leftNode)->rightNode = root->rightNode;

    return root->leftNode;
}

TreeNode *PopNode(TreeNode *root, TreeNode *node) {
    TreeNode *temp;

    if(root == node) {    // if node is root
        if (root->leftNode == NULL && root->rightNode == NULL) {
            return NULL;
        }
        temp = root;
        root = shiftRight(root);
        free(temp);
        return root;
    }

    temp = GetParent(root, node);

    if(node->leftNode == NULL && node->rightNode == NULL) {    // if node is leaf
        if(temp->leftNode == node) {
            temp->leftNode = NULL;
        }
        else {
            temp->rightNode = NULL;
        }
        free(node);
        return root;
    }

    // if node is a parent

    if(node == temp->rightNode) {
        temp->rightNode = shiftRight(node);
    }
    else {
        temp->leftNode = shiftLeft(node);
    }

    free(node);
    return root;
}

void UpdateNode(TreeNode *node, int midterm, int final) {
    node->midterm = midterm;
    node->final = final;
    node->mean = midterm*0.4 + final*0.6;
}

void FindAndUpdateNode(TreeNode *root, const char *qName, int midterm, int final) {
    TreeNode *node = FindNode(root, qName);

    if(node == NULL) {
        printf("\nOgrenci bulunamadi.");
        return;
    }

    UpdateNode(node, midterm, final);
    printf("\nOgrenci guncellendi.");
}

void PrintInOrder(TreeNode *root) {

    if(root == NULL) {
        return;
    }

    PrintInOrder(root->leftNode);
    printf(PRINT_FORMAT, root->number, root->name, root->midterm, root->final, root->mean);
    PrintInOrder(root->rightNode);
}

int Menu() {
    int option;

    printf("\n\nMenu:"
           "\n1) Agac Olustur"
           "\n2) Listele"
           "\n3) Guncelle"
           "\n4) Sil"
           "\n0) Cikis");

    printf("\nSecim: ");
    scanf("%d", &option);

    return option;
}



int main() {

    char addType, name[NAME_LIMIT];
    int option, newMidterm, newFinal;
    TreeNode *root, *node;
    FILE *file;

    while ((option = Menu()) != 0) {
        switch (option) {
            case 1:
                root = NULL;
                printf("\nOgrenciler ortalamaya gore mi, numaraya gore mi eklenecek? (n/o): ");
                scanf(" %c", &addType);
                if(addType != 'n' && addType != 'o') {
                    printf("\nBilinmeyen ekleme tipi girildi. Agac olusturulamadi.");
                    break;
                }
                file = fopen("ogrenci.txt", "r");
                root = AddTreeFromFile(file, READ_FORMAT, root, addType);
                fclose(file);
                printf("\nAgac olusturuldu.");
                break;
            case 2:
                printf("\n");
                PrintInOrder(root);
                break;
            case 3:
                printf("\nGuncellenecek ogrencinin ismini giriniz: ");
                scanf(" %[^\n]s", name);
                printf("\nYeni vize notu: ");
                scanf("%d", &newMidterm);
                printf("\nYeni final notu: ");
                scanf("%d", &newFinal);
                FindAndUpdateNode(root, name, newMidterm, newFinal);
                break;
            case 4:
                printf("\nSilinecek ogrencinin ismini girin: ");
                scanf(" %[^\n]s", name);
                node = FindNode(root, name);
                if (node == NULL) {
                    printf("\nOgrenci bulunamadi.");
                    break;
                }
                root = PopNode(root, node);
                printf("\nOgrenci silindi.");
                break;
            default:
                printf("\nMenude olmayan bir secenek girildi.");
        }
    }

    return 0;
}
