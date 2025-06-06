#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = (int)1e17;

inline void n_lamba_29() {
    int m, x;
    cin >> m >> x;
    vector<int> c(m), h(m);
    int sum = 0;
    for(int i=0;i<m;i++) {
        cin >> c[i] >> h[i];
        sum += h[i];
    }

    vector<vector<int>> dp(m, vector<int>(sum + 1, -1));

    function<int(int, int)> rec = [&](int ind, int happ) {
        if(happ == 0) return 0LL;
        if(ind < 0) return inf;
        if(dp[ind][happ] != -1) return dp[ind][happ];
        int ff = rec(ind - 1, happ);
        int ss = inf;
        if(happ - h[ind] >= 0) {
            ss = rec(ind - 1, happ - h[ind]) + c[ind];
            if(ss > ind * x) ss = inf;
        }
        return dp[ind][happ] = min(ff, ss);
    };

    int ans = -1;
    for(int i = sum; i >= 0; i--) {
        if(rec(m-1, i) <= x * (m-1)) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
 
}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}