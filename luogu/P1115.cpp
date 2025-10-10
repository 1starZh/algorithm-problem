#include <bits/stdc++.h>

using namespace std;
int n, a, f;
int ans = -INFINITY;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        f = max(f+a, a);
        ans = max(f, ans);
    }
    cout << ans << endl;
    return 0;
}