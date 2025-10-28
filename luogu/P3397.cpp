#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1010][1010];
int x_1, y_1, x_2, y_2;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        a[x_1][y_1]++;
        a[x_1][y_2+1]--;
        a[x_2+1][y_1]--;
        a[x_2+1][y_2+1]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}