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

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin >> grid[i];

    DSU ds(n*m);
    vector<int> t1(n), t2(m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '.') {
                t1[i]++;
                t2[j]++;
                continue;
            }
            if(i + 1 < n && grid[i + 1][j] == '#') {
                ds.merge(i * m + j, (i + 1) * m + j);
            }
            if(j + 1 < m && grid[i][j + 1] == '#') {
                ds.merge(i * m + j, i * m + j + 1);
            }
        }
    }

    vector<set<int>> row(n), col(m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '#') row[i].insert(ds.find(i * m + j));
            else {
                if(i + 1 < n && grid[i + 1][j] == '#') row[i].insert(ds.find((i + 1) * m + j));
                if(i - 1 >= 0 && grid[i - 1][j] == '#') row[i].insert(ds.find((i - 1) * m + j));
                if(j + 1 < m && grid[i][j + 1] == '#') row[i].insert(ds.find(i * m + j + 1));
            }
        }
    }
    for(int j=0;j<m;j++) {
        for(int i=0;i<n;i++) {
            if(grid[i][j] == '#') col[j].insert(ds.find(i * m + j));
            else {
                if(j + 1 < m && grid[i][j + 1] == '#') col[j].insert(ds.find(i * m + j + 1));
                if(j - 1 >= 0 && grid[i][j - 1] == '#') col[j].insert(ds.find(i * m + j - 1));
                if(i + 1 < n && grid[i + 1][j] == '#') col[j].insert(ds.find((i + 1) * m + j));
            }
        }
    }

    vector<int> cnt1(n), cnt2(m);
    for(int i=0;i<n;i++) {
        for(int p : row[i]) {
            cnt1[i] += ds.sz[p];
        }
    }
    for(int j=0;j<m;j++) {
        for(int p : col[j]) {
            cnt2[j] += ds.sz[p];
        }
    }
    vector<vector<int>> comp(n*m);
    for(int j=0;j<m;j++) {
        for(int p : col[j]) {
            comp[p].push_back(j);
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) {
        
        vector<int> overlap(m);
        for(int par : row[i]) {
            for(int cl : comp[par]) {
                overlap[cl] += ds.sz[par];
            }
        }

        for(int j=0;j<m;j++) {
            int total = cnt1[i] + cnt2[j] - overlap[j] + t1[i] + t2[j] - (grid[i][j] == '.');
            ans = max(ans, total);
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