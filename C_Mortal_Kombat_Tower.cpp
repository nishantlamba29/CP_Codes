#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> dp(n+1, vector<int>(2, (int)1e9));
    dp[n][0] = 0, dp[n][1] = 0;

    for(int i=n-1;i>=0;i--) {
        dp[i][0] = min(dp[i][0], v[i] + dp[i+1][1]);
        if(i+1 < n) 
            dp[i][0] = min(dp[i][0], v[i] + v[i+1] + dp[i+2][1]);

        dp[i][1] = min(dp[i][1], dp[i+1][0]);
        if(i+1 < n) 
            dp[i][1] = min(dp[i][1], dp[i+2][0]);
    }

    cout << dp[0][0] << "\n";

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