#include <bits/stdc++.h>
using namespace std;

class DSU{
    public:
    int n;
    vector<int> par, sz;
    DSU(int n) {
        this->n = n+1;
        par.resize(n+1);
        iota(par.begin(), par.end(), 0);
        sz.resize(n+1, 1);
    }
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    bool merge(int u, int v) {
        int p1 = find(u), p2 = find(v);
        if(p1 == p2) return 0;
        if(sz[p1] > sz[p2]) swap(p1, p2);
        par[p1] = p2;
        sz[p2] += sz[p1];
        return 1;
    }
};

inline void n_lamba_29() {

    int n, m;
    cin >> n >> m;
    vector<array<int,3>> edges(m);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    vector<int> bad(m, 0);

    int ans = 0;
    for(int mask = 29; mask >= 0; mask--) {
        DSU ds(n);
        for(int i=0;i<m;i++) {
            auto &[w, u, v] = edges[i];
            if(bad[i]) continue;
            if(w >> mask & 1) continue;
            ds.merge(u, v);
        }

        int p1 = ds.find(1), p2 = ds.find(n);
        if(p1 == p2 && ds.sz[p1] == n) {
            for(int i=0;i<m;i++) {
                auto &[w, u, v] = edges[i];
                bad[i] |= (w >> mask & 1);
            }
        }
        else {
            ans |= (1 << mask);
        }
    }

    cout << ans << "\n";

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