#include <bits/stdc++.h>
using namespace std;

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

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<array<int,4>> edges(m);
    for(int i=0;i<m;i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][3] = i;
    }
    sort(edges.begin(), edges.end(),[&](const array<int,4> &a, const array<int,4> &b) {
        return a[2] < b[2];
    });

    DSU ds(n);
    int mst = 0;
    vector<pair<int, int>> adj[n+1];
    for(int i=0;i<m;i++) {
        auto [u, v, w, ind] = edges[i];
        if(ds.merge(u, v)) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            mst += w;
        }
    }

    int par[n+1][20];
    int depth[n+1];
    int max_2[n+1][20];
    function<void(int,int, int, int)> dfs = [&](int node, int p, int d, int weight) {
        par[node][0] = p;
        depth[node] = d;
        max_2[node][0] = weight;
        for(int i=1;i<20;i++) {
            par[node][i] = par[par[node][i-1]][i-1];
            max_2[node][i] = max(max_2[par[node][i-1]][i-1], max_2[node][i-1]);
        }
        for(auto &[v, w] : adj[node]) {
            if(v != p) {
                dfs(v, node, d + 1, w);
            }
        }
    };

    function<int(int,int)> get_max = [&](int u, int v) {
        int ans = 0;
        if(depth[u] > depth[v]) swap(u, v);
        int diff = depth[v] - depth[u];
        for(int i=19;i>=0;i--) {
            if(diff >> i & 1) {
                ans = max(ans, max_2[v][i]);
                v = par[v][i];
            }
        }
        if(u == v) return ans;

        for(int i=19;i>=0;i--) {
            if(par[u][i] != par[v][i]) {
                ans = max(ans, max_2[u][i]);
                ans = max(ans, max_2[v][i]);
                u = par[u][i];
                v = par[v][i];
            }
        }
        ans = max(ans, max_2[u][0]);
        ans = max(ans, max_2[v][0]);
        return ans;
    };

    dfs(1, 1, 0, 0);

    vector<bool> ans(m, true);

    for(int i=0;i<m;i++) {
        auto [u, v, w, ind] = edges[i];
        if(w != get_max(u, v)) ans[ind] = false;
    }

    for(int i=0;i<m;i++) {
        cout << (ans[i] ? "YES\n" : "NO\n");
    }

    return 0;
}