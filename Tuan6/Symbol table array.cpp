
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

// Khai bao cau truc Symbol
struct Symbol {
    string name;    // Ten bien
    string type;    // Kieu du lieu
    string value;   // Gia tri
};

// Lop Symbol Table
class SymbolTable {
private:
    Symbol table[MAX];
    int n;          // So luong phan tu

public:
    // Khoi tao
    SymbolTable() {
        n = 0;
    }

    // Kiem tra rong
    bool isEmpty() {
        return n == 0;
    }

    // Kiem tra day
    bool isFull() {
        return n == MAX;
    }

    // Them phan tu
    void insert(string name, string type, string value) {

        if (isFull()) {
            cout << "Symbol Table da day\n";
            return;
        }

        // Kiem tra ten da ton tai
        for (int i = 0; i < n; i++) {
            if (table[i].name == name) {
                cout << "Symbol da ton tai\n";
                return;
            }
        }

        table[n].name = name;
        table[n].type = type;
        table[n].value = value;

        n++;

        cout << "Them thanh cong!\n";
    }

    // Tim kiem
    void search(string name) {
        for (int i = 0; i < n; i++) {
            if (table[i].name == name) {
                cout << "\nTim thay Symbol\n";
                cout << "Name: " << table[i].name << endl;
                cout << "Type: " << table[i].type << endl;
                cout << "Value: " << table[i].value << endl;
                return;
            }
        }

        cout << "Khong tim thay Symbol!\n";
    }

    // Xoa phan tu
    void remove(string name) {
        int pos = -1;

        // Tim vi tri can xoa
        for (int i = 0; i < n; i++) {
            if (table[i].name == name) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Khong tim thay Symbol de xoa\n";
            return;
        }

        // Dich cac phan tu sang trai
        for (int i = pos; i < n - 1; i++) {
            table[i] = table[i + 1];
        }

        n--;

        cout << "Xoa thanh cong\n";
    }

    // Hien thi
    void display() {
        if (isEmpty()) {
            cout << "Symbol Table rong\n";
            return;
        }

        cout << "\n SYMBOL TABLE\n";
        cout << "Name\tType\tValue\n";

        for (int i = 0; i < n; i++) {
            cout << table[i].name << "\t"
                 << table[i].type << "\t"
                 << table[i].value << endl;
        }
    }
};

// Ham main
int main() {
    SymbolTable st;

    int choice;
    string name, type, value;

    do {
        cout << "\n MENU \n";
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

