
#include <iostream>
using namespace std;

// Tron hai nua mang da sap xep
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[100], R[100];

    // Sao chep du lieu vao hai mang tam
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    // So sanh va tron
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chep cac phan tu con lai
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

// Ham Merge Sort
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Chia nua trai
        mergeSort(a, l, m);

        // Chia nua phai
        mergeSort(a, m + 1, r);

        // Tron hai nua
        merge(a, l, m, r);
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

    mergeSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

