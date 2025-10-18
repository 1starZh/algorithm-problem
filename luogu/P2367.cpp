#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000005
int n, p, x, y, z;
int a[MAXN], b[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i-1];
    }
    for (int i = 1; i <= p; i++) {
        cin >> x >> y >> z;
        b[x] += z;
        b[y+1] -= z;
    }
    int s_min = 101;
    for (int i = 1; i <= n; i++) {
        b[i] += b[i-1];
        if (b[i] < s_min) s_min = b[i];
    }
    cout << s_min;
    return 0;
}