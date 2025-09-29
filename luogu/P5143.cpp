#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x;
    int y;
    int z;
} p;
p point[50005];

double ans;

bool cmp(p a, p b) {
    return a.z < b.z;
}

double distance(p a, p b) {
    long long sum = 0;
    sum += pow((a.x-b.x), 2) + pow((a.y-b.y), 2) + pow((a.z-b.z), 2);
    return (double)sqrt(sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <=n; i++) {
        cin >> point[i].x >> point[i].y >> point[i].z;
    }
    sort(point+1, point+n+1, cmp);
    for (int i = 1; i < n; i++) {
        ans += distance(point[i], point[i+1]);
    }
    cout << fixed << setprecision(3) << ans;
    return 0;
}
