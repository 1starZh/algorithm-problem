#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
ll s_, b_;
ll ans = INT_MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<ll> s(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        s_ = 1;
        b_ = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                s_ *= s[i];
                b_ += b[i];
            }
        }
        ans = min(ans, abs(s_-b_));
    }
    cout << ans << '\n';
    return 0;
}