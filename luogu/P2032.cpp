#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[2000005];
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n-k+1; i++) {
        cout << *max_element(a+i, a+i+k) << endl;
    }
    return 0;
}

// 待优化（使用队列）