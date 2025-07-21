#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, m, depth[N], par[N][20];
vector<int> tree[N];
int val[N];

void dfs(int node = 1, int p = -1, int d = 0){
    par[node][0] = p;
    depth[node] = d;
    for(int i = 1; i < 20; i++){
        if(par[node][i-1] != -1)
        par[node][i] = par[par[node][i - 1]][i - 1];
        else par[node][i] = -1;
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

void dfs2(int node = 1, int p = -1) {
    for(auto &j : tree[node]) {
        if(j == p) continue;
        dfs2(j, node);
        val[node] += val[j];
    }
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs();
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        val[a]++;
        val[b]++;
        int c = lca(a, b);
        val[c]--;
        c = par[c][0];
        if(c != -1) val[c]--;
    }

    dfs2();

    for(int i=0;i<n;i++) cout << val[i+1] << " "; 


    return 0;
}