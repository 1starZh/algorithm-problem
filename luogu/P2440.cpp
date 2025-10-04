#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    int low = 1;
    int high = *max_element(l.begin(), l.end()); 
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long sum = 0;
        for (int x : l) {
            sum += x / mid;
        }

        if (sum >= k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
