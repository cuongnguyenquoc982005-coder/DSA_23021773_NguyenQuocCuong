
#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> list;

public:
    // Khoi tao Stack rong: O(1)
    Stack() {}

    // Kiem tra Stack rong: O(1)
    bool isEmpty() {
        return list.empty();
    }

    // Them phan tu vao dinh Stack: O(1) trung binh
    void push(int x) {
        list.push_back(x);
        cout << "Da them: " << x << endl;
    }

    // Xoa phan tu tren dinh Stack: O(1) trung binh
    void pop() {
        if (isEmpty()) {
            cout << "Stack rong, khong the xoa!" << endl;
            return;
        }

        cout << "Phan tu bi xoa: " << list.back() << endl;
        list.pop_back();
    }

    // Lay gia tri phan tu tren dinh: O(1)
    void top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return;
        }

        cout << "Phan tu dinh Stack: "
             << list.back() << endl;
    }

    // In Stack tu dinh xuong day: O(n)
    void display() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return;
        }

        cout << "Stack (dinh -> day): ";
        for (int i = (int)list.size() - 1; i >= 0; i--) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, x;

    do {
        cout << "\n===== STACK BANG LIST =====" << endl;
        cout << "1. Push (them)" << endl;
        cout << "2. Pop (xoa)" << endl;
        cout << "3. Top (xem dinh)" << endl;
        cout << "4. Kiem tra rong" << endl;
        cout << "5. In Stack" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri: ";
            cin >> x;
            s.push(x);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.top();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack dang rong!" << endl;
            else
                cout << "Stack khong rong!" << endl;
            break;

        case 5:
            s.display();
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

