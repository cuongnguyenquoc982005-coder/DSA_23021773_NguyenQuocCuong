#include <iostream>
using namespace std;

// a) Tinh tong phan tu trong mang 
int tinhTong(int a[][100], int n, int m) {
    int tong = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tong += a[i][j];
        }
    }

    return tong;
}

// b) Xoa dong thu i 
void xoaDong(int a[][100], int &n, int m, int i) {
    // i la so dong bat dau tu 1 
    if (i < 1 || i > n) {
        cout << "Vi tri dong khong hop le" << endl;
        return;
    }

    // Dich cac dong len tren  
    for (int row = i - 1; row < n - 1; row++) {
        for (int col = 0; col < m; col++) {
            a[row][col] = a[row + 1][col];
        }
    }

    n--;
}

// Ham xuat mang 
void xuatMang(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    int a[100][100];

    cout << "Nhap so dong N: ";
    cin >> n;

    cout << "Nhap so cot M: ";
    cin >> m;

    // Nhap mang 
    cout << "Nhap cac phan tu:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // a) Tinh tong 
    cout << "Tong cac phan tu = "
         << tinhTong(a, n, m) << endl;

    // b) Xoa dong 
    int i;
    cout << "Nhap dong can xoa i: ";
    cin >> i;

    xoaDong(a, n, m, i);

    cout << "Mang sau khi xoa dong " << i << ":\n";
    xuatMang(a, n, m);

    return 0;
}
//Do phuc tap 
//a) Tinh tong 
//Time:O(N × M)
//Memory: O(1) 
//b) xoa ding thu i
//Co N - i dong phai dich, moi dong m phan tu 
//Best case:O(M) xoa dong cuoi 
//Average case:O(N × M)
//Worst case:O(N × M) xoa dong dau 
//Memory: O(1)
