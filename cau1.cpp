#include <iostream>
#include <cmath>
using namespace std;

int tinhTongUoc(int n) {
    int tong = 0;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            tong += i;
            if (i != n / i) {
                tong += n / i;
            }
        }
    }
    return tong;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << tinhTongUoc(n) << endl;
    }
    return 0;
}