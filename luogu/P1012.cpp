#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

int n;

bool cmp(Int a, Int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    return sa + sb > sb + sa;
}

int main() {
    cin >> n;
    vector<Int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    return 0;
}