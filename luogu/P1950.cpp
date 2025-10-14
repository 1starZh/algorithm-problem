#include <bits/stdc++.h>
using namespace std;
#define MAXN 1010

int n, m, top;
char ch[MAXN][MAXN];
int h[MAXN], l[MAXN], r[MAXN], st[MAXN];
long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ch[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            h[j] = ch[i][j] == '*' ? 0 : h[j]+1;
        }
        top = 0;
        for (int j = 1; j <= m; j++) {
            while (top > 0 && h[j] < h[st[top]]) {
                r[st[top]] = j;
                top--;
            }
            top++;
            st[top] = j;
        }
        while (top > 0) {
            r[st[top]] = m+1;
            top--;
        }
        top = 0;
        for (int j = m; j >= 1; j--) {
            while (top > 0 && h[j] <= h[st[top]]) {
                l[st[top]] = j;
                top--;
            }
            top++;
            st[top] = j;
        }
        while (top > 0) {
            l[st[top]] = 0;
            top--;
        }
        for (int j = 1; j <= m; j++) {
            ans += (j - l[j]) * (r[j] - j) * h[j];
        }
    }
    cout << ans;
    return 0;
}