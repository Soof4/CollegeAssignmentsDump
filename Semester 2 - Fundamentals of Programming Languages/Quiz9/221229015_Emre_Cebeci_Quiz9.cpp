#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct TreeNode {
    int value;
    TreeNode *leftNode;
    TreeNode *rightNode;

}TreeNode;


TreeNode *newNode(int value) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    return newNode;
}

TreeNode *AddNode(TreeNode *root, int value) {
    if (root == NULL) {
        return newNode(value);
    }

    if(value <= root->value) {
        root->leftNode = AddNode(root->leftNode, value);

    }
    else {
        root->rightNode = AddNode(root->rightNode, value);
    }

    return root;
}

void PrintInOrder(TreeNode *root) {
    if(root == NULL) {
        return;
    }

    PrintInOrder(root->leftNode);
    printf("%d ", root->value);
    PrintInOrder(root->rightNode);
}

int GetSum(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int sum = root->value;
    sum += GetSum(root->leftNode);
    sum += GetSum(root->rightNode);
    return sum;
}

int GetElementCount(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int count = 1;
    count += GetElementCount(root->leftNode);
    count += GetElementCount(root->rightNode);

    return count;
}

double GetMean(TreeNode *root) {
    return (double)GetSum(root)/GetElementCount(root);
}

void PrintGreater(TreeNode *root, double number) {
    if (root == NULL) {
        return;
    }

    PrintGreater(root->leftNode, number);
    if (root->value > number) {
        printf("%d ", root->value);
    }
    PrintGreater(root->rightNode, number);
}



int main() {
    srand(time(NULL));

    TreeNode *root = NULL;
    int n;

    printf("\nN: ");
    scanf("%d", &n);

    if(n<1) {
        printf("\nDizi olusturulamadi.");
        return 0;
    }

    for (int i=0; i<n; i++) {
        root = AddNode(root, 10 + rand()%41);
    }

    double mean = GetMean(root);
    printf("\nOlusturulan dizi: ");
    PrintInOrder(root);
    printf("\nOrtalama: %.2lf", mean);

    printf("\nOrtalamadan buyuk sayilar: ");
    PrintGreater(root, mean);

    return 0;
}
