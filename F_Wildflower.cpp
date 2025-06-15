#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;

int modpowr(int64_t a, int64_t b) {
    int64_t res = 1;
    while(b > 0) {
        if(b & 1LL) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1LL;
    }
    return res;
}

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> par(n+1, -1), depth(n+1), temp;
    function<void(int, int, int)> dfs = [&](int node, int p, int d) {
        par[node] = p;
        depth[node] = d;
        bool leaf = true;
        for(auto &j : adj[node]) {
            if(j != p) {
                leaf = false;
                dfs(j, node, d + 1);
            }
        }
        if(leaf) temp.push_back(node);
    };

    dfs(1, -1, 0);

    if(temp.size() > 2) {
        cout << "0\n";
    }
    else if(temp.size() == 1) {
        cout << modpowr(2, n) << "\n";
    }
    else {
        int u = temp[0], v = temp[1];
        if(depth[u] > depth[v]) swap(u, v);
        int x = u, y = v;

        while(depth[v] != depth[u]) {
            v = par[v];
        }
        while(u != v) {
            u = par[u];
            v = par[v];
        }
        int lca = u;
        u = x, v = y;
        int diff = abs(depth[u] - depth[v]);

        if(diff == 0) {
            int64_t ans = modpowr(2, depth[lca]);
            ans = (ans * 4) % mod; // 2 * pw[depth[lca]] // extra 2 bcz depth start from 0 instead of 1
            cout << ans << "\n";
        }
        else {
            int64_t ans = modpowr(2, diff + depth[lca]);
            ans = (ans * 3) % mod;
            cout << ans << "\n";
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t-- > 0) {
        n_lamba_29();
    }

    return 0;
}
