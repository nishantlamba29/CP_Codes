#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 2e5;
int n, m, pr[N+1], sz[N+1], par[N+1][20], depth[N+1], max_2j[N+1][20];
int dp[N+1];
vector<vector<int>> edges, G[N+1], tree[N+1], ed;


void dfs(int node = 1, int p = 1, int d = 0, int wt = 0){
    par[node][0] = p;
    depth[node] = d;
    max_2j[node][0] = wt;
    dp[node] = max(wt, dp[node]);
    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
        max_2j[node][i] = max(max_2j[par[node][i-1]][i-1], max_2j[node][i-1]);
    }

    for(auto &j : tree[node]){
        if(j[0] != p) {
            dp[j[0]] = dp[node];
            dfs(j[0], node, d + 1, j[1]);
        }
    }
}


int lca(int u, int v, int &ans){
    if(depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--){
        if(diff >> i & 1){
            ans = max(ans, max_2j[u][i]);
            u = par[u][i];
        }
    }

    if(u == v) return u;

    for(int i=19;i>=0;i--){
        if(par[u][i] != par[v][i]){
            ans = max(ans, max_2j[u][i]);
            ans = max(ans, max_2j[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }

    ans = max(ans, max_2j[u][0]);
    ans = max(ans, max_2j[v][0]);

    return par[u][0];
}


int find(int x){
    return x == pr[x] ? x : find(pr[x]);
}
bool merge(int u, int v) {
    int p1 = find(u), p2 = find(v);
    if (p1 == p2) return 0;
    if (sz[p1] < sz[p2]) swap(p1, p2);
    pr[p2] = p1;
    sz[p1] += sz[p2];
    return 1;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u, v, w});
        ed.push_back({u, v, w});
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    sort(edges.begin(), edges.end(), [&](const vector<int> &a, const vector<int> &b){
        return a[2] < b[2];
    });

    for(int i=0;i<=n;i++){
        pr[i] = i;
        sz[i] = 1;
    }

    int mst = 0;
    for(auto &i : edges){
        int u = i[0], v = i[1],w = i[2];
        if(merge(u, v)){
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
            mst += w;
        }
    }

    dfs();

    for(auto &i : ed){
        int u = i[0], v = i[1],w = i[2];
        int maxi = 0;
        int ut = lca(u, v, maxi);
        int ans = max({dp[u], dp[v]});
        // cout<<mst - ans + w<<"\n";
        cout<<mst - maxi + w<<"\n";
    }

}