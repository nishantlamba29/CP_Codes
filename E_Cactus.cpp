#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 100005;
const int mod = 1000000007 ;
int n, m, K, t, a, b, timer, isCycle[N+1], vis[N+1], par[N+1][20], depth[N+1], dp[N+1][20], pr[N+1], sz[N+1], disc[N+1], low[N+1];
vector<int> adj[N+1], tree[N+1];
set<pair<int,int>> bridges;

int modpowr(int a, int b){ 
    int res = 1LL;
    while(b > 0){
        if(b & 1LL) 
        res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1LL;
    }
    return res % mod;
}

int find(int x){
    return x == pr[x] ? x : pr[x] = find(pr[x]);
}
bool merge(int u, int v){
    int p1 = find(u), p2 = find(v);
    if(p1 == p2) return 0;
    if(sz[p1] < sz[p2]) swap(p1, p2);
    pr[p2] = p1;
    sz[p1] += sz[p2];
    return 1;
}

void dfs(int node = 1, int p = -1){
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

void dfs2(int node = find(1), int p = -1, int d = 0){
    dp[node][0] = isCycle[node];
    par[node][0] = p;
    depth[node] = d;

    for(int i=1;i<20;i++){
        if(par[node][i-1] != -1){
            par[node][i] = par[par[node][i-1]][i-1];
            dp[node][i] = dp[par[node][i-1]][i-1] + dp[node][i-1];
        }
        else{
            par[node][i] = -1;
            dp[node][i] = dp[node][i-1];
        }
    }

    for(auto &j : tree[node]){
        if(j != p){
            dfs2(j, node, d + 1);
        }
    }
}

int lca(int u, int v, int &ans){
    if(depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--){
        if(diff >> i & 1LL){
            ans += dp[u][i];
            u = par[u][i];
        }
    }

    if(u == v) return u;

    for(int i=19;i>=0;i--){
        if(par[u][i] != par[v][i]){
            ans += dp[u][i];
            ans += dp[v][i];
            u = par[u][i];
            v = par[v][i];
        }
    }
    ans += dp[u][0];
    ans += dp[v][0];
    return par[u][0];
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<=n;i++){
        sz[i] = 1;
        pr[i] = i;
    }
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a, b});
    }

    timer = 1;
    dfs();

    for(auto &[u, v] : edges){
        if(bridges.find({u, v}) == bridges.end() && bridges.find({v, u}) == bridges.end()){
            merge(u, v);
            isCycle[find(u)] = 1;
            isCycle[find(v)] = 1;
        }
    }

    for(auto &[u, v] : edges){
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
        int ans = 0;
        int ut = lca(a, b, ans);
        ans += isCycle[ut];
        int res = modpowr(2, ans);
        cout<<res<<"\n";

    }

    return 0;
}