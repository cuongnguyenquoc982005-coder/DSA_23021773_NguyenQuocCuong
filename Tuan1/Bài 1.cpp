#include <iostream>
using namespace std;

int main() {
    int n;
    int a[100];

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int tong = 0;

    for (int i = 0; i < n; i++) {
        tong += a[i];
    }

    cout << "Tong = " << tong << endl;

    return 0;
}
//Ðo phuc tap
Time: O(N)
Nhap N phan t?: O(N)
Tinh tong: O(N)
Tong  là O(N).
Memory: O(N)
Can mang a chua N phan tu // 
