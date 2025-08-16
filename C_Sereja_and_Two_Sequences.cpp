#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, s, e;
    cin >> n >> m >> s >> e;

    vector<int> a(n+1), b(m+1);
    vector<vector<int>> pos(N);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) {
        cin >> b[i];
        pos[b[i]].push_back(i);
    }
    
    int OP = s / e;
    vector<vector<int>> dp(n+1, vector<int>(OP + 1, m+1));
    
    for(int i=0;i<=n;i++) {
        dp[i][0] = 0;
    }
    
    int ans = 0;

    for(int op=1;op<=OP;op++) {
        int mini = m+1;
        for(int i=1;i<=n;i++) {
            mini = min(mini, dp[i-1][op-1]);
            if(pos[a[i]].size() == 0) continue;
            if(pos[a[i]].back() <= mini) continue;
            int ind = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), mini) - pos[a[i]].begin();
            int j = pos[a[i]][ind];
            if(s - e * op >= i + j) {
                ans = op;
                dp[i][op] = j;
            }
            
        }
    }

    cout << ans << "\n";

    return 0;
}