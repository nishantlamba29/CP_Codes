#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
 
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n+1];

    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    vector<vector<bool>> vis(n+1, vector<bool>(1025, 0));
    queue<pair<int,int>> q;
    q.push({1, 0});
    vis[1][0] = 1;
    int ans = -1;
    while(q.size()) {
        auto [node, xr] = q.front();
        q.pop();
        if(node == n && (ans == -1 || xr < ans)) {
            ans = xr;
        }
        for(auto &[v, w] : adj[node]) {
            int new_xr = xr ^ w;
            if(!vis[v][new_xr]) {
                q.push({v, new_xr});
                vis[v][new_xr] = 1;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}