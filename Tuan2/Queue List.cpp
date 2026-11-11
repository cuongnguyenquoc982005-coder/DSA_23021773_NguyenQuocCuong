
#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
    vector<int> list;

public:
    // Khoi tao Queue rong:do phuc tap O(1) 
    Queue() {}

    // Kiem tra Queue rong: do phuc tap O(1)
    bool isEmpty() {
        return list.empty();
    }

    // Them phan tu vao cuoi Queue: do phuc tap O(1)
    void enqueue(int x) {
        list.push_back(x);
        cout << "Da them: " << x << endl;
    }

    // Xoa phan tu dau Queue: do phuc tap O(n)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue rong, khong the xoa!" << endl;
            return;
        }

        cout << "Phan tu bi xoa: " << list[0] << endl;
        list.erase(list.begin());
    }

    // Xem phan tu dau Queue: do phuc tapO(1)
    void front() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return;
        }

        cout << "Phan tu dau Queue: " << list[0] << endl;
    }

    // Xem phan tu cuoi Queue: do phuc tap O(1)
    void rear() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return;
        }

        cout << "Phan tu cuoi Queue: "
             << list[list.size() - 1] << endl;
    }

    // In Queue:do phuc tap O(n)
    void display() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return;
        }

        cout << "Queue (dau -> cuoi): ";

        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, x;

    do {
        cout << "\nQUEUE BANG LIST" << endl;
        cout << "1. Enqueue (them)" << endl;
        cout << "2. Dequeue (xoa)" << endl;
        cout << "3. Front (xem dau)" << endl;
        cout << "4. Rear (xem cuoi)" << endl;
        cout << "5. Kiem tra rong" << endl;
        cout << "6. In Queue" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri: ";
            cin >> x;
            q.enqueue(x);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.front();
            break;

        case 4:
            q.rear();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue rong!" << endl;
            else
                cout << "Queue khong rong!" << endl;
            break;

        case 6:
            q.display();
            break;

        case 0:
            cout << "Ket thuc chuong trinh!" << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);

    return 0;
}

