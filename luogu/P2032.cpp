#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[2000005];
deque<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        while(!q.empty() && q.front() + k <= i) {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] < a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k) {
            cout << a[q.front()] << endl;
        }
    }
    return 0;
}
