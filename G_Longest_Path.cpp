#include "bits/stdc++.h"
using namespace std;

int dfs(int node, vector<int> adj[], vector<int>& dp){
    if(dp[node] != -1) return dp[node];

    int ans = 0;
    for(auto j : adj[node]){
        ans = max(ans, dfs(j, adj, dp));
    }

    return dp[node] = 1 + ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1], radj[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }
    vector<int> dp(n+1, -1);
    for(int i=1;i<=n;i++){
        if(dp[i] == -1) dfs(i, adj, dp);
    }

    cout<<*max_element(dp.begin(), dp.end()) -1 <<"\n";

}