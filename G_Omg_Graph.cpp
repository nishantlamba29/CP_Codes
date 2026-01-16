#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

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

inline void n_lamba_29() {
    int n, m;
    cin >> n >> m;
    vector<array<int,3>> edges;
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    DSU ds(n);

    sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
        return a[2] < b[2];
    });

    vector<int> mn(n + 1, inf);

    int ans = inf;
    for(auto [u, v, w] : edges) {
        int p1 = ds.find(u), p2 = ds.find(v);
        if(p1 != p2) {
            ds.merge(u, v);
            mn[p1] = mn[p2] = min({mn[p1], mn[p2], w});
            if(ds.find(1) == ds.find(n) && ds.find(1) == ds.find(u)) {
                ans = min(ans, mn[p1] + w);
            }
        }
    }

    cout << ans << "\n";

}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }

    return 0;
}