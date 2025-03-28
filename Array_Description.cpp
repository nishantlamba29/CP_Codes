#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>> dp(n+1, vector<int>(m+2, 0));
    if(v[0] == 0){
        for(int j=1;j<=m;j++) dp[1][j] = 1;
    }
    else dp[1][v[0]] = 1;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i-1] != 0 && v[i-1] != j) continue;
            if(j-1 > 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if(j+1 <= m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
        }
    }
    int ans = 0;
    for(int j=1;j<=m;j++) ans = (ans + dp[n][j]) % mod;
    cout<<ans;
    // khud se
}