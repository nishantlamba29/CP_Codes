#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e17;
int dfs(int node, vector<int> adj[], vector<int>& v){ 
    if(adj[node].empty()) return v[node];
    int ans = inf;
    for(auto &j : adj[node]){
        ans = min(ans, dfs(j, adj, v));
    }
    int temp = min(ans, v[node]);
    return (ans+temp)>>1;
}
inline void n_lamba_29(){
    int n;
    cin>>n;
    vector<int> v(n+1), adj[n+1];
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i+1);
    }
    int mini = inf;
    for(auto &j : adj[1]){
        mini = min(mini, dfs(j, adj, v));
    }
    cout<<mini + v[1] <<"\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tending_to_;
    cin>>tending_to_;
    while(tending_to_-->0)
    n_lamba_29();

    return 0;
}