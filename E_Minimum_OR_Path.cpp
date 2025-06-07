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
        return x == par[x] ? x : find(par[x]);
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
    vector<array<int, 3>> edges(m);
    for(int i=0;i<m;i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int ans = 0;
    vector<int> bad(m, 0);
    for(int bit = 30; bit >= 0; bit--) {
        DSU ds(n);
        for(int i=0;i<m;i++) {
            auto &[u, v, w] = edges[i];
            if(bad[i]) continue;
            if(w >> bit & 1) continue;
            ds.merge(u, v);
        }
        if(!ds.merge(1, n)) {
            for(int i=0;i<m;i++) {
                auto &[u, v, w] = edges[i];
                bad[i] |= (w >> bit & 1);
            }
        }
        else {
            ans |= (1 << bit);
        }
    }

    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();


    return 0;
}