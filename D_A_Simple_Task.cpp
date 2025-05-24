#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(n < 3) {
        cout << 0;
        return 0;
    }
    
    vector<vector<int64_t>> dp(1 << n, vector<int64_t>(n));

    for(int mask = (1 << n) - 1; mask > 0; mask--) {
        int cnt = __builtin_popcount(mask);
        int first = 31 - __builtin_clz(mask);
        for(int i=0;i<n;i++) {
            if(!(mask | (1 << i))) continue;
            int64_t ans = 0;
            for(auto &j : adj[i]) {
                if(j > first)  continue;
                else if(j == first && cnt >= 3) ans++;
                else if(!(mask & (1 << j))) ans += dp[mask | (1 << j)][j];
            }
            dp[mask][i] = ans;
        }
    }

    int64_t ans = 0;
    for(int i=0;i<n;i++) ans += dp[1 << i][i];
    cout << ans / 2 ;

    return 0;
}