#include <iostream>
using namespace std;
void xoaPhanTu(int a[], int &n, int k) {
    // k là vi tri bat dau
    if (k < 1 || k > n) {
        cout << "Vi tri k khong hop le" << endl;
        return;
    }

    for (int i = k - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--;
}

int main() {
    int n;
    int a[100];

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cout << "Nhap vi tri can xoa k: ";
    cin >> k;

    xoaPhanTu(a, n, k);

    cout << "Day sau khi xoa: ";

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
//Do phuc tap
//Best case: O(1) — xoa phan tu cuoi.
//Average case: O(N)
//Worst case: O(N) — xoa phan tu dau.
//Memory: O(1)//
