#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> adj[n+1];
    vector<pair<int,int>> edges;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> converted(n+1), sz(n+1), depth(n+1);
    int time = 1;

    function<void(int, int, int)> dfs = [&](int node, int p, int d) {
        converted[node] = time;
        sz[node] = 1;
        time++;
        depth[node] = d;
        for(auto &j : adj[node]) {
            if(j != p) {
                dfs(j, node, d + 1);
                sz[node] += sz[j];
            }
        }
    };

    dfs(1, -1, 0);

    vector<int> bit(n+1, 0);
    auto update = [&](int id, int w) {
        while(id <= n) {
            bit[id] += w;
            id += id & - id;
        }
    };
    auto query = [&](int id) {
        int ans = 0;
        while(id > 0) {
            ans += bit[id];
            id -= id & - id;
        }
        return ans;
    };

    for(int i=1;i<=n;i++) {
        update(converted[i], 1);
    }

    int q;
    cin >> q;
    int total = n;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int x, w;
            cin >> x >> w;
            update(converted[x], w);
            total += w;
        }
        else {
            int y;
            cin >> y;
            y--;

            auto [u, v] = edges[y];
            int child = (depth[u] > depth[v] ? u : v);
            int l = converted[child], r = converted[child] + sz[child] - 1;
            int ans = query(r) - query(l - 1);
            cout << abs(total - 2 * ans) << "\n";

        }
    }

}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();

    return 0;
}