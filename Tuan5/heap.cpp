
#include <iostream>
using namespace std;

struct Heap {
    int a[100];
    int n;

    // Khoi tao Heap
    void init() {
        n = 0;
    }

    // Ham vun dong Max Heap
    void heapify(int i, int size) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && a[left] > a[largest])
            largest = left;

        if (right < size && a[right] > a[largest])
            largest = right;

        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(largest, size);
        }
    }

    // Nhap Heap
    void input() {
        cout << "Nhap so phan tu: ";
        cin >> n;

        if (n < 0 || n > 100) {
            cout << "So phan tu khong hop le!\n";
            n = 0;
            return;
        }

        cout << "Nhap cac phan tu:\n";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        buildHeap();
    }

    // Xay dung Max Heap
    void buildHeap() {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i, n);
        }
    }

    // Xuat Heap
    void output() {
        if (n == 0) {
            cout << "Heap rong!\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // Them phan tu
    void insert(int x) {
        if (n == 100) {
            cout << "Heap da day!\n";
            return;
        }

        int i = n;
        a[n++] = x;

        while (i > 0 && a[(i - 1) / 2] < a[i]) {
            swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }

        cout << "Da them " << x << " vao Heap!\n";
    }

    // Xoa nut goc
    void deleteRoot() {
        if (n == 0) {
            cout << "Heap rong!\n";
            return;
        }

        cout << "Da xoa: " << a[0] << endl;

        a[0] = a[n - 1];
        n--;

        if (n > 0)
            heapify(0, n);
    }

    // Heap Sort
    void heapSort() {
        buildHeap();

        int size = n;

        for (int i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);
            heapify(0, i);
        }

        cout << "Mang sau Heap Sort: ";
        output();

        n = size;
        buildHeap();
    }
};

int main() {
    Heap h;
    h.init();

    int choice, x;

    do {
        cout << "\nMENU HEAP\n";
        cout << "1. Nhap Heap\n";
        cout << "2. Xuat Heap\n";
        cout << "3. Them phan tu\n";
        cout << "4. Xoa phan tu lon nhat\n";
        cout << "5. Heap Sort\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            h.input();
            break;

        case 2:
            h.output();
            break;

        case 3:
            cout << "Nhap phan tu can them: ";
            cin >> x;
            h.insert(x);
            break;

        case 4:
            h.deleteRoot();
            break;

        case 5:
            h.heapSort();
            break;

        case 0:
            cout << "Thoat chuong trinh\n";
            break;

        default:
            cout << "Lua chon khong hop le\n";
        }

    } while (choice != 0);

    return 0;
}

