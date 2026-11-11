#include <iostream>
using namespace std;

int main() {
    int n;
    double a[100];

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double tong = 0;

    for (int i = 0; i < n; i++) {
        tong += a[i];
    }

    double trungBinh = tong / n;

    cout << "Gia tri trung binh = " << trungBinh << endl;

    cout << "Cac gia tri >= trung binh: ";

    for (int i = 0; i < n; i++) {
        if (a[i] >= trungBinh) {
            cout << a[i] << " ";
        }
    }

    return 0;
}
