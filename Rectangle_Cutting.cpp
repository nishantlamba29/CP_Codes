#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(int v=1;v<i;v++){
                dp[i][j] = min(dp[i][j], 1 + dp[v][j] + dp[i-v][j]);
            }
            for(int h=1;h<j;h++){
                dp[i][j] = min(dp[i][j], 1 + dp[i][h] + dp[i][j-h]);
            }
        }
    }
    cout<<dp[n][m];
}