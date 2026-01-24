#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful
#define int long long
const int inf = 1e18;

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
    void merge(int u, int v) {
        int p1 = find(u), p2 = find(v);
        if (p1 == p2) return;
        if (sz[p1] < sz[p2]) swap(p1, p2);
        par[p2] = p1;
        sz[p1] += sz[p2];
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(k + 1);
    vector<int> type(n + 1);
    DSU ds(n + 1);
    int ptr = 1;
    for(int i=1;i<=k;i++) {
        cin >> c[i];
        for(int j=ptr;j<ptr+c[i];j++) {
            type[j] = i;
        }
        ptr += c[i];
    }

    vector<vector<int>> dist(k + 1, vector<int>(k + 1, inf));
    for(int i=1;i<=k;i++) dist[i][i] = 0;

    for(int i=0;i<m;i++) {
        int u, v, x;
        cin >> u >> v >> x;
        if(x == 0) ds.merge(u, v);
        if(type[u] != type[v]) {
            dist[type[u]][type[v]] = min(dist[type[u]][type[v]], x);
            dist[type[v]][type[u]] = min(dist[type[v]][type[u]], x);
        }
    }
    ptr = 1;
    for(int i=1;i<=k;i++) {
        for(int j=ptr;j<ptr + c[i];j++) {
            if(ds.find(j) != ds.find(ptr)) {
                cout << "No\n";
                return;
            }
        }
        ptr += c[i];
    }

    for(int k1=1;k1<=k;k1++) {
        for(int i=1;i<=k;i++) {
            for(int j=1;j<=k;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k1] + dist[k1][j]);
            }
        }
    }

    cout << "Yes\n";
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=k;j++) {
            cout << (dist[i][j] == inf ? -1 : dist[i][j]) << " ";
        }
        cout << "\n";
    }

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int _;
    // cin >> _;
    // while (_-->0) {
        solve();
    // }

    return 0;
}