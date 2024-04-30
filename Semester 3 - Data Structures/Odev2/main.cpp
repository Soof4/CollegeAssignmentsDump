#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct Node {
    string name;
    string surname;
    int number;
    int age;
    int height = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *arr[10];

    Node(string name, string surname, int number, int age) : name(name), surname(surname), number(number), age(age) { }
    Node() {
        for (int i = 0; i < 10; i++) {
            arr[i] = new Node();
        }
    }
};


// Enums
enum RotationType {
    Left,
    Right
};


// Utility Functions
int countNodes(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return countNodes(node->left) + 1 + countNodes(node->right);
}

Node *getMin(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}

Node *getMax(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->right != nullptr) {
        node = node->right;
    }

    return node;
}

int getHeight(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void rotate(Node *&root, RotationType rotationType) {
    Node *temp = root;

    if (rotationType == Left) {    // Left rotation
        root = temp->right;
        temp->right = root->left;
        root->left = temp;
    }
    else {    // Right rotation
        root = temp->left;
        temp->left = root->right;
        root->right = temp;
    }

    // Update the heights
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void copyNodeData(Node *copyTo, Node *copyFrom) {
    copyTo->name = copyFrom->name;
    copyTo->surname = copyFrom->surname;
    copyTo->number = copyFrom->number;
    copyTo->age = copyFrom->age;
}

Node *findNode(Node *root, int key) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->number == key) {
        return root;
    }

    if (root->number > key) {
        return findNode(root->left, key);
    }
    else {
        return findNode(root->right, key);
    }
}


// Insertion and Deletion
void insert(Node *&root, Node *newNode) {
    if (root == nullptr) {
        root = newNode;
    }
    else if (newNode->number == root->number) {
        cout << "Bu numaraya ait bir kisi zaten ekli." << endl;
        return;
    }
    else if (newNode->number > root->number) {    // If new number is greater than current node's number => add to the right
        insert(root->right, newNode);

        if (getBalanceFactor(root) < -1) {    // If right is unbalanced
            if (newNode->number > root->right->number) {    // If it's going to be added to right of right
                rotate(root, Left);
            }
            else {    // It's going to be added to left of right
                rotate(root->right, Right);
                rotate(root, Left);
            }
        }
    }
    else {    // If number is lesser than current node's number => add to the left
        insert(root->left, newNode);

        if (getBalanceFactor(root) > 1) {    // If left is unbalanced
            if (newNode->number < root->left->number) {    // If it's going to be added to left of right
                rotate(root, Right);
            }
            else {    // It's going to be added to right of left
                rotate(root->left, Left);
                rotate(root, Right);
            }
        }
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void autoInsertFromFile(Node *&root, string dir) {
    try {
        ifstream fs = ifstream (dir);

        string line;
        getline(fs, line);  // Skip the title line

        while (getline(fs, line)) {
            istringstream ss = istringstream(line);

            string name, surname;
            int number, age;

            if (ss >> number >> name >> surname >> age) {
                insert(root, new Node(name, surname, number, age));
            }
        }

    }
    catch (const exception &e) {
        cout << "Dosya okumada hata olustu." << endl;
    }
}

Node *deletion(Node *root, int key) {
    if (root == nullptr) {    // Key is not found or tree is empty
        return nullptr;
    }

    if (root->number > key) {
        root->left = deletion(root->left, key);
    }
    else if (root->number < key) {
        root->right = deletion(root->right, key);
    }
    else {    // Key is found
        if (root->left == nullptr) {    // node has a right child
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {    // node has a left child
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = getMin(root->right);    // Find the successor
        copyNodeData(root, temp);    // Move successor's data to root
        root->right = deletion(root->right, temp->number);    // Delete the successor from the bottom of tree
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;    // Update the height

    // Rotations
    int balFactor = getBalanceFactor(root);
    int leftBalFactor = getBalanceFactor(root->left);
    int rightBalFactor = getBalanceFactor(root->right);

    // Single Rotations
    if (balFactor > 1 && leftBalFactor >= 0) {
        rotate(root, Right);
    }
    if (balFactor < -1 && rightBalFactor <= 0) {
        rotate(root, Left);
    }
    // Double Rotations
    if (balFactor > 1 && leftBalFactor < 0) {
        rotate(root->left, Left);
        rotate(root, Right);
    }
    if (balFactor < -1 && rightBalFactor > 0) {
        rotate(root->right, Right);
        rotate(root, Left);
    }

    return root;
}


// Print functions
void printNode(Node *node) {
    cout << setw(9) << left << node->number << "  ";
    cout << setw(9) << left << node->name  << "  ";
    cout << setw(6) << left << node->surname << "  ";
    cout << setw(2) << left << node->age << endl;
}

void printPreOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    printNode(root);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    printInOrder(root->left);
    printNode(root);
    printInOrder(root->right);
}

void printPostOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    printNode(root);
}

void printLeavesInOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    printLeavesInOrder(root->left);
    if (root->left == nullptr && root->right == nullptr) {
        printNode(root);
    }
    printLeavesInOrder(root->right);
}


// Menu functions
void menu(Node *&root) {
    while (true) {
        cout << "\nMENU:\n"
                "1. Dosyadan oku\n"
                "2. Yeni kisi ekle\n"
                "3. Kisi sil\n"
                "4. Agaci yazdir\n"
                "5. Subtree'deki dugum sayisini bul\n"
                "6. Subtree'nin minimum ve maksimumunu bul\n"
                "7. Yapraklari yazdir\n"
                "8. Cikis\n"
                "Secim (1-8): ";

        int choice = 8;
        cin >> choice;
        switch (choice) {
            case 1: {    // Dosyadan oku
                cout << endl << "Dosya ismini giriniz: ";
                string dir = "";
                cin >> dir;

                autoInsertFromFile(root, dir);
                break;
            }
            case 2: {   // Yeni kisi ekle
                cout << endl << "Yeni kisi ismi giriniz: ";
                string name = "";
                cin >> name;

                cout << "Yeni kisi soyismi giriniz: ";
                string surname = "";
                cin >> surname;

                cout << "Yeni kisi numarasi giriniz: ";
                int number = 0;
                cin >> number;

                cout << "Yeni kisi yasini giriniz: ";
                int age = 0;
                cin >> age;

                insert(root, new Node(name, surname, number, age));
                cout << "\nInOrder: " << endl;
                printInOrder(root);
                break;
            }
            case 3: {    // Kisi sil
                cout << endl << "Silinecek kisinin numarasini giriniz: ";
                int number = 0;
                cin >> number;

                deletion(root, number);
                cout << "\nInOrder: " << endl;
                printInOrder(root);
                break;
            }
            case 4: {  // Agaci yazdir
                cout << endl <<"Siralama turleri:\n"
                               "1. PreOrder\n"
                               "2. InOrder\n"
                               "3. PostOrder\n"
                               "Bir tur giriniz (1/2/3): ";

                int orderType = 1;
                cin >> orderType;
                switch (orderType) {
                    case 1:
                        cout << endl << "PreOrder:" << endl;
                        printPreOrder(root);
                        break;
                    case 2:
                        cout << endl << "InOrder:" << endl;
                        printInOrder(root);
                        break;
                    case 3:
                        cout << endl << "PostOrder:" << endl;
                        printPostOrder(root);
                        break;
                    default:
                        cout << "Listede olmayan bir secenek girildi." << endl;
                }
                break;
            }
            case 5: {   // Subtree'deki dugum sayisini bul
                cout << endl << "Subtreenin root'u olan ogrencinin numarasini giriniz: ";
                int number = 0;
                cin >> number;

                Node *node = findNode(root, number);
                cout << "Dugum sayisi: " << countNodes(node);
                break;
            }
            case 6: {  // Subtree'nin minimum ve maksimumunu bul
                cout << endl << "Subtreenin root'u olan ogrencinin numarasini giriniz: ";
                int number = 0;
                cin >> number;

                Node *node = findNode(root, number);

                cout << "Minimum: ";
                printNode(getMin(node));

                cout << "Maksimum: ";
                printNode(getMax(node));
                break;
            }
            case 7: {  // Yapraklari yazdir
                cout << endl << "Yapraklar:" << endl;
                printLeavesInOrder(root);
                break;
            }
            case 8: {   // Cikis
                cout << "Program sonlandirildi.";
                return;
            }
            default: {
                cout << "Menude olmayan bir secenek girildi." << endl;
            }
        }
    }
}


int main() {
    Node *root = nullptr;
    menu(root);
}
