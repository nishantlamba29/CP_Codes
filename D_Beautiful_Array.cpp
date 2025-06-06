#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(3));
    if(v[0] >= 0) {
        dp[0][0] = v[0];
        dp[0][1] = (x > 0 ? x*v[0] : v[0]);
        dp[0][2] = dp[0][1];
    }
    else {
        dp[0][0] = 0;
        dp[0][1] = (x < 0 ? x * v[0] : 0);
        dp[0][2] = dp[0][1];
    }
    
    for(int i=1;i<n;i++) {
        dp[i][0] = max(dp[i-1][0] + v[i], v[i]);
        dp[i][1] = max({dp[i-1][0] + x * v[i], dp[i-1][1] + x * v[i], x * v[i]});
        dp[i][2] = max({dp[i-1][1] + v[i], dp[i-1][2] + v[i], v[i]});
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) ans = max(ans, dp[i][j]);
    }
    cout << ans << "\n";

    return 0;
}