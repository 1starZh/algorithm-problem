#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<pair<ll,int>> items; // (value, freq)

bool check(int L){
    priority_queue<int, vector<int>, greater<int>> heap; // min-heap of current active group lengths
    ll prev = (ll)4e18; // sentinel
    for(auto &p : items){
        ll val = p.first;
        int f = p.second;
        if(prev == (ll)4e18 || val != prev + 1){
            // gap: all active sequences end, must be >= L
            while(!heap.empty()){
                int len = heap.top(); heap.pop();
                if(len < L) return false;
            }
            // start f new sequences of length 1
            for(int i = 0; i < f; ++i) heap.push(1);
        }else{
            int active = (int)heap.size();
            int extend = min(active, f);
            int to_end = active - extend;
            // Those to_end smallest lengths end here; check they >= L
            for(int i = 0; i < to_end; ++i){
                int len = heap.top(); heap.pop();
                if(len < L) return false;
            }
            // extend 'extend' sequences: pop extend shortest, increment, push back
            vector<int> tmp;
            for(int i = 0; i < extend; ++i){
                int len = heap.top(); heap.pop();
                tmp.push_back(len + 1);
            }
            for(int x : tmp) heap.push(x);
            // remaining (f - extend) start new sequences length 1
            for(int i = 0; i < f - extend; ++i) heap.push(1);
        }
        prev = val;
    }
    // all remaining sequences end, must be >= L
    while(!heap.empty()){
        int len = heap.top(); heap.pop();
        if(len < L) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    // build frequency list
    items.clear();
    for(int i = 0; i < n; ){
        int j = i;
        while(j < n && a[j] == a[i]) ++j;
        items.emplace_back(a[i], j - i);
        i = j;
    }

    int lo = 1, hi = n, ans = 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }else hi = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}
