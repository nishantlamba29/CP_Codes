#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<pair<string, string>> vec(n);
    for(int i=0;i<n;i++) {
        cin >> vec[i].first >> vec[i].second;
    }
    map<string, int> mp;
    int k = 1;
    for(int i=0;i<n;i++) {
        string s = vec[i].first, t = vec[i].second;
        if(mp.find(s) == mp.end()) {
            mp[s] = k++;
        }
        if(mp.find(t) == mp.end()) {
            mp[t] = k++;
        }
    }
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) {
        string s = vec[i].first, t = vec[i].second;
        v[i] = {mp[s], mp[t]};
    }

    vector<vector<int>> dp(1<<n, vector<int>(n+1, -1));
    int mask = 0;

    function<int(int, int)> rec = [&](int mask, int prev) {
        if(mask == (1<<n) - 1) {
            return 0;
        }  
        if(dp[mask][prev+1] != -1) {
            return dp[mask][prev+1];
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(mask & (1<<i)) continue;
            int new_mask = mask | (1<<i);
            if(prev == -1) {
                ans = max(ans, 1 + rec(new_mask, i));
            }
            else {
                if(v[prev].first == v[i].first || v[prev].second == v[i].second) {
                    ans = max(ans, 1 + rec(new_mask, i));
                }
            }
        }
        return dp[mask][prev+1] = ans;
    };

    int ans = rec(mask, -1);
    cout << n - ans << "\n";

}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}