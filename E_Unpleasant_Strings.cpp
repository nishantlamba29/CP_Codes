#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> next(n+2, vector<int> (k, n));
    for(int i=n-1;i>=0;i--) {
        next[i] = next[i+1];
        next[i][s[i] - 'a'] = i;
    }
    
    vector<int> dp(n+1, (int)1e9);
    dp[n] = 0;
    
    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<k;j++) {
            if(next[i+1][j] == n) dp[i] = min(dp[i], 1LL);
            else {
                dp[i] = min(dp[i], dp[next[i+1][j]] + 1);
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        string t;
        cin >> t;
        int p = -1;
        for(auto ch : t) {
            p = next[p+1][ch - 'a'];
        }
        cout << dp[p] << "\n";
    }

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();

    return 0;
}