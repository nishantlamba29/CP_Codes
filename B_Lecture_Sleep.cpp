#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    vector<int> v(n), t(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> t[i];
    
    vector<int> pre = v;
    for(int i=1;i<n;i++) pre[i] += pre[i-1];

    vector<vector<int>> dp(n, vector<int> (3));

    if(t[0]) dp[0][0] = v[0];
    dp[0][1] = dp[0][2] = v[0];

    for(int i=1;i<n;i++) {
        dp[i][0] = dp[i-1][0] + (t[i] ? v[i] : 0);

        if(i-k >= 0) dp[i][1] = pre[i] - pre[i-k] + dp[i-k][0];
        else dp[i][1] = pre[i];

        dp[i][2] = max(dp[i-1][2], dp[i-1][1]) + (t[i] ? v[i] : 0);
    }

    cout << max(dp[n-1][1], dp[n-1][2]) << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();


    return 0;
}