#include <bits/stdc++.h>
using namespace std;
#define int long long

int dfs(int node, vector<int> adj[], vector<int> &dp, vector<int> &val){
    if(dp[node] != -1) return dp[node];
    int ans = val[node];
    for(auto &j : adj[node]){
        ans += dfs(j, adj, dp, val);
    }
    return dp[node] = ans;
}

int dfs2(int node, vector<int> adj[], vector<int> &val, vector<int>& vis){
    vis[node] = 1;
    int ans = val[node];
    for(auto &j : adj[node]){
        if(!vis[j]) 
            ans += dfs2(j, adj, val, vis);
    }
    return ans;
}

int32_t main() {
    
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> val(n+1);
    for(int i=1;i<=n;i++) cin>>val[i];
    vector<int> dp(n+1, -1);

    for(int i=1;i<=n;i++){
        dfs(i, adj, dp, val);
    }

    for(int i=1;i<=n;i++) cout<<dp[i]<<" ";cout<<endl;

    vector<int> dp2(n+1);

    for(int i=1;i<=n;i++){
        vector<int> vis(n+1, 0);
        dp2[i] = dfs2(i, adj, val, vis);
    }
    
    for(int i=1;i<=n;i++) cout<<dp2[i]<<" ";cout<<endl;


}