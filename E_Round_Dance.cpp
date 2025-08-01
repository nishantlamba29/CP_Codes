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

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    DSU ds(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        v[i]--;
        ds.merge(i, v[i]);
    }

    int mn = 0, mx = 0, flag = 0;
    vector<int> vis(n, 0);
    for(int i=0;i<n;i++) {
        if(v[v[i]] == i) {
            vis[ds.find(i)] = 1;
            flag = 1;
        }
    }

    for(int i=0;i<n;i++) {
        if(ds.find(i) == i) {
            mx++;
            if(!vis[i]) mn++;
        }
    }
    mn += flag;
    cout << mn << " " << mx << "\n";

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