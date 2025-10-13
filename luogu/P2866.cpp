#include <bits/stdc++.h>
using namespace std;
#define MAXN 8005
int n;
int h;
long long ans;
stack<int> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h;
        while (!s.empty() && h >= s.top()) {
            s.pop();
        }
        ans += s.size();
        s.push(h);
    }
    cout << ans;
    return 0;
}
