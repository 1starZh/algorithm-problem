#include <bits/stdc++.h>
using namespace std;

typedef struct {
    string name;
    string zhiwei;
    int bg;
    int level;
} player_;
player_ player[115];
int n;
int bangzhu;
int fbangzhu;
int absi2011;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> player[i].name >> player[i].zhiwei >> player[i].bg >> player[i].level;
        if (player[i].name == "absi2011") absi2011 = i;
        if (player[i].zhiwei == "BangZhu") bangzhu = i;
        if (player[i].zhiwei == "FuBangZhu" && player[i].name != "absi2011") fbangzhu = i;
    }
    

    return 0;
}
