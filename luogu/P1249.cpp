#include <bits/stdc++.h>
using namespace std;

vector<int> mul(const vector<int> a, int b) {
    vector<int> ans;
    long long carry = 0;
    for (int i = a.size()-1; i >= 0; i--) {
        long long temp = 1LL * a[i] * b + carry;
        ans.push_back(temp % 10);
        carry = temp / 10;
    }
    while (carry) {
        ans.push_back(carry % 10);
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> res;
    if (n <= 4) {
        res.push_back(n);
    }
    else {
        int num = 2;
        int sum = 0;
        while (sum < n) {
            res.push_back(num);
            sum += num;
            num++;
        }

        int r = sum - n;
        if (r == 1) {
            res.erase(res.begin());
            res.back() += 1;
        }
        else {
            if(r >= 2) res.erase(res.begin()+r-2);
        }
    }
    vector<int> ans = {1};
    for (int i = 0; i < res.size(); i++) {
        ans = mul(ans, res[i]);
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    for (auto num : ans) {
        cout << num;
    }
    return 0;
}
