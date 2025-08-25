#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for(int i=1;i<=n;i++) cin >> h[i];

    vector<pair<int, int>> dp(n + 2);
    
    dp[n].first = h[n];
    dp[n].second = h[n] - 1;
    for(int i=n - 1;i > 0; i--) {
        dp[i].first = min(h[i] + dp[i+1].second, h[i] + max(0LL, h[i+1] - i) + dp[i+2].second);
        dp[i].second = min(dp[i].first, h[i] - 1 + dp[i+1].second);
    }

    cout << dp[1].first << "\n";

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