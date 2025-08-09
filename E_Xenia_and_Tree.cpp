#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int INF = 1e9;
int n, q, depth[N+1], par[N+1][20];
vector<int> tree[N+1];

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

int sz[N], par2[N];
bool mark[N];

void dfs_sz(int node, int p) {
    sz[node] = 1;
    for(auto &j : tree[node]) {
        if(j != p && !mark[j]) {
            dfs_sz(j, node);
            sz[node] += sz[j];
        }
    }
}

int dfs2(int node, int p, int total) {
    for(auto &j : tree[node]) {
        if(j != p && !mark[j] && sz[j] > total / 2) {
            return dfs2(j, node, total);
        }
    }
    return node;
}

void Decompose(int node, int p) {
    dfs_sz(node, p);
    int cen = dfs2(node, p, sz[node]);
    mark[cen] = 1;
    par2[cen] = p;
    for(auto &j : tree[cen]) {
        if(!mark[j]) {
            Decompose(j, cen);
        }
    }
}

int get_dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int best[N];

void update(int node) {
    int temp = node;
    while(temp != -1) {
        best[temp] = min(best[temp], get_dist(temp, node));
        temp = par2[temp];
    }
}

int query(int node) {
    int res = INF;
    int temp = node;
    while(temp != -1) {
        res = min(res, best[temp] + get_dist(temp, node));
        temp = par2[temp];
    }
    return res;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs();

    Decompose(1, -1);

    for(int i=0;i<=n;i++) {
        best[i] = INF;
    }
    best[1] = 0;
    update(1);

    while(m--) {
        int type, node;
        cin >> type >> node;
        if(type == 1) {
            update(node);
        }
        else {
            cout << query(node) << "\n";
        }
    }


    return 0;
}