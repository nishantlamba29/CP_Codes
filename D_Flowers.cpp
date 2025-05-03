#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9 + 7;

const int N = 1e5;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, k;
    cin >> t >> k;

    vector<vector<int>> dp(N+1, vector<int>(2));
    // dp[0][0] = 1;
    dp[k][1] = 1;
    for(int i=1;i<=k;i++) dp[i][0] = 1;
    for(int i=k+1;i<=N;i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-k][0] + dp[i-k][1]) % mod;
    }
    vector<int> pre(N+1);
    for(int i=1;i<=N;i++) {
        pre[i] = (pre[i-1] + dp[i][0] + dp[i][1]) % mod;
    }
    // cout << "\n";
    while(t--) {
        int a, b;
        cin >> a >> b;

        // cout << dp[b+1][0] + dp[b+1][1] - dp[a-1][0] - dp[a-1][1] << "\n";
        // cout << t << "\n";
        cout << (pre[b] - pre[a-1] + mod ) % mod << "\n";

    }


    return 0;
}