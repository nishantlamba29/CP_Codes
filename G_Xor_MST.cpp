#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 40;
vector<pair<int,int>> adj[N];
int val[N];

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

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> val[i];

    vector<array<int, 3>> edges;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<30;j++) {
            if(val[i] >> j & 1) {
                int xr = val[i] ^ (1 << j);
                edges.push_back({i, n + j + 1, xr});
            }
        }
    }

    DSU ds(n + 40);
    sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
        return a[2] < b[2];
    });
    
    int ans = 0;
    for(auto [u, v, wt] : edges) {
        if(ds.merge(u, v)) {
            ans += wt;
        }
    }
    for(int i=1;i<=n;i++) {
        
    }
    cout << ans << "\n";

    return 0;
}