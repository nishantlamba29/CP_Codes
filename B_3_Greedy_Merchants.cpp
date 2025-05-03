#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 100005;
int n, m, a, b, K, timer, vis[N+1], low[N+1], disc[N+1], depth[N+1], par[N+1], sz[N+1], up[N+1][20];
vector<int> adj[N+1], tree[N+1];
set<pair<int,int>> bridges;

int find(int x){
    return x == par[x] ? x : par[x] = find(par[x]);
}
bool merge(int u, int v){
    int p1 = find(u), p2 = find(v);
    if(p1 == p2) return 0;
    if(sz[p1] < sz[p2]) swap(p1, p2);
    par[p2] = p1;
    sz[p1] += sz[p2];
    return 1;
}

void dfs(int node, int p){
    disc[node] = low[node] = ++timer;
    vis[node] = 1;
    for(auto &j : adj[node]){
        if(j == p) continue;
        if(vis[j]){
            low[node] = min(low[node], disc[j]);
        }
        else{
            dfs(j, node);
            low[node] = min(low[node], low[j]);
            if(low[j] > disc[node]){
                bridges.insert({j, node});
            }
        }
    }
}

void dfs2(int node = find(1), int p = find(1), int d = 0){
    depth[node] = d;
    up[node][0] = p;
    for(int i=1;i<20;i++){
        up[node][i] = up[up[node][i-1]][i-1];
    }
    for(auto &j : tree[node]){
        if(j != p)
        dfs2(j, node, d + 1);
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--){
        if(diff >> i & 1){
            u = up[u][i];
        }
    }

    if(u == v) return u;

    for(int i=19;i>=0;i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    vector<pair<int,int>> edges;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        edges.push_back({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);  
    }
    timer = 1;
    dfs(1, -1);

    for(auto &[u, v] : edges){
        if(bridges.find({u, v}) == bridges.end() && bridges.find({v, u}) == bridges.end()){
            merge(u, v);
        }
    }

    for(auto &[u, v] : bridges){
        int p1 = find(u), p2 = find(v);
        if(p1 != p2){
            tree[p1].push_back(p2);
            tree[p2].push_back(p1);
        }
    }

    dfs2();

    cin>>K;
    for(int i=0;i<K;i++){
        cin>>a>>b;
        a = find(a), b = find(b);
        int ans = depth[a] + depth[b] - 2*depth[lca(a, b)];
        cout<<ans<<"\n";
    }


    return 0;
}