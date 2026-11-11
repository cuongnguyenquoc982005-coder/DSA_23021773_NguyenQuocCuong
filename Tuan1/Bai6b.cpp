#include <iostream>
using namespace std;
void chenPhanTu(int a[], int &n, int y, int m) {
    // m là v? trí b?t d?u t? 1
    if (m < 1 || m > n + 1) {
        cout << "Vi tri m khong hop le" << endl;
        return;
    }

    for (int i = n; i >= m; i--) {
        a[i] = a[i - 1];
    }

    a[m - 1] = y;
    n++;
}

int main() {
    int n;
    int a[100];

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int y, m;

    cout << "Nhap gia tri y: ";
    cin >> y;

    cout << "Nhap vi tri m: ";
    cin >> m;

    chenPhanTu(a, n, y, m);

    cout << "Day sau khi chen: ";

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
