#include <iostream>
#include <stack>
#include <string>
using namespace std;

string encodeString(const string& s) {
    stack<char> stackChar;
    stack<int> stackCount;
    string result = "";

    for (char ch : s) {
        if (!stackChar.empty() && stackChar.top() == ch) {
            stackCount.top()++;
        } else {
            if (!stackChar.empty()) {
                result += stackChar.top();
                result += to_string(stackCount.top());
            }
            stackChar.push(ch);
            stackCount.push(1);
        }
    }

    if (!stackChar.empty()) {
        result += stackChar.top();
        result += to_string(stackCount.top());
    }

    return result;
}

int main() {
    string s;
    cout << "Nhập vào sâu cần mã hoá: ";
    cin >> s;

    string encoded = encodeString(s);
    cout << "Kết quả mã hoá của sâu là: " << encoded << endl;

    return 0;
}