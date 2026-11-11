#include <iostream>
using namespace std;

int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void rutGon(int &a, int &b) {
    int ucln = UCLN(a, b);

    a = a / ucln;
    b = b / ucln;
}

int main() {
    int a, b;

    cout << "Nhap tu so a: ";
    cin >> a;

    cout << "Nhap mau so b: ";
    cin >> b;

    if (b == 0) {
        cout << "Mau so phai khac 0!";
        return 0;
    }

    rutGon(a, b);

    cout << "Phan so sau khi rut gon: "
         << a << "/" << b << endl;

    return 0;
}
