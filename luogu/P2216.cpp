#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int a, b, n;
int mat[MAXN][MAXN], row_max[MAXN][MAXN], row_min[MAXN][MAXN], square_max[MAXN][MAXN], square_min[MAXN][MAXN];
int ans = INFINITY;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> n;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= a; i++) {
        deque<int> max, min;
        for (int j = 1; j <= b; j++) {
            while (!max.empty() && max.front() + n <= j) max.pop_front();
            while (!max.empty() && mat[i][max.back()] < mat[i][j]) max.pop_back();
            max.push_back(j);
            if (j >= n) {
                row_max[i][j-n+1] = mat[i][max.front()];
            }

            while (!min.empty() && min.front() + n <= j) min.pop_front();
            while (!min.empty() && mat[i][min.back()] > mat[i][j]) min.pop_back();
            min.push_back(j);
            if (j >= n) {
                row_min[i][j-n+1] = mat[i][min.front()];
            }
        }
    }

    for (int i = 1; i <= b-n+1; i++) {
        deque<int> max, min;
        for (int j = 1; j <= a; j++) {
            while (!max.empty() && max.front() + n <= j) max.pop_front();
            while (!max.empty() && row_max[max.back()][i] < row_max[j][i]) max.pop_back();
            max.push_back(j);
            if (j >= n) {
                square_max[j-n+1][i] = row_max[max.front()][i];
            }

            while (!min.empty() && min.front() + n <= j) min.pop_front();
            while (!min.empty() && row_min[min.back()][i] > row_min[j][i]) min.pop_back();
            min.push_back(j);
            if (j >= n) {
                square_min[j-n+1][i] = row_min[min.front()][i];
            }
        }
    }

    for (int i = 1; i <= a-n+1; i++) {
        for (int j = 1; j <= b-n+1; j++) {
            ans = min(ans, square_max[i][j] - square_min[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}
