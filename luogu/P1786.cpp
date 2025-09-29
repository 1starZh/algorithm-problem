#include <bits/stdc++.h>
using namespace std;

typedef struct {
    string name;
    string zhiwei;
    long long bg;
    int level;
    int cin_sort;
} player_;
player_ player[115];

int n;
int bangzhu;
int fbangzhu;
int absi2011;

bool cmp1(player_ a, player_ b) {
    if (a.bg == b.bg) return a.cin_sort < b.cin_sort;
    else return a.bg > b.bg;
}

int s2int(string a){
	if (a=="BangZhu") return 0;
	if (a=="FuBangZhu") return 1;
	if (a=="HuFa") return 2;
	if (a=="ZhangLao") return 3;
	if (a=="TangZhu") return 4;
	if (a=="JingYing") return 5;
	if (a=="BangZhong") return 6;
}

bool cmp2(player_ a, player_ b) {
    if (s2int(a.zhiwei) < s2int(b.zhiwei)) return true;
    if (s2int(a.zhiwei) > s2int(b.zhiwei)) return false;
    if (s2int(a.zhiwei) == s2int(b.zhiwei)) {
        if (a.level == b.level) {
            return a.cin_sort < b.cin_sort;
        }
        else return a.level > b.level;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> player[i].name >> player[i].zhiwei >> player[i].bg >> player[i].level;
        player[i].cin_sort = i;
        if (player[i].name == "absi2011") absi2011 = i;
        if (player[i].zhiwei == "BangZhu") bangzhu = i;
        if (player[i].zhiwei == "FuBangZhu" && player[i].name != "absi2011") fbangzhu = i;
    }

    swap(player[1], player[bangzhu]);
    swap(player[2], player[absi2011]);
    swap(player[3], player[fbangzhu]);
    sort(player+2, player+3, cmp1);
    sort(player+4, player+n+1, cmp1);

    for (int i = 4; i <= n; i++) {
        if (i == 4 || i == 5) player[i].zhiwei = "HuFa";
        else if (i >= 6 && i <= 9) player[i].zhiwei = "ZhangLao";
        else if (i >= 10 && i <= 16) player[i].zhiwei = "TangZhu";
        else if (i >= 17 && i <= 41) player[i].zhiwei = "JingYing";
        else player[i].zhiwei = "BangZhong";
    }

    sort(player+1, player+n+1, cmp2);
    for (int i = 1; i <= n; i++) {
        cout << player[i].name << " "<< player[i].zhiwei << " " << player[i].level << endl;
    }

    return 0;
}
