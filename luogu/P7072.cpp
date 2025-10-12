#include <bits/stdc++.h>
using namespace std;

int n, w, x;
int t[610];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        t[x]++;
        int sum = 0;
        for (int j = 600; j >= 0; j--) {
            sum += t[j];
            if (sum >= max(1, i*w / 100)) {
                cout << j << " ";
                break;
            }
        }
    }

    return 0;
}
