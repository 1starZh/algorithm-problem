#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100010];
int l[100010], r[100010];
long long s[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i-1] + a[i];
    }
    for (int i = 1; i <= m; i++) {
        cout << s[r[i]] - s[l[i]-1] << endl;
    }
    return 0;
}