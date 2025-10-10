#include <bits/stdc++.h>

using namespace std;
int n, c;
int a[200005];

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int l = 0, r = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        while (a[l] < a[i] - c && l < n) l++;
        while (a[r] <= a[i] - c && r < n) r++;
        if (a[i] - a[l] == c) {
            sum += r - l;
        }
    }
    cout << sum;
    return 0;
}