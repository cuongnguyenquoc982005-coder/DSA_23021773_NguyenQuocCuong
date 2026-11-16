
#include <iostream>
#include <string>
using namespace std;

// Khai bao Node
struct Node {
    string name;
    string type;
    string value;
    Node* next;

    Node(string n, string t, string v) {
        name = n;
        type = t;
        value = v;
        next = NULL;
    }
};

// Lop Symbol Table
class SymbolTable {
private:
    Node* head;

public:
    // Khoi tao danh sach
    SymbolTable() {
        head = NULL;
    }

    // Huy danh sach
    ~SymbolTable() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Kiem tra danh sach rong
    bool isEmpty() {
        return head == NULL;
    }

    // Them phan tu
    void insert(string name, string type, string value) {
        Node* p = head;

        // Kiem tra ten da ton tai
        while (p != NULL) {
            if (p->name == name) {
                cout << "Symbol da ton tai\n";
                return;
            }
            p = p->next;
        }

        // Tao Node moi
        Node* newNode = new Node(name, type, value);

        // Them vao dau danh sach
        newNode->next = head;
        head = newNode;

        cout << "Them thanh cong\n";
    }

    // Tim kiem phan tu
    void search(string name) {
        Node* p = head;

        while (p != NULL) {
            if (p->name == name) {
                cout << "\nTim thay Symbol\n";
                cout << "Name: " << p->name << endl;
                cout << "Type: " << p->type << endl;
                cout << "Value: " << p->value << endl;
                return;
            }

            p = p->next;
        }

        cout << "Khong tim thay Symbol\n";
    }

    // Xoa phan tu
    void remove(string name) {
        Node* p = head;
        Node* prev = NULL;

        // Tim Node can xoa
        while (p != NULL && p->name != name) {
            prev = p;
            p = p->next;
        }

        if (p == NULL) {
            cout << "Khong tim thay Symbol de xoa\n";
            return;
        }

        // Neu xoa Node dau
        if (prev == NULL) {
            head = head->next;
        }
        else {
            prev->next = p->next;
        }

        delete p;

        cout << "Xoa thanh cong!\n";
    }

    // Hien thi danh sach
    void display() {
        if (isEmpty()) {
            cout << "Symbol Table rong!\n";
            return;
        }

        Node* p = head;

        cout << "\n SYMBOL TABLE\n";
        cout << "Name\tType\tValue\n";

        while (p != NULL) {
            cout << p->name << "\t"
                 << p->type << "\t"
                 << p->value << endl;

            p = p->next;
        }
    }
};

// Ham main
int main() {
    SymbolTable st;

    int choice;
    string name, type, value;

    do {
        cout << "\n MENU\n";
        cout << "1. Insert (Them)\n";
        cout << "2. Search (Tim kiem)\n";
        cout << "3. Delete (Xoa)\n";
        cout << "4. Display (Hien thi)\n";
        cout << "0. Exit (Thoat)\n";

        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap ten: ";
            cin >> name;

            cout << "Nhap kieu du lieu: ";
            cin >> type;

            cout << "Nhap gia tri: ";
            cin >> value;

            st.insert(name, type, value);
            break;

        case 2:
            cout << "Nhap ten can tim: ";
            cin >> name;

            st.search(name);
            break;

        case 3:
            cout << "Nhap ten can xoa: ";
            cin >> name;

            st.remove(name);
            break;

        case 4:
            st.display();
            break;

        case 0:
            cout << "Ket thuc chuong trinh\n";
            break;

        default:
            cout << "Lua chon khong hop le\n";
        }

    } while (choice != 0);

    return 0;
}

