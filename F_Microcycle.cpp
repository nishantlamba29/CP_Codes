#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> par, sz;
    public:
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

inline void n_lamba_29() {

    int n, m;
    cin >> n >> m;
    vector<array<int,3>> edges(m);
    for(int i=0;i<m;i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    sort(edges.begin(), edges.end(), [&](const array<int,3> &a, const array<int,3> &b) {
        return a[2] > b[2];
    });

    DSU ds(n);

    int start = -1, end = -1, mini = -1;
    vector<pair<int,int>> adj[n+1];
    for(auto &[u, v, w] : edges) {
        if(ds.merge(u, v)) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        else {
            mini = w;
            start = u;
            end = v;
        }
    }
    vector<int> par(n+1);

    function<void(int, int)> dfs = [&](int node, int p) {
        par[node] = p;
        for(auto &[v, w] : adj[node]) {
            if(v != p) dfs(v, node);
        }
    };

    dfs(start, -1);
    vector<int> path;
    while(end != -1) {
        path.push_back(end);
        end = par[end];
    }

    cout << mini << " " << path.size() << "\n";
    for(auto &i : path) cout << i << " ";
    cout << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}