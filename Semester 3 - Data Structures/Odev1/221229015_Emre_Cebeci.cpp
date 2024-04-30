#include <iostream>
#include <stdio.h>
#include <cctype>
#include <string>

#define READ_FORMAT_NO_ID "%20s\t%20s\t%4d\t%12d\n"
#define READ_FORMAT "%4d\t%20s\t%20s\t%4d\t%12d\n"
#define TITLE_READ_FORMAT_NO_ID "%20s\t%20s\t%4s\t%12s\n"
#define TITLE_READ_FORMAT "%4s\t%20s\t%20s\t%4s\t%12s\n"

using namespace std;


struct node {
    int id;
    string name;
    string surname;
    int age;
    int salary;
    struct node *next;
};


bool compareNodes(node *n1, node *n2) {
    if (n2->age == n1->age) {
        if (n2->salary == n1->salary) {
            string fullName1 = n1->name + n1->surname;
            string fullName2 = n2->name + n2->surname;

            if (fullName2.compare(fullName1) <= 0) {
                return true;
            }
        }
        else if (n2->salary < n1->salary) {
            return true;
        }
    }
    else if (n2->age < n1->age) {
        return true;
    }

    return false;
}

string toLower(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = ::tolower(str[i]);
    }
    return str;
}

bool areEqual(string str1, string str2) {
    return toLower(str1).compare(toLower(str2)) == 0;
}

struct node *getEndNode(node *head) {
    struct node *temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    return temp;
}

void printList(node *head, bool quiet = false) {
    if (head == NULL) {
        if (!quiet) {
            cout << "Liste bos." << endl;
        }
        return;
    }
    printf(TITLE_READ_FORMAT_NO_ID, "Isim", "Soyisim", "Yas", "Maas");
    printf("----------------------------------------------------------------------------\n");

    node *temp = head;
    while (temp->next != head) {
        printf(READ_FORMAT_NO_ID, temp->name.c_str(), temp->surname.c_str(), temp->age, temp->salary);
        temp = temp->next;
    }
    printf(READ_FORMAT_NO_ID, temp->name.c_str(), temp->surname.c_str(), temp->age, temp->salary);
}

bool strEndsWith(string str, string suffix) {
    if (suffix.length() == 0) {
        return true;
    }

    if (str.length() < suffix.length()) {
        return false;
    }

    for (int i = suffix.length() - 1, j = str.length() - 1; i >= 0; i--, j--) {
        if (str[j] != suffix[i]) {
            return false;
        }
    }

    return true;
}

struct node *addNode(node *head, int id, string name, string surname, int age, int salary) {
    struct node *newNode = new node();
    newNode->id = id;
    newNode->name = name;
    newNode->surname = surname;
    newNode->age = age;
    newNode->salary = salary;
    newNode->next = head;

    // Add the new node
    if (head == NULL) {
        head = newNode;
        head->next = head;
    }
    else if (head->next == head) {
        if (compareNodes(head, newNode)) {
            struct node *temp = head;
            head = newNode;
            newNode->next = temp;
            temp->next = newNode;
        }
        else {
            head->next = newNode;
            newNode->next = head;
        }
    }
    else {
        if (compareNodes(head, newNode)) {
            struct node *endNode = getEndNode(head);

            endNode->next = newNode;
            head = newNode;
        }
        else {
            struct node *temp = head->next, *preTemp = head;

            while (temp != head) {
                if (compareNodes(temp, newNode)) {
                    break;
                }

                preTemp = temp;
                temp = temp->next;
            }

            preTemp->next = newNode;
            newNode->next = temp;
        }
    }

    return head;
}


struct node *createListFromFile(string dir, node *head, bool quiet = false) {
    if (!strEndsWith(dir, ".txt")) {
        dir += ".txt";
    }

    FILE *file = fopen(dir.c_str(), "r");

    if(file == NULL) {
        if (!quiet) {
            cout << "Hata: Dosya bulumadi." << endl;
        }
        return NULL;
    }

    char temp[50];
    fscanf(file, TITLE_READ_FORMAT, temp, temp, temp, temp, temp);    // Read the titles line

    int id, age, salary;
    char name[50], surname[50];
    while(fscanf(file, READ_FORMAT, &id, name, surname, &age, &salary) != EOF) {
        head = addNode(head, id, (string)name, (string)surname, age, salary);
    }

    cout << "Dosyadan liste olusturuldu." << endl;

    fclose(file);
    return head;
}

struct node *delNode(node *head, string name, string surname) {
    if (head == NULL) {
        return NULL;
    }

    if (areEqual(head->name, name) && areEqual(head->surname, surname)) {
        if (head == head->next) {
            cout << endl << head->name << " " << head->surname << " listeden silindi." << endl;
            delete head;
            return NULL;
        }

        struct node *endNode = getEndNode(head);
        head = head->next;
        delete endNode->next;
        endNode->next = head;
    }
    else {
        struct node *temp = head->next, *preTemp = head;

        while(temp != head) {
            if (areEqual(temp->name, name) && areEqual(temp->surname, surname)) {
                break;
            }

            preTemp = temp;
            temp = temp->next;
        }

        cout << endl << temp->name << " " << temp->surname << " listeden silindi." << endl;
        preTemp->next = temp->next;
        delete temp;
    }

    return head;
}

struct node *delNode(node *head, node *target) {
    if (head == NULL) {
        cout << "Liste bos." << endl;
        return NULL;
    }

    if (head == target) {
        if (head == head->next) {
            delete head;
            return NULL;
        }

        struct node *endNode = getEndNode(head);
        head = head->next;
        delete endNode->next;
        endNode->next = head;
    }
    else {
        struct node *temp = head->next, *preTemp = head;

        while(temp != head) {
            if (temp == target) {
                break;
            }

            preTemp = temp;
            temp = temp->next;
        }

        preTemp->next = temp->next;
        delete temp;
    }

    return head;
}

void printCorpInfo(node *head) {
    if (head == NULL) {
        cout << "Liste bos." << endl;
        return;
    }

    struct node *temp = head;
    int sum = 0, cnt = 0;

    cout << "Toplam personel maasi: ";
    while (temp->next != head) {
        cout << temp->salary;
        sum += temp->salary;
        temp = temp->next;
        cnt++;
        cout << " + ";
    }
    cnt++;
    sum += temp->salary;
    cout << temp->salary << " = " << sum << " TL" << endl;
    cout << "Ortalama personel maasi: " << sum << " / " << cnt << " = " << sum / cnt << endl;
    cout << "Toplam personel sayisi: " << cnt << endl;

}

double getMeanSalary(node *head) {
    int cnt = 0;
    double sum = 0;
    struct node *temp = head;

    while (temp-> next != head) {
        sum += temp->salary;
        cnt++;
        temp = temp->next;
    }
    sum += temp->salary;
    cnt++;

    return sum / cnt;
}

string lowOrHighSalary(double mean, int salary) {
    if (salary >= mean) {
        return "ust gelirli";
    }

    return "alt gelirli";
}

void searchPerson(node *head, string name, string surname) {
    if (head == NULL) {
        cout << "Liste bos." << endl;
        return;
    }
    struct node *temp = head;

    while (temp->next != head) {
        if (areEqual(temp->name, name) && areEqual(temp->surname, surname)) {

            cout << endl << temp->name << " " << temp->surname << " listede mevcuttur." << endl;
            cout << "  Yasi: " << temp->age << endl;
            cout << "  Maasi: " << temp->salary << endl;
            cout << "  Gelir durumu: " << lowOrHighSalary(getMeanSalary(head), temp->salary) << endl;
            return;
        }

        temp = temp->next;
    }

    if (areEqual(temp->name, name) && areEqual(temp->surname, surname)) {

        cout << endl << temp->name << " " << temp->surname << " listede mevcuttur." << endl;
        cout << "  Yasi: " << temp->age << endl;
        cout << "  Maasi: " << temp->salary << endl;
        cout << "  Gelir durumu: " << lowOrHighSalary(getMeanSalary(head), temp->salary) << endl;
        return;
    }

    cout << name << " " << surname << " listede mevcut degildir." << endl;
}

struct node *swapNodes(node *head, node *preNode1, node *preNode2) {
    if (head == NULL) {
        cout << "Liste bos." << endl;
        return head;
    }

    struct node *node1 = preNode1->next;
    struct node *node2 = preNode2->next;

    if (node1 == node2) {
        return head;
    }

    preNode1->next = node2;
    preNode2->next = node1;

    struct node *temp = node2->next;
    node2->next = node1->next;
    node1->next = temp;

    if (head == node1) {
        head = node2;
    }
    else if (head == node2) {
        head = node1;
    }

    return head;
}

int sizeOfList(node *head) {
    struct node *temp = head;
    int cnt = 0;

    while (temp->next != head) {
        cnt++;
        temp = temp->next;
    }

    return ++cnt;
}

struct node *sortAlphabetical(node *head) {
    if (head == NULL) {
        return head;
    }

    int size = sizeOfList(head);

    for (int i = 0; i < size; i++) {
        struct node *temp, *preTemp;
        preTemp = getEndNode(head);
        temp = head;

        while (temp->next != head) {
            // Concat into the full name
            string fullName1 = toLower(temp->name + temp->surname);
            string fullName2 = toLower(temp->next->name + temp->next->surname);

            if (fullName1.compare(fullName2) > 0) {
                head = swapNodes(head, preTemp, temp);
            }

            preTemp = temp;
            temp = temp->next;
        }
    }

    return head;
}

void saveList(node *head, string dir) {
    if (head == NULL) {
        cout << "Liste bos. Kayit iptal edildi." << endl;
        return;
    }

    if (!strEndsWith(dir, ".txt")) {
        dir += ".txt";
    }

    FILE *file = fopen(dir.c_str(), "w");

    struct node *temp = head;

    fprintf(file, TITLE_READ_FORMAT, "ID", "Isim", "Soyisim", "Yas", "Maas");

    while (temp->next != head) {
        fprintf(file, READ_FORMAT, temp->id, temp->name.c_str(), temp->surname.c_str(), temp->age, temp->salary);
        temp = temp->next;
    }

    fprintf(file, READ_FORMAT, temp->id, temp->name.c_str(), temp->surname.c_str(), temp->age, temp->salary);
    fclose(file);

    cout << "Dosya " << dir << " olarak kaydedildi." << endl;
}

struct node *purgeList(node *head) {
    while (head != NULL) {
        head = delNode(head, head);
    }

    return NULL;
}

void menu() {
    cout << endl << "Bilgi-1: Isim ve soyisim istenilen seceneklerde buyuk/kucuk harfe duyarlilik yoktur." << endl;
    cout << "Bilgi-2: Eger listede ismi veya soyismi 20 karakterden buyuk olan bir kisi olursa liste kayacaktir." << endl;
    struct node *head = createListFromFile("kayit.txt", NULL, true);
    printList(head, true);

    while (true) {
        int choice;

        cout << endl << "MENU:" << endl;
        cout << "1. Dosyadan oku" << endl;
        cout << "2. Yeni kisi ekle" << endl;
        cout << "3. Kisi sil" << endl;
        cout << "4. Kisi ara" << endl;
        cout << "5. Listele" << endl;
        cout << "6. Kurum bilgisi" << endl;
        cout << "7. Personel kayit" << endl;
        cout << "-> Cikmak icin herhangi farkli bir sayi girin." << endl;
        cout << "Secim: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string dir;
                cout << "Dosyanin ismini/dizinini girin: ";
                cin >> dir;
                head = purgeList(head);
                head = createListFromFile(dir, head);
                printList(head);
                break;
            }
            case 2: {    // Add person
                string name, surname;
                int id, age, salary;
                cout << "Yeni kisi ID girin: ";
                cin >> id;

                cout << "Yeni kisi ismi girin: ";
                cin >> name;

                cout << "Yeni kisi soyadi girin: ";
                cin >> surname;

                cout << "Yeni kisi yasi girin: ";
                cin >> age;

                cout << "Yeni kisi maasi girin: ";
                cin >> salary;

                head = addNode(head, id, name, surname, age, salary);

                cout << endl << name << " " << surname << " listeye eklendi." << endl;
                printList(head);
                break;
            }
            case 3: {    // Delete person
                string name, surname;
                cout << "Silinecek kisinin ismini girin: ";
                cin >> name;

                cout << "Silinecek kisinin soyismini girin: ";
                cin >> surname;

                head = delNode(head, name, surname);

                printList(head);
                break;
            }
            case 4: {    // Search person
                string name, surname;

                cout << "Aranacak kisinin ismini girin: ";
                cin >> name;

                cout << "Aranacak kisinin soyismini girin: ";
                cin >> surname;

                searchPerson(head, name, surname);
                break;
            }
            case 5: {    // List alphabetically
                head = sortAlphabetical(head);
                printList(head);
                break;
            }
            case 6: {    // Show corporation info
                printCorpInfo(head);
                break;
            }
            case 7: {    // Save the list
                string dir;
                cout << "Yeni dosyanin ismini/dizinini girin: ";
                cin >> dir;
                saveList(head, dir);
                break;
            }
            default: {
                return;
            }

        }
    }
}

int main(int argc, char *argv[]){
    menu();
}
