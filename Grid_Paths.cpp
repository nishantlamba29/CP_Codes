#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if(v[0][0] != '*') dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j] == '*') continue;
            if(i>0 && v[i-1][j] != '*') dp[i][j] += dp[i-1][j];
            if(j>0 && v[i][j-1] != '*') dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    cout<<dp[n-1][n-1];
}