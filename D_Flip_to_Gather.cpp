#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = (s[0] == '1');
    dp[0][1] = (s[0] == '0');
    dp[0][2] = (s[0] == '1');
    for(int i=1;i<n;i++) {
        dp[i][0] = dp[i-1][0] + (s[i] == '1');
        dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + (s[i] == '0');
        dp[i][2] = min(dp[i-1][2], dp[i-1][1]) + (s[i] == '1');
    }
    int ans = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}