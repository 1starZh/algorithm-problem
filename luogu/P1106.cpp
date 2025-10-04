#include <bits/stdc++.h>

using namespace std;

string s;
int k;
void del(string& s) {
    int j = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i+1] >= s[i]) {
            j = i + 1;
        }
        else {
            j = i;
            break;
        }
    }
    s.erase(j, 1);
}

void re0(string& s) {
    while (s.size() > 0 && s[0] == '0') {
        s.erase(0, 1);
    }
}

int main() {
    cin >> s;
    cin >> k;
    for (int i = 0; i < k; i++) {
        del(s);
    }
    re0(s);
    if (s.empty()) {
        cout << '0';
    }
    else {
        cout << s;
    }
    return 0;
}