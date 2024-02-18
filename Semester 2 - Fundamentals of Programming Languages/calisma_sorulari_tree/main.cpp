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

void PrintPreOrder(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->value);
    PrintPreOrder(root->leftNode);
    PrintPreOrder(root->rightNode);
}

void PrintLevelOrder(TreeNode *root, TreeNode *startNode) {
    if (startNode == NULL || root == NULL) {
        return;
    }

    if (root == startNode) {
        printf("%d \n", root->value);
    }

    if (startNode->leftNode != NULL) {
        printf("%d ", startNode->leftNode->value);
    }
    if (startNode->rightNode != NULL) {
        printf("%d ", startNode->rightNode->value);
    }
    printf("\n");

    PrintLevelOrder(root, startNode->leftNode);
    PrintLevelOrder(root, startNode->rightNode);
}

int GetMaxValue(TreeNode *root) {
    if(root->rightNode == NULL) {
        return root->value;
    }
    return GetMaxValue(root->rightNode);
}

int GetMinValue(TreeNode *root) {
    if(root->leftNode == NULL) {
        return root->value;
    }
    return GetMinValue(root->leftNode);
}

int GetRange(TreeNode *root) {
    return GetMaxValue(root) - GetMinValue(root);
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
    if (root->value >= number) {
        printf("%d ", root->value);
    }
    PrintGreater(root->rightNode, number);
}

void PrintLesser(TreeNode *root, double number) {
    if (root == NULL) {
        return;
    }

    PrintLesser(root->rightNode, number);
    if (root->value <= number) {
        printf("%d ", root->value);
    }
    PrintLesser(root->leftNode, number);
}

void PrintInBetween(TreeNode *root, int num1, int num2) {
    if (root == NULL) {
        return;
    }

    if (num2 < num1) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    PrintInBetween(root->leftNode, num1, num2);
    if(root->value > num1 && root->value < num2) {
        printf("%d ", root->value);
    }
    PrintInBetween(root->rightNode, num1, num2);
}

void IncreaseAllNodes(TreeNode *root, int value) {
    if (root == NULL) {
        return;
    }

    root->value += value;
    IncreaseAllNodes(root->leftNode, value);
    IncreaseAllNodes(root->rightNode, value);
}

int CountEvenNumbers(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int count;
    root->value%2 == 0 ? count = 1 : count = 0;

    count += CountEvenNumbers(root->leftNode);
    count += CountEvenNumbers(root->rightNode);

    return count;
}

TreeNode *FindNode(TreeNode *root, int query) {
    if(root == NULL) {
        return NULL;
    }

    if (root->value == query) {
        return root;
    }

    TreeNode *temp = FindNode(root->leftNode, query);
    if (temp == NULL) {
        temp = FindNode(root->rightNode, query);
    }

    return temp;
}

int SubstractChildren(TreeNode *parent) {
    if (parent->leftNode == NULL && parent->rightNode == NULL) {
        return -1;
    }

    if (parent->leftNode != NULL && parent->rightNode != NULL) {
        return parent->rightNode->value - parent->leftNode->value;
    }

    if (parent->leftNode == NULL) {
        return parent->rightNode->value;
    }
    else {
        return parent->leftNode->value;
    }
}

int Eg10(TreeNode *root, int query) {
    TreeNode *parent = FindNode(root, query);
    if(parent == NULL) {
        return NULL;
    }

    return SubstractChildren(parent);
}



int main() {
    srand(time(NULL));

    TreeNode *root;

    for (int i=0; i<10; i++) {
        root = AddNode(root, rand()%201);
    }

    PrintInOrder(root);

    printf("\nMax value: %d", GetMaxValue(root));
    printf("\nMin value: %d", GetMinValue(root));
    printf("\nRange value: %d", GetRange(root));
    printf("\nMean value: %lf", GetMean(root));

    printf("\n");
    PrintGreater(root, GetMean(root));

    printf("\n");
    PrintLesser(root, GetMean(root));

    printf("\n");
    PrintInBetween(root, 40, 120);

    IncreaseAllNodes(root, 20);
    printf("\n");
    PrintInOrder(root);

    printf("\nEven number count: %d", CountEvenNumbers(root));

    printf("\n");
    PrintLevelOrder(root, root);

    int query, result;
    printf("\nAranacak sayi: ");
    scanf("%d", &query);
    result = Eg10(root, query);

    if (result == NULL) {
        printf("\nSayi bulunamadi.");
    }
    else if (result == -1) {
        printf("\nBu node'un cocuklari yok.");
    }
    else {
        printf("\nCocuklar arasindaki fark: %d", result);
    }
}