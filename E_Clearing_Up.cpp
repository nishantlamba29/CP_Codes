#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU {
    public:
    vector<int> par, sz;
    DSU (int n) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        sz.resize(n + 1, 1);
    }
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    bool merge(int u, int v) {
        int p1 = find(u), p2 = find(v);
        if(p1 == p2) return 0;
        if(sz[p1] < sz[p2]) swap(p1, p2);
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
    vector<array<int,4>> edges;
    for(int i=0;i<m;i++) {
        int u, v;
        char ch;
        cin >> u >> v >> ch;
        edges.push_back({u, v, (ch == 'S') ? 1 : 0, i});
    }

    if(n % 2 == 0) {
        cout << "-1\n";
        return 0;
    }

    DSU ds(n), ds2(n); // 1 0

    vector<int> ans(m, 0);
    for(auto [u, v, id, ind] : edges) {
        if(id == 1) ds.merge(u, v);
        else ds2.merge(u, v);
    }
    int c1 = 0, c2 = 0;
    for(auto [u, v, id, ind] : edges) {
        if(id == 0) {
            int p1 = ds.find(u), p2 = ds.find(v);
            if(p1 != p2) {
                ds.merge(u, v);
                c1++;
                ans[ind] = 1;
            }
        }
        else {
            int p1 = ds2.find(u), p2 = ds2.find(v);
            if(p1 != p2) {
                ds2.merge(u, v);
                c2++;
                ans[ind] = 1;
            }
        }
    }

    int req = (n - 1) / 2;
    if(c1 > req || c2 > req) {
        cout << "-1\n";
        return 0;
    }

    DSU ds3(n);
    for(auto [u, v, id, ind] : edges) {
        if(ans[ind] != 0) {
            ds3.merge(u, v);
        }
    }
    for(auto [u, v, id, ind] : edges) {
        if(ans[ind] != 0) continue;
        if(id == 1 && c2 < req) {
            int p1 = ds3.find(u), p2 = ds3.find(v);
            if(p1 != p2) {
                c2++;
                ans[ind] = 1;
                ds3.merge(u, v);
            }
        }
        else if(id == 0 && c1 < req){
            int p1 = ds3.find(u), p2 = ds3.find(v);
            if(p1 != p2) {
                c1++;
                ans[ind] = 1;
                ds3.merge(u, v);
            }
        }
    }

    if(c1 != req && c2 != req) {
        cout << "-1\n";
        return 0;
    }
    
    cout << n - 1 << "\n";
    for(int i=0;i<m;i++) {
        if(ans[i] != 0) cout << i + 1 << " ";
    }
    cout << "\n";

    return 0;
}