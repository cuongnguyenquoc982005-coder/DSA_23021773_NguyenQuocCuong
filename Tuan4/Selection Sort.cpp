
#include <iostream>
using namespace std;
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        // Tim vi tri phan tu nho nhat
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        // Doi cho
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main() {
    int n;
    int a[100];

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    selectionSort(a, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

