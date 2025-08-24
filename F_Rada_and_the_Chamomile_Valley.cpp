#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;
vector<pair<int, int>> adj[N];
vector<pair<int, int>> G[N];

int tin[N], low[N];
bool vis[N], isBridge[N];

int timer = 0;
void dfs(int node, int p) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for(auto [ch, id] : adj[node]) {
        if(ch == p) continue;
        if(!vis[ch]) {
            dfs(ch, node);
            low[node] = min(low[node], low[ch]);
            if(low[ch] > tin[node]) {
                isBridge[id] = 1;
            }
        }
        else if(vis[ch]) {
            low[node] = min(low[node], low[ch]);
        }
    }
}

int n, m;
int par[N], sz[N];
int find(int x) {
    return (x == par[x] ? x : par[x] = find(par[x]));
}

void merge(int u, int v) {
    if(sz[v] < sz[u]) swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
}

queue<int> q;
int dist[N];
int query[N];
pair<int, int> edge[N];

bool dfs2(int node, int p) {
    if(node == find(n)) return 1;
    for(auto [ch, id] : G[node]) {
        if(ch == p) continue;
        if(dfs2(ch, node)) {
            auto [u, v] = edge[id];
            q.push(u);
            q.push(v);
            dist[u] = 0;
            dist[v] = 0;
            query[u] = min(query[u], id);
            query[v] = min(query[v], id);
            return 1;
        }
    }
    return 0;
}

inline void n_lamba_29() {

    cin >> n >> m;
    for(int i=0;i<=n;i++) {
        adj[i].clear();
        G[i].clear();
        vis[i] = 0;
        tin[i] = 0;
        low[i] = 0;
        par[i] = i;
        sz[i] = 1;
        dist[i] = inf;
        query[i] = inf;
    }
    for(int i=0;i<=m;i++) {
        isBridge[i] = 0;
    }

    vector<array<int, 2>> edges;
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edges.push_back({u, v});
        edge[i] = {u, v};
    }

    timer = 0;
    dfs(1, -1);
    
    for(int i=0;i<m;i++) {
        if(isBridge[i]) continue;
        int u = edges[i][0], v = edges[i][1];
        int p1 = find(u), p2 = find(v);
        if(p1 != p2) {
            merge(p1, p2);
        }
    }

    if(find(n) == find(1)) {
        int q;
        cin >> q;
        while(q--) {
            int a;
            cin >> a;
            cout << "-1 ";
        }
        cout << "\n";
        return;
    }

    for(int i=0;i<m;i++) {
        if(!isBridge[i]) continue;
        int u = edges[i][0], v = edges[i][1];
        int p1 = find(u), p2 = find(v);
        if(p1 != p2) {
            G[p1].push_back({p2, i});
            G[p2].push_back({p1, i});
        }
    }

    dfs2(find(1), -1);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto [ch, id] : adj[node]) {
            if(dist[ch] > dist[node] + 1) {
                dist[ch] = dist[node] + 1;
                query[ch] = query[node];
                q.push(ch);
            }
            else if(dist[ch] == dist[node] + 1) {
                query[ch] = min(query[ch], query[node]);
                q.push(ch);
            }
        }
    }

    int qq;
    cin >> qq;
    while(qq--) {
        int a;
        cin >> a;
        cout << query[a] + 1 << " ";
    }
    cout << "\n";

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