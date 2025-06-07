#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007LL; 

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        v[i]--;
    }

    vector<vector<int>> dp(n+1, vector<int>(2));
    
    dp[0][0] = 1;// dp[1][1] odd to 1 again so dp[0][0] = 1
    for(int i=1;i<n;i++) {
        dp[i][1] = (1 + dp[i-1][0]) % mod; // i pe i-1 se aya and i-1 even hi hoga
        // as moving forward all rooms will be having even crosses
        dp[i][0] = (dp[i][1] + 2 + dp[i-1][0] - dp[v[i]][1] + mod) % mod; // phle ane k ways dp[i][1] + 
        // 1 (i to v[i]) + ab v[i] to dp[i-1][0] pe jaunga + 1 (i-1 to i)
    }
    cout << (dp[n-1][0] + 1) % mod;

    return 0;
}