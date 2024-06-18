#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

bool kiemTraSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

bool kiemTraSoSieuNguyenTo(int num) {
    queue<int> q;
    q.push(num);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (!kiemTraSoNguyenTo(current)) return false;
        if (current > 9) {
            q.push(current / 10);
        }
    }
    return true;
}

void timDaySoSieuNguyenTo(int n) {
    cout << "Các số siêu nguyên tố nhỏ hơn hoặc bằng " << n << " là: ";
    for (int i = 2; i <= n; ++i) {
        if (kiemTraSoSieuNguyenTo(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhập vào số n: ";
    cin >> n;

    timDaySoSieuNguyenTo(n);

    return 0;
}