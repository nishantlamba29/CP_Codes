#include "bits/stdc++.h"
using namespace std;

const int N = 1e5;
int n, q, u, v, depth[N+1], sz[N+1], par[N+1][20];
vector<int> adj[N+1];

void dfs(int node = 1, int p = -1, int d = 0){
    par[node][0] = p;
    depth[node] = d;
    sz[node] = 1;
    for(int i=1;i<20;i++){
        if(par[node][i-1] != -1) par[node][i] = par[par[node][i-1]][i-1];
        else par[node][i] = -1;
    }
    for(auto &j : adj[node]){
        if(j != p) {
            dfs(j, node, d + 1);
            sz[node] += sz[j];
        }
    }
}

int kpar(int u, int k){
    for(int i=19;i>=0;i--){
        if(k >> i & 1)
            u = par[u][i];
    }
    return u;
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    u = kpar(u, depth[u] - depth[v]);
    if(u == v) return u;

    for(int i=19;i>=0;i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
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
    }

    dfs();

    cin>>q;
    while(q--){
        cin>>u>>v;
        if(depth[u] < depth[v]) swap(u, v);
        int ut = lca(u, v);
        int diff = depth[u] - depth[v];

        if(diff == 0){
            int len = depth[u] - depth[ut];
            int k = len-1;
            int p1 = kpar(u, k), p2 = kpar(v, k);
            int ans = n - sz[p1] - sz[p2];
            cout<<ans<<"\n";
            continue;
        }
        if(diff & 1){
            cout<<0<<'\n';
            continue;
        }
        int len = depth[u] + depth[v] - 2 * depth[ut];
        int k = len/2 - 1;
        int p1 = kpar(u, k);
        int node = par[p1][0];
        int ans = sz[node] - sz[p1];
        cout<<ans<<"\n";

    }

    return 0;
}