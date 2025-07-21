#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, q, depth[N], par[N][20];
vector<int> tree[N];

void dfs(int node = 1, int p = 1, int d = 0){
    par[node][0] = p;
    depth[node] = d;
    for(int i = 1; i < 20; i++){
        par[node][i] = par[par[node][i - 1]][i - 1];
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
    for(int i = 19; i >= 0; i--){
        if((diff >> i) & 1){
            u = par[u][i];
        }
    }

    if(u == v) return u;

    for(int i = 19; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    for(int i=2;i<=n;i++) {
        int p;
        cin >> p;
        tree[i].push_back(p);
        tree[p].push_back(i);
    }
    dfs();
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }


    return 0;
}