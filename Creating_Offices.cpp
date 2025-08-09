#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int INF = 1e9;
vector<int> adj[N];
int sz[N], depth[N], par[N][20], par2[N], best[N];
bool mark[N];
int n, d;

void dfs(int node, int p, int d) {
    depth[node] = d;
    par[node][0] = p;
    for(int i=1;i<20;i++) {
        if(par[node][i-1] != -1) {
            par[node][i] = par[par[node][i-1]][i-1];
        }
        else par[node][i] = -1;
    }
    for(auto &j : adj[node]) {
        if(j != p) {
            dfs(j, node, d + 1);
        }
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--) {
        if(diff >> i & 1) {
            u = par[u][i];
        }
    }
    if(u == v) return u;
    for(int i=19;i>=0;i--) {
        if(par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void dfs_sz(int node, int p) {
    sz[node] = 1;   
    for(auto &j : adj[node]) {
        if(j != p && !mark[j]) {
            dfs_sz(j, node);
            sz[node] += sz[j];
        }
    }
}

int dfs2(int node, int p, int total) { // return centroid
    for(auto &j : adj[node]) {
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
    for(auto &j : adj[cen]) {
        if(!mark[j]) {
            Decompose(j, cen);
        }
    }
}


// update: we open an office at u
void update(int u) {
    int v = u;
    best[u] = 0;
    // walk up the centroid‐parent chain
    while (v != -1) {
        best[v] = min(best[v], dist(v, u));
        v = par2[v];
    }
}

// query: how far is v from its nearest office?
int query(int v) {
    int res = INF;
    int x = v;
    while (x != -1) {
        // best[x] is min dist from x to *some* office
        // dist(x,v) is the distance from x down to v in the original tree
        res = min(res, best[x] + dist(x, v));
        x = par2[x];
    }
    return res;
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> d;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i <= n; i++) {
        mark[i] = false;
        sz[i] = 0;
        depth[i] = 0;
        par2[i] = -1;
        best[i] = INF;
        for(int j = 0; j < 20; j++) par[i][j] = -1;
    }
    // LCA preprocessing
    dfs(1, -1, 0);
    // Centroid decomposition
    Decompose(1, -1);

    vector<pair<int,int>> order;
    for(int i=1;i<=n;i++) {
        order.push_back({depth[i], i});
    }
    sort(order.rbegin(), order.rend());

    vector<int> office;
    for(auto [d2, node] : order) {
        if(query(node) >= d) {
            office.push_back(node);
            update(node);
        }
    }

    cout << office.size() << "\n";
    for(auto it : office) cout << it << " ";


    return 0;
}