#include "bits/stdc++.h"
using namespace std;
#define int long long


void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> par(n+1, vector<int>(20));
    vector<int> depth(n+1);
    vector<int> color(n+1, 0); //  0  =>  blue
    color[1] = 1; // 1  =>  red

    function<void(int, int)> dfs = [&](int node, int p) {
        par[node][0] = p;
        for(int i=1;i<20;i++){
            par[node][i] = par[par[node][i-1]][i-1];
        }
        for(auto &j : adj[node]){
            if(j != p){
                depth[j] = depth[node] + 1;
                dfs(j, node);
            }
        }
    };

    auto lca = [&](int u, int v) {
        if(depth[u] < depth[v]) swap(depth[u], depth[v]);
        int diff = depth[u] - depth[v];
        for(int i=19;i>=0;i--){
            if(diff >> i & 1){
                u = par[u][i];
            }
        }
        if(u == v) return u;
        for(int i=19;i>=0;i--){
            u = par[u][i];
            v = par[v][i];
        }
        return par[u][0];
    };

    dfs(1, 1);

    while(m--){
        int typ, v;
        cin >> typ >> v;
        if(typ == 1){
            color[v] = 1;
        }
        else{

        }
    }

}

int32_t main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}