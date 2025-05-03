#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 200000;
int n, m, depth[N+1], par[N+1][20];
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
    int k;
    cin>>k;
    vector<int> v(k);
    int node = -1, maxi = -1, flag = 1;
    for(int i=0;i<k;i++){
        cin>>v[i];
        if(depth[v[i]] > maxi){
            maxi = depth[v[i]];
            node =  v[i];
        }
    }
    for(int i=0;i<k;i++){
        int ut = lca(par[v[i]][0], node);
        if(ut != par[v[i]][0]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs();

    for(int i=0;i<m;i++){
        query();
    }

    return 0;
}