#include <bits/stdc++.h>
using namespace std;
#define MAXN 1010
int n, m;
char a[MAXN][MAXN];
int h[MAXN][MAXN], l[MAXN][MAXN], r[MAXN][MAXN];
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'F') {
                h[i][j] = 1;
                l[i][j] = r[i][j] = j;
            } 
            else {
                h[i][j] = 0;
                l[i][j] = r[i][j] = j;
            }
        }
        for (int j = 2; j <= m; j++) {
            if (a[i][j] == 'F' && a[i][j-1] == 'F') {
                l[i][j] = l[i][j-1];
            }
        }
        for (int j = m - 1; j >= 1; j--) {
            if (a[i][j] == 'F' && a[i][j+1] == 'F') {
                r[i][j] = r[i][j+1];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'F' && i > 1) {
                if (a[i-1][j] == 'F') {
                    h[i][j] = h[i-1][j] + 1;
                    l[i][j] = max(l[i][j], l[i-1][j]);
                    r[i][j] = min(r[i][j], r[i-1][j]);
                }
            }
            ans = max(ans, (r[i][j] - l[i][j] + 1) * h[i][j]);
        }
    }
    cout << 3 * ans;
    return 0;
}
