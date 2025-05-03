#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 100000;
int n, q, depth[N+1], par[N+1][20];
vector<int> tree[N+1];

void dfs(int node = 1, int p = 1, int d = 0){
    par[node][0] = p;
    depth[node] = d;
    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(auto &j : tree[node]){
        if(j != p) {
            dfs(j, node, d + 1);
        }
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--){
        if(diff >> i & 1){
            u = par[u][i];
        }
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

void query(){
    int x, y, a, b, k;
    cin>>x>>y>>a>>b>>k;

    int ut = lca(a, b);
    int len = depth[a] + depth[b] - 2 * depth[ut];
    if((len&1) == (k&1) && len <= k){
        cout<<"YES\n";
        return;
    }

    int len1 = depth[a] + depth[x] - 2 * depth[lca(a, x)] + 1 + depth[y] + depth[b] - 2 * depth[lca(y, b)];
    if((len1&1) == (k&1) && len1 <= k){
        cout<<"YES\n";
        return;
    }
    int len2 = depth[a] + depth[y] - 2 * depth[lca(a, y)] + 1 + depth[x] + depth[b] - 2 * depth[lca(x, b)];
    if((len2&1) == (k&1) && len2 <= k){
        cout<<"YES\n";
        return;
    }

    cout<<"NO\n";

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs();

    cin>>q;
    for(int i=0;i<q;i++){
        query();
    }

    return 0;
}