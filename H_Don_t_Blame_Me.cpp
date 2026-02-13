#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

#define int long long
const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> dp(n + 1, vector<int>(64));

    for(int i=n-1;i>=0;i--) {
        (dp[i][v[i]] += 1) %= mod;
        for(int j=0;j<64;j++) {
            (dp[i][j] += dp[i+1][j]) %= mod;
            (dp[i][j & v[i]] += dp[i+1][j]) %= mod;
        }

    }

    int ans = 0;
    for(int i=0;i<64;i++) {
        if(__builtin_popcount(i) == k) {
            (ans += dp[0][i]) %= mod;
        }
    }

    cout << ans << "\n";


}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        solve();
    }

    return 0;
}