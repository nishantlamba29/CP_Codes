#include "bits/stdc++.h"
using namespace std;
#define int long long

const int N = 2e5;
int n, dp[N+1][2], ans;
vector<int> tree[N+1];

void dfs(int node = 1, int p = -1){
    int m1 = -1, m2 = -1, sz = tree[node].size();
    for(auto &j : tree[node]){
        if(j == p) continue;
        dfs(j, node);
        if(dp[j][0] >= m1){
            m2 = m1;
            m1 = dp[j][0];
        }
        else if(dp[j][0] > m2){
            m2 = dp[j][0];
        }
        dp[node][0] = max(sz - 1 + dp[j][0] - 1, dp[node][0]);
    }
    dp[node][0] = max(sz, dp[node][0]);
    dp[node][1] = max(sz - 2 + m1 - 1 + m2 - 1, dp[node][1]);
    ans = max({ans, dp[node][0], dp[node][1]});
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<=n;i++) {
            tree[i].clear();
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        for(int i=0;i<n-1;i++){
            int u, v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        ans = 0;
        dfs();
        cout<<ans<<"\n";
    }

    return 0;
}