#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> wt(n + 1);
    for(int i=0;i<n;i++) cin >> wt[i+1];
    vector<pair<int,int>> adj[n+1];
    vector<array<int,3>> edges(n-1);
    for(int i=0;i<n-1;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int64_t ans = 0;
    function<void(int,int)> dfs = [&](int node, int p) {
        for(auto &[v, w] : adj[node]) {
            if(v != p) {
                dfs(v, node);
                wt[node] += wt[v];
                ans += 1LL * abs(wt[v]) * w;
            }
        }
    };

    dfs(1, -1);
    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();


    return 0;
}