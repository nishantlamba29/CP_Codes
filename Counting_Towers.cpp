#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> dp(1e6+1, vector<int>(2));
    dp[1][1] = 1, dp[1][0] = 1;

    for(int i=2;i<=1e6;i++){
        dp[i][1] = (2LL*dp[i-1][1] + dp[i-1][0]) % mod;
        dp[i][0] = (4LL*dp[i-1][0] + dp[i-1][1]) % mod;
    }
    
    int __;
    cin>>__;
    for(int _=0;_<__;++_) {
        int n;
        cin>>n;
        int ans = (dp[n][0] + dp[n][1]) % mod;
        cout<<ans<<"\n";
    }
    
}