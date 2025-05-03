#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> dp(n+1, vector<int>(h+1));
    
    for(int i=n-1;i>=0;i--) {
        for(int j=h-1;j>=0;j--) {
            int op1 = (j + v[i]) % h;
            int op2 = (j + v[i] - 1) % h;
            dp[i][j] = max(dp[i+1][op1] + (op1 >= l && op1 <= r), dp[i+1][op2] + (op2 >= l && op2 <= r));
        }
    }
    cout << dp[0][0] << "\n";


    return 0;
}