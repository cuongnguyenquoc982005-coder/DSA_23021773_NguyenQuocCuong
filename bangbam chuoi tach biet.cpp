
#include <iostream>
using namespace std;
const int SIZE = 10;
// Node cua danh sach lien ket
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Lop bang bam
class HashTable {
private:
    Node* table[SIZE];

    // Ham bam
    int hashFunction(int key) {
        return (key % SIZE + SIZE) % SIZE;
    }

public:
    // Khoi tao bang bam
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }

    // Them phan tu
    void insert(int key) {
        int index = hashFunction(key);

        // Kiem tra phan tu da ton tai
        Node* p = table[index];
        while (p != NULL) {
            if (p->data == key) {
                cout << "Phan tu da ton tai!\n";
                return;
            }
            p = p->next;
        }
        // Chen vao dau danh sach
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
        cout << "Da them " << key << endl;
    }
    // Tim kiem phan tu
    bool search(int key) {
        int index = hashFunction(key);
        Node* p = table[index];

        while (p != NULL) {
            if (p->data == key)
                return true;
            p = p->next;
        }

        return false;
    }

    // Xoa phan tu
    void remove(int key) {
        int index = hashFunction(key);
        Node* p = table[index];
        Node* prev = NULL;

        while (p != NULL && p->data != key) {
            prev = p;
            p = p->next;
        }

        if (p == NULL) {
            cout << "Khong tim thay phan tu!\n";
            return;
        }

        if (prev == NULL) {
            table[index] = p->next;
        } else {
            prev->next = p->next;
        }

        delete p;
        cout << "Da xoa " << key << endl;
    }

    // In bang bam
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Bucket " << i << ": ";

            Node* p = table[i];
            while (p != NULL) {
                cout << p->data << " -> ";
                p = p->next;
            }

            cout << "NULL" << endl;
        }
    }

    // Giai phong bo nho
    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Node* p = table[i];

            while (p != NULL) {
                Node* temp = p;
                p = p->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable ht;
    int choice, x;

    do {
        cout << "\n BANG BAM LINKED LIST \n";
        cout << "1. Them phan tu\n";
        cout << "2. Tim kiem\n";
        cout << "3. Xoa phan tu\n";
        cout << "4. In bang bam\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri: ";
            cin >> x;
            ht.insert(x);
            break;

        case 2:
            cout << "Nhap gia tri can tim: ";
            cin >> x;
            if (ht.search(x))
                cout << "Tim thay " << x << endl;
            else
                cout << "Khong tim thay " << x << endl;
            break;

        case 3:
            cout << "Nhap gia tri can xoa: ";
            cin >> x;
            ht.remove(x);
            break;

        case 4:
            ht.display();
            break;

        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}

