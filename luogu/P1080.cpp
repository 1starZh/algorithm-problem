#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
const int BASE = 1000000000;

void trim(vi &a){
    while(a.size() > 1 && a.back() == 0) a.pop_back();
}

vi multi(const vi &a, int b){
    if (b == 0) return vi{0};
    if (a.size() == 1 && a[0] == 0) return vi{0};
    long long carry = 0;
    vi res;
    res.resize(a.size());
    for(size_t i = 0; i < a.size(); ++i){
        long long cur = (long long)a[i] * (long long)b + carry;
        res[i] = (int)(cur % BASE);
        carry = cur / BASE;
    }
    while(carry){
        res.push_back((int)(carry % BASE));
        carry /= BASE;
    }
    trim(res);
    return res;
}

vi div(const vi &a, int b){
    assert(b > 0);
    if (a.size() == 1 && a[0] == 0) { b = 0; return vi{0}; }

    vi q(a.size(), 0);
    long long rem = 0;
    for(int i = (int)a.size() - 1; i >= 0; --i){
        __int128 cur = (__int128)rem * BASE + a[i];
        long long qi = (long long)(cur / b);
        rem = (long long)(cur % b);
        q[i] = (int)qi;
    }
    trim(q);
    return q;
}

bool cmp(const pii& a, const pii& b) {
    return (ll)a.first * (ll)a.second < (ll)b.first * (ll)b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    pii gw;
    cin >> gw.first >> gw.second;

    vector<pii> dc(n);
    for (int i = 0; i < n; i++) {
        cin >> dc[i].first >> dc[i].second;
    }

    sort(dc.begin(), dc.end(), cmp);

    vi ans = multi(vi{1}, gw.first);

    for (int i = 0; i < n-1; i++) {
        ans = multi(ans, dc[i].first);
    }

    if (dc.back().second == 0) {
        cerr << "Division by zero error\n";
        return 0;
    }
    ans = div(ans, dc.back().second);

    trim(ans);
    int m = (int)ans.size();
    if (m == 0) { cout << 0 << "\n"; return 0; }

    cout << ans[m-1];
    for (int i = m-2; i >= 0; --i) {
        string part = to_string(ans[i]);
        cout << string(9 - (int)part.length(), '0') << part;
    }
    cout << '\n';

    return 0;
}
