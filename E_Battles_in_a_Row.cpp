#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, h, m;
    cin >> n >> h >> m;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    // index i tak
    // j magic used
    // dp[i][j] = max health left 
    dp[0][0] = h;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<=m;j++) {
            if(dp[i][j] < 0) continue;
            if(dp[i][j] - a[i] >= 0) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] - a[i]);
            }
            int m2 = j + b[i];
            if(m2 <= m) {
                dp[i+1][m2] = max(dp[i+1][m2], dp[i][j]);
            }
        }
    }

    for(int i = n; i >= 0; --i) {
        for(int j = 0; j <= m; ++j) {
            if (dp[i][j] >= 0) {
                cout << i << "\n";
                return 0;
            }
        }
    }


    return 0;
}