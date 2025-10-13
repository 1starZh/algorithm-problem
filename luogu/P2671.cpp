#include <bits/stdc++.h>
using namespace std;

const int mod = 10007;
const int maxn = 1e5 + 5;
int n, m;
int a[maxn], b[maxn];
int sa[maxn][2];
int sb[maxn][2];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sa[b[i]][i%2]++;
        sb[b[i]][i%2] = (sb[b[i]][i%2] + a[i]) % mod;
    }
    for (int i = 1; i <= n; i++) {
        int y = b[i];
        ans += i * (sb[y][i%2] + a[i] * (sa[y][i%2] - 2) % mod) % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}
