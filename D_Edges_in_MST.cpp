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

const int N = 1e5 + 5;

vector<pair<int,int>> adj[N];
vector<array<int,4>> edges;
bool vis[N];
int in[N], low[N];
int timer;

void dfs(int node, int par_id, vector<int> &ans) {
    in[node] = low[node] = timer++;
    vis[node] = 1;
    for(auto [j, j_id] : adj[node]) {
        if(j_id == par_id) continue;
        if(vis[j]) {
            ans[j_id] = 2; // at least one
            low[node] = min(low[node], low[j]); 
        }
        else {
            dfs(j, j_id, ans);
            low[node] = min(low[node], low[j]);
            if(low[j] > in[node]) ans[j_id] = 1; // must (any)
            else ans[j_id] = 2; // at least one
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }

    DSU ds(n+1);

    sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
        return a[2] < b[2];
    });

    vector<int> temp;
    vector<int> ans(m);
    vector<int> temp2;
    for(int i=0;i<m;i++) {
        int wt = edges[i][2];
        while(i < m && edges[i][2] == wt) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2], ind = edges[i][3];
            int p1 = ds.find(u), p2 = ds.find(v);
            if(p1 == p2) {
                ans[ind] = 0; // none;
            }
            else {
                temp.push_back(p1);
                temp.push_back(p2);
                adj[p1].push_back({p2, ind});
                adj[p2].push_back({p1, ind});
            }
            temp2.push_back(i);
            i++;
        }
        i--;

        for(auto it : temp) {
            if(!vis[it]) {
                timer = 0;
                dfs(it, -1, ans);
            }
        }

        for(int j : temp2) {
            int u = edges[j][0], v = edges[j][1];
            ds.merge(u, v);
        }

        temp2.clear();
        for(auto it : temp) {
            adj[it].clear();
            vis[it] = 0;
        }
        temp.clear();
    }

    for(int i=0;i<m;i++) {
        if(ans[i] == 0) cout << "none\n";
        else if(ans[i] == 1) cout << "any\n";
        else cout << "at least one\n";
    }


    return 0;
}