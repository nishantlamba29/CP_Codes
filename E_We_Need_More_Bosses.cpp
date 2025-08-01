#include <bits/stdc++.h>
using namespace std;

const int N = 3'000'05;
vector<int> adj[N], tree[N];
int n, m;
int tin[N], low[N];
bool vis[N];
set<pair<int,int>> bridges;

int timer;
void dfs(int node, int p) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for(auto &j : adj[node]) {
        if(j == p) continue;
        if(vis[j]) {
            low[node] = min(low[node], tin[j]);
        }
        else {
            dfs(j, node);
            low[node] = min(low[node], low[j]);
            if(low[j] > tin[node]) {
                bridges.insert({min(node, j), max(node, j)});
            }
        }
    }
}

int diameter;
int dfs2(int node, int p) {
    int max1 = 0, max2 = 0;
    for(auto &j : tree[node]) {
        if(j == p) continue;
        int d = dfs2(j, node) + 1;
        if(d > max1) {
            max2 = max1;
            max1 = d;
        }
        else if(d > max2) {
            max2 = d;
        }
    }
    diameter = max(diameter, max1 + max2);
    return max1;
}

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;  
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    for(int i=1;i<=n;i++) {
        if(!vis[i]) dfs(i, -1);
    }

    DSU ds(n);

    for(auto [u, v] : edges) {
        if(bridges.find({min(u, v), max(u, v)}) == bridges.end())
        ds.merge(u, v);
    }

    for(auto &[u, v] : bridges) {
        int p1 = ds.find(u), p2 = ds.find(v);
        if(p1 != p2) {
            tree[p1].push_back(p2);
            tree[p2].push_back(p1);
        }
    }


    diameter = 0;
    dfs2(ds.find(1), -1);
    
    cout << diameter << "\n";

    return 0;
}