
#include <iostream>
using namespace std;

// Khai bao node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Cai dat Stack bang Linked List
class Stack {
private:
    Node* topNode;

public:
    // Khoi tao Stack rong (do phuc tap O(1)) 
    Stack() {
        topNode = NULL;
    }

    // Huy Stack, giai phong bo nho
    ~Stack() {//Do phuc tap O(n)) 
        while (!isEmpty()) {
            pop();
        }
    }

    // Kiem tra Stack rong(Do phuc tap O(1)) 
    bool isEmpty() {
        return topNode == NULL;
    }

    // Them phan tu vao Stack (Push)(Do phuc tap O(1)) 
    void push(int x) {
        Node* p = new Node(x);
        p->next = topNode;
        topNode = p;
        cout << "Da them " << x << " vao Stack\n";
    }

    // Lay va xoa phan tu dinh (Pop)(Do phuc tap O(1)) 
    void pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return;
        }

        Node* p = topNode;
        cout << "Phan tu bi xoa: " << p->data << endl;
        topNode = topNode->next;
        delete p;
    }

    // Xem phan tu dinh (Top)(Do phuc tap 0(1)) 
    void top() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return;
        }

        cout << "Phan tu dinh Stack: "
             << topNode->data << endl;
    }

    // In Stack tu dinh xuong day(Do phuc tap O(n)) 
    void display() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return;
        }

        Node* p = topNode;
        cout << "Stack (tu dinh xuong day): ";

        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, x;

    do {
        cout << " MENU STACK\n";
        cout << "1. Push - Them phan tu\n";
        cout << "2. Pop - Xoa phan tu dinh\n";
        cout << "3. Top - Xem phan tu dinh\n";
        cout << "4. Kiem tra Stack rong\n";
        cout << "5. In Stack\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap so nguyen: ";
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
                cout << "Stack rong\n";
            else
                cout << "Stack khong rong\n";
            break;

        case 5:
            s.display();
            break;

        case 0:
            cout << "Ket thuc chuong trinh\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}
 

