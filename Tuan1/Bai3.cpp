#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Nhap n: ";
    cin >> n;

    long long gt = 1;

    for (int i = 1; i <= n; i++) {
        gt *= i;
    }

    cout << n << "! = " << gt << endl;

    return 0;
}

