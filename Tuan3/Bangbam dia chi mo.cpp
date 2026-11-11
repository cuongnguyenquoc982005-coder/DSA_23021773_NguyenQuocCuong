
#include <iostream>
using namespace std;
const int SIZE = 10;
class HashTable {
private:
    int table[SIZE];
    bool occupied[SIZE];
    // Ham bam
    int hashFunction(int key) {
        return key % SIZE;
    }
public:
    // Khoi tao bang bam
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            occupied[i] = false;
        }
    }
    // Them phan tu bang Linear Probing
    void insert(int key) {
        int index = hashFunction(key);
        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;

            if (!occupied[pos]) {
                table[pos] = key;
                occupied[pos] = true;
                cout << "Da them " << key
                     << " vao vi tri " << pos << endl;
                return;
            }
        }
        cout << "Bang bam da day!\n";
    }
    // Tim kiem phan tu
    bool search(int key) {
        int index = hashFunction(key);
        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;

            if (!occupied[pos]) {
                return false;
            }
            if (table[pos] == key) {
                cout << "Tim thay " << key
                     << " tai vi tri " << pos << endl;
                return true;
            }
        }
        return false;
    }
    // Hien thi bang bam
    void display() {
        cout << "Bang bam:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";

            if (occupied[i]) {
                cout << table[i];
            } else {
                cout << "EMPTY";
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;
    do {
        cout << "HASH TABLE\n";
        cout << "1. Them phan tu\n";
        cout << "2. Tim kiem\n";
        cout << "3. Hien thi\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Nhap key: ";
                cin >> key;
                ht.insert(key);
                break;

            case 2:
                cout << "Nhap key can tim: ";
                cin >> key;

                if (!ht.search(key)) {
                    cout << "Khong tim thay " << key << endl;
                }
                break;

            case 3:
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

