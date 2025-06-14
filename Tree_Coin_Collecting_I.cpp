#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

const int N = 200005;
int n, m;
vector<int> adj[N];
int par[N][20], depth[N], minUp[N][20], dist[N];

void dfs(int node = 1, int p = 1, int d = 0) {
    par[node][0] = p;
    depth[node] = d;
    minUp[node][0] = dist[node];
    for(int i=1;i<20;i++) {
        par[node][i] = par[par[node][i-1]][i-1];
        minUp[node][i] = min(minUp[par[node][i-1]][i-1], minUp[node][i-1]);
    }
    for(auto &v : adj[node]) {
        if(v != p) {
            dfs(v, node, d + 1);
        }
    }
}

int lca(int u, int v, int &ans) {
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for(int i=19;i>=0;i--) {
        if(diff >> i & 1) {
            ans = min(ans, minUp[v][i]);
            v = par[v][i];
        }
    }
    if(u == v) {
        ans = min(ans, dist[u]);
        return u;
    }
    for(int i=19;i>=0;i--) {
        if(par[u][i] != par[v][i]) {
            ans = min(ans, minUp[u][i]);
            ans = min(ans, minUp[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    ans = min(ans, minUp[u][0]);
    ans = min(ans, minUp[v][0]);
    ans = min(ans, dist[par[u][0]]);
    return par[u][0];
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    queue<int> q;
    for(int i=1;i<=n;i++) {
        dist[i] = inf;
    }
    for(int i=1;i<=n;i++) {
        int coin;
        cin >> coin;
        if(coin) {
            q.push(i);
            dist[i] = 0;
        }
    }
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(q.size()) {
        int u = q.front();
        q.pop();
        for(auto &j : adj[u]) {
            if(dist[j] > dist[u] + 1) {
                dist[j] = dist[u] + 1;
                q.push(j);
            }
        }
    }

    dfs();

    while(m--) {
        int u, v;
        cin >> u >> v;
        int mini = inf;
        int len = depth[u] + depth[v] - 2 * depth[lca(u, v, mini)];
        cout << len + 2 * mini << "\n";
    }

    return 0;
}