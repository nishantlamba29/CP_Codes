#include "bits/stdc++.h"
using namespace std;

const int N = 1e5;
int n, q, u, v, depth[N+1], val[N+1], par[N+1][20];
vector<int> adj[N+1];
vector<vector<int>> edges;
map<vector<int>, int> mp;

void dfs(int node = 1, int p = -1, int d = 0){
    par[node][0] = p;
    depth[node] = d;
    for(int i=1;i<20;i++){
        if(par[node][i-1] != -1) par[node][i] = par[par[node][i-1]][i-1];
        else par[node][i] = -1;
    }
    for(auto &j : adj[node]){
        if(j != p) 
            dfs(j, node, d + 1);
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--){
        if(diff >> i & 1)
            u = par[u][i];
    }
    if(u == v) return u;

    for(int i=19;i>=0;i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void dfs2(int node = 1, int p = -1){
    for(auto &j : adj[node]){
        if(j != p){
            dfs2(j, node);
            if(node < j) mp[{node, j}] = val[j];
            else mp[{j, node}] = val[j];
            val[node] += val[j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(v < u) swap(u, v);
        edges.push_back({u, v});
    }

    dfs();

    cin>>q;
    while(q--){
        cin>>u>>v;
        val[u]++;
        val[v]++;
        int ut = lca(u, v);
        val[ut] -= 2;
    }

    dfs2();

    for(auto &i : edges){
        cout<<mp[i]<<" ";
    }

    return 0;
}