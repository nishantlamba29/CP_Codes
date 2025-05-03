#include <bits/stdc++.h>
using namespace std;
#define int long long

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

    if(n & 1) {
        cout << "-1\n";
        return;
    }

    int ans = -1;

    vector<int> sz(n+1);

    function<void(int,int)> dfs = [&](int node, int par) {
        sz[node] = 1;
        for(auto &j : adj[node]) {
            if(j != par) {
                dfs(j, node);
                sz[node] += sz[j];
            }
        }
        if(sz[node] % 2 == 0) {
            ans++;
            // sz[node] = 0;
        }
    };


    dfs(1, -1);

    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _ = 1;
    // cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}