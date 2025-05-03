#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9 + 7;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    
    vector<char> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> dp(n, vector<int>(n+2));
    vector<int> pre(n+1);
    
    for(int i=1;i<=n;i++) {
        dp[n-1][i] = 1;
        pre[i] = i;
    }
    
    for(int i=n-2;i>=0;i--) {
        for(int j=n;j>=1;j--) {
            if(v[i] == 's') {
                dp[i][j] = pre[j];
            }
            else {
                dp[i][j] = dp[i+1][j+1];
            }
        }

        for(int j=0;j<=n;j++) pre[j] = dp[i][j];
        for(int j=1;j<=n;j++) pre[j] = (pre[j-1] + pre[j]) % mod;
    }

    cout << dp[0][1] << "\n";


    return 0;
}