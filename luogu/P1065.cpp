#include <bits/stdc++.h>
using namespace std;

int m, n;
int order[405];
typedef struct {
    int machine_id[25] = {0};
    int time_step[25] = {0};
} product;
product pd[25];
int machine[25][100001];
int last_time[25];
int step[25];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= m*n; i++) {
        cin >> order[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> pd[i].machine_id[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> pd[i].time_step[j];
        }
    }
    for (int i = 1; i <= m*n; i++) {
        int now = order[i];
        step[now]++;
        int mac_now = pd[now].machine_id[step[now]];
        int time_now = pd[now].time_step[step[now]];
        int s = 0;
        for (int j = last_time[now] + 1; ;j++) {
            if (machine[mac_now][j] == 0) {
                s++;
            }
            else {
                s = 0;
            }
            if (s == time_now) {
                for (int k = j - time_now + 1;k <= j; k++) {
                    machine[mac_now][k] = 1;
                }
                if (j > ans) ans = j;
                last_time[now] = j;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
