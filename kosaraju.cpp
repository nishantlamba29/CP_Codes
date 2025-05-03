#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
void dfs(int node, vector<int>& vis, vector<int> adj[], vector<int>& res){
    vis[node] = 1;
    for(auto &j : adj[node]){
        if(!vis[j]){
            dfs(j, vis, adj, res);
        }
    }
    res.push_back(node);
}

int32_t main(){
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    int m;
    cin>>m;
    vector<int> adj[n+1], radj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vector<int> order1;
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i, vis, adj, order1);
        }
    }
    reverse(order1.begin(), order1.end());
    vis.assign(n+1, 0);
    int ans = 0, ans2 = 1;

    for(auto &i : order1){
        if(vis[i]) continue;
        vector<int> temp;
        dfs(i, vis, radj, temp);
        int mini = 1e10;
        for(auto &j : temp){
            mini = min(mini, v[j]);
        }
        ans += mini;
        int cnt = 0;
        for(auto &j : temp){
            if(mini == v[j]) cnt++;
        }
        if(cnt > 1) 
            ans2 = (ans2*cnt)%mod;

    }
   
    cout<<ans<<" "<<ans2<<"\n";

    return 0;
}