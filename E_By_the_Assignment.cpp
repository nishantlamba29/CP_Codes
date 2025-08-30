#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;

const int N = 2e5 + 5;
vector<pair<int, int>> adj[N];
vector<int> adj2[N];
bool isBridge[2 * N];
bool vis[N], vis2[N];
int tin[N], low[N], color[N];
int weight[N];
int timer;

void dfs(int node, int p) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for(auto [j, id] : adj[node]) {
        if(j == p) continue;
        if(!vis[j]) {
            dfs(j, node);
            low[node] = min(low[node], low[j]);
            if(low[j] > tin[node]) {
                isBridge[id] = 1;
            }
        }
        else {
            low[node] = min(low[node], low[j]);
        }
    }
}

bool bip_dfs(int node, int c) {
    color[node] = c;
    for(auto j : adj2[node]) {
        if(color[j] == -1) {
            if(!bip_dfs(j, 1 ^ c)) return 0;
        }
        else if(color[j] == color[node]) return 0;
    }
    return 1;
}

void val_dfs(int node, set<int> &vals) {
    vis2[node] = 1;
    vals.insert(weight[node]);
    for(auto j : adj2[node]) {
        if(!vis2[j]) {
            val_dfs(j, vals);
        }
    }
}

inline void n_lamba_29() {

    int n, m, W;
    cin >> n >> m >> W;
    for(int i=0;i<=n;i++) {
        adj[i].clear();
        adj2[i].clear();
        vis[i] = 0;
        color[i] = -1;
        vis2[i] = 0;
    }
    timer = 0;
    for(int i=0;i<=m;i++) {
        isBridge[i] = 0;
    }

    for(int i=1;i<=n;i++) cin >> weight[i];
    vector<array<int, 3>> edges;
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edges.push_back({u, v, i});
    }


    dfs(1, -1);

    for(auto [u, v, id] : edges) {
        if(isBridge[id]) continue;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    int ans = 1;
    for(int i=1;i<=n;i++) {
        if(vis2[i]) continue;
        if(adj2[i].size() == 0) {
            vis2[i] = 1;
            if(weight[i] == -1) {
                ans = (ans * W) % mod;
            }
            continue;
        }

        bool isBip = bip_dfs(i, 0);
        set<int> vals;
        val_dfs(i, vals);

        if(isBip) {
            if(vals.size() > 2) {
                ans = 0;
                break;
            }
            else if(vals.size() == 2) {
                auto it = vals.begin();
                if(*it != -1) {
                    ans = 0;
                    break;
                }
            }
            else if(vals.size() == 1) {
                if(*vals.begin() == -1) {
                    ans = (ans * W) % mod;
                }
            }
        }
        else {
            for(int ele : vals) {
                if(ele != -1 && ele != 0) {
                    ans = 0;
                    break;
                }
            }
        }
        if(ans == 0) break;
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