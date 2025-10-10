#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[1000005];
int num;
int sum[2005];
int ans = 1000005;
int ansl, ansr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1;
    while (l <= r && r <= n + 1) {
        if (num < m) {
            r++;
            sum[a[r - 1]]++;
            if (sum[a[r - 1]] == 1) num++;
        }
        else {
            if (ans > r - l) {
                ans = r - l;
                ansl = l;
                ansr = r - 1;
            }
            sum[a[l]]--;
            if (sum[a[l]] == 0) num--;
            l++;
        }
    }
    cout << ansl << " " << ansr << endl;
    return 0;
}