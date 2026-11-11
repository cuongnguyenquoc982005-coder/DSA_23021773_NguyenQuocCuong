
#include <iostream>
using namespace std;

class Heap {
private:
    int a[100];
    int n;

    // Ham vun dong (Heapify)
    void heapify(int i, int size) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Tim nut lon nhat trong 3 nut
        if (left < size && a[left] > a[largest])
            largest = left;

        if (right < size && a[right] > a[largest])
            largest = right;

        // Neu nut cha khong lon nhat thi doi cho
        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(largest, size);
        }
    }

public:
    // Nhap mang
    void input() {
        cout << "Nhap so phan tu: ";
        cin >> n;

        cout << "Nhap cac phan tu:\n";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    // Xuat mang
    void output() {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // Xay dung Max Heap
    void buildHeap() {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i, n);
        }
    }

    // Them mot phan tu vao Heap
    void insert(int x) {
        if (n >= 100) {
            cout << "Heap da day!\n";
            return;
        }

        int i = n;
        a[n++] = x;

        // Day phan tu len neu lon hon nut cha
        while (i > 0 && a[(i - 1) / 2] < a[i]) {
            swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Xoa phan tu lon nhat (goc Heap)
    void deleteRoot() {
        if (n == 0) {
            cout << "Heap rong!\n";
            return;
        }

        a[0] = a[n - 1];
        n--;

        heapify(0, n);
    }

    // Thuat toan Heap Sort
    void heapSort() {
        buildHeap();

        for (int i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);
            heapify(0, i);
        }
    }
};

int main() {
    Heap h;

    h.input();

    cout << "\nMang ban dau: ";
    h.output();

    h.buildHeap();
    cout << "Max Heap: ";
    h.output();

    h.heapSort();
    cout << "Mang sau Heap Sort: ";
    h.output();

    return 0;
}

