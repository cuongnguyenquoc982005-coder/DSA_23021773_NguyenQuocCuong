
#include <iostream>
using namespace std;

// Ham phan hoach
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

// Ham Quick Sort
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        // Sap xep ben trai Pivot
        quickSort(a, low, pi - 1);

        // Sap xep ben phai Pivot
        quickSort(a, pi + 1, high);
    }
}

int main() {
    int n, a[100];

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

