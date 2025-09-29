#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
    if (a.size() < b.size()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string res;
    int carry = 0;
    for (size_t i = 0; i < a.size(); i++) {
        int x = a[i] - '0';
        int y = (i < b.size() ? b[i] - '0' : 0);
        int sum = x + y + carry;
        res.push_back(char(sum % 10 + '0'));
        carry = sum / 10;
    }
    if (carry) res.push_back(char(carry + '0'));
    reverse(res.begin(), res.end());
    return res;
}

string mulBigLow(string a, int b) {
    if (b == 0) return "0";

    reverse(a.begin(), a.end());
    string res;
    long long carry = 0;
    for (size_t i = 0; i < a.size(); i++) {
        long long cur = 1LL * (a[i] - '0') * b + carry;
        res.push_back(char(cur % 10 + '0'));
        carry = cur / 10;
    }
    while (carry) {
        res.push_back(char(carry % 10 + '0'));
        carry /= 10;
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

string mulBigBig(string a, string b) {
    int n = a.size(), m = b.size();
    vector<int> A(n), B(m), C(n+m, 0);

    for (int i = 0; i < n; i++) A[i] = a[n-1-i] - '0';
    for (int i = 0; i < m; i++) B[i] = b[m-1-i] - '0';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i+j] += A[i] * B[j];
        }
    }

    for (int i = 0; i < n+m; i++) {
        if (C[i] >= 10) {
            C[i+1] += C[i] / 10;
            C[i] %= 10;
        }
    }

    int len = n+m;
    while (len > 1 && C[len-1] == 0) len--;

    string res;
    for (int i = len-1; i >= 0; i--) res.push_back(C[i] + '0');
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}
