#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n, m, x, y, mid;
long long s;
int w[MAXN], v[MAXN], l[MAXN], r[MAXN];
long long sw[MAXN], sv[MAXN];
long long sum, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s;
    ans = s;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        y = max(y, w[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
    }
    x = 1, y++;
    while (x < y) {
        memset(sw, 0, sizeof(sw));
        memset(sv, 0, sizeof(sv));
        mid = (x + y) >> 1;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            if (w[i] >= mid) {
                sw[i] = sw[i-1] + 1;
                sv[i] = sv[i-1] + v[i];
            }
            else {
                sw[i] = sw[i-1];
                sv[i] = sv[i-1];
            }
        }
        for (int i = 1; i <= m; i++) {
            sum += (long long)(sw[r[i]] - sw[l[i]-1]) * (sv[r[i]] - sv[l[i]-1]);
        }
        if (sum == s) {
            ans = 0;
            break;
        }
        ans = min(ans, abs(sum - s));
        if (sum <= s) {
            y = mid;
        }
        else {
            x = mid + 1;
        }
    }
    cout << ans;
    return 0;
}