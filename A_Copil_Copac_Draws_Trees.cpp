#include "bits/stdc++.h"
using namespace std;

const int N = 2e5;
vector<pair<int,int>> adj[N+1];
int val[N+1], dp[N+1];

void dfs(int u = 1, int p = -1){
    for(auto &[v, idx] : adj[u]){
        if(v == p) continue;
        val[v] = idx;
        dp[v] = dp[u] + (idx < val[u]);
        dfs(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<=n;i++) {
            adj[i].clear();
            dp[i] = 0;
            val[i] = 0;
        }
        dp[1] = 1;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        dfs();
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans, dp[i]);
        }
        cout<<ans<<"\n";
    }
    
}