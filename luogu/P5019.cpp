#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void sol(vector<int>& s, int l, int r) {
    if (l >= r) return;
    int min_ = *min_element(s.begin()+l, s.begin()+r);
    int index;
    for (int i = l; i < r; i++) {
        if (s[i] == min_) index = i;
    }
    for (int i = l; i < r; i++) {
        s[i] -= min_;
    }
    ans += min_;
    int i = l;
    while (i < r) {
        while (i < r && s[i] == 0) ++i;
        int j = i;
        while (j < r && s[j] != 0) ++j;
        sol(s, i, j);
        i = j;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sol(v, 0, n);
    cout << ans << endl;
    return 0;
}