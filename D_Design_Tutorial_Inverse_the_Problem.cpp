#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

class DSU {
    public:
    vector<int> par, sz;
    DSU(int n){
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        sz.resize(n + 1, 1);
    }
    int find(int x){
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    bool merge(int u, int v) {
        int p1 = find(u), p2 = find(v);
        if (p1 == p2) return 0;
        if (sz[p1] < sz[p2]) swap(p1, p2);
        par[p2] = p1;
        sz[p1] += sz[p2];
        return 1;
    }
};

void dfs(int root, int node, int p, vector<pair<int,int>> adj[], vector<vector<int>> &dist) {
    for(auto &[j, c] : adj[node]) {
        if(j != p) {
            dist[root][j] = min(dist[root][j], dist[root][node] + c);
            dfs(root, j, node, adj, dist);
        }
    }
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    vector<array<int,3>> edges;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> mat[i][j];
            if(j >= i+1)
            edges.push_back({i, j, mat[i][j]});
        }
    }
    sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
        return a[2] < b[2];
    });
    vector<pair<int, int>> adj[n+1];

    DSU ds(n);
    for(auto &[u, v, w] : edges) {
        if(ds.merge(u, v)) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    vector<vector<int>> dist(n, vector<int>(n, inf));

    for(int i=0;i<n;i++) {
        dist[i][i] = 0;
        dfs(i, i, -1, adj, dist);
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(dist[i][j] != mat[i][j] || (i != j && dist[i][j] == 0)) {
                cout << "NO\n";
                return 0;
            }
            
        }
    }

    cout << "YES\n";

    return 0;
}