
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Queue {
private:
    Node* frontNode; // Dau hang doi
    Node* rearNode;  // Cuoi hang doi

public:
    // Khoi tao Queue rong: O(1)
    Queue() {
        frontNode = NULL;
        rearNode = NULL;
    }

    // Huy Queue, giai phong bo nho: O(n)
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Kiem tra Queue rong: O(1)
    bool isEmpty() {
        return frontNode == NULL;
    }

    // Them phan tu vao cuoi Queue: O(1)
    void enqueue(int x) {
        Node* p = new Node(x);

        if (isEmpty()) {
            frontNode = rearNode = p;
        } else {
            rearNode->next = p;
            rearNode = p;
        }

        cout << "Da them: " << x << endl;
    }

    // Xoa phan tu dau Queue: O(1)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue rong, khong the xoa!" << endl;
            return;
        }

        Node* p = frontNode;
        cout << "Phan tu bi xoa: " << p->data << endl;

        frontNode = frontNode->next;

        // Neu Queue tro thanh rong
        if (frontNode == NULL) {
            rearNode = NULL;
        }

        delete p;
    }

    // Xem phan tu dau Queue: O(1)
    void front() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return;
        }

        cout << "Phan tu dau Queue: "
             << frontNode->data << endl;
    }

    // Xem phan tu cuoi Queue: O(1)
    void rear() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return;
        }

        cout << "Phan tu cuoi Queue: "
             << rearNode->data << endl;
    }

    // In Queue tu dau den cuoi: O(n)
    void display() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return;
        }

        cout << "Queue (dau -> cuoi): ";

        Node* p = frontNode;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, x;

    do {
        cout << "QUEUE BANG LINKED LIST\n" << endl;
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
                cout << "Queue dang rong!" << endl;
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


