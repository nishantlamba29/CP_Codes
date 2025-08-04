#include <bits/stdc++.h>
using namespace std;
#define int long long

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

DSU *ds = NULL;

const int N = 1e5 + 5;
vector<pair<int,int>> adj[N];
int total, sz[N], val[N];
bool vis[N];
int comp[N];

void dfs(int node, int p, int id, vector<int> &balance) {
    total += ds->sz[node];
    vis[node] = 1;
    for(auto [j, id] : adj[node]) {
        if(vis[j]) continue;
        dfs(j, node, id, balance);
    }
}

void dfs2(int node, vector<int> &balance, int total) {
    sz[node] = ds->sz[node];
    vis[node] = 1;
    for(auto [j, id] : adj[node]) {
        if(vis[j]) continue;
        dfs2(j, balance, total);
        balance[id] += (total - sz[j]) * sz[j];
        sz[node] += sz[j];
    }
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<array<int, 4>> edges;
    for(int i=0;i<n-1;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }

    sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
        return a[2] < b[2];
    });

    vector<int> balance(n-1);
    ds = new DSU(n);
    for(int i=0;i<n-1;i++) {
        vector<int> temp, temp2;
        int wt = edges[i][2];
        while(i < n-1 && edges[i][2] == wt) {
            int u = edges[i][0], v = edges[i][1], ind = edges[i][3];
            int p1 = ds->find(u), p2 = ds->find(v);
            if(p1 != p2) {
                adj[p1].push_back({p2, ind});
                adj[p2].push_back({p1, ind});
                temp2.push_back(p1);
                temp2.push_back(p2);
            }
            temp.push_back(i);
            i++;
        }
        i--;

        for(auto node : temp2) {
            if(!vis[node]) {
                total = 0;
                dfs(node, -1, -1, balance);
                comp[node] = total;
            }
        }
        for(int node : temp2) vis[node] = 0;
        for(int node : temp2) {
            if(!vis[node]) {
                dfs2(node, balance, comp[node]);
            }
        }

        for(int j : temp) {
            int u = edges[j][0], v = edges[j][1];
            ds->merge(u, v);
        }

        for(auto it : temp2) {
            vis[it] = 0;
            adj[it].clear();
        }
    }

    int maxi = *max_element(balance.begin(), balance.end());

    vector<int> ans;
    for(int i=0;i<n-1;i++) {
        if(maxi == balance[i]) ans.push_back(i + 1);
    }
    cout << 2 * maxi << " " << ans.size() << "\n";
    for(auto it : ans) cout << it << " ";

    return 0;
}