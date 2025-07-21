#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200005;
vector<int> adj[N];
int dp[N], sz[N];
int n, ans;

void dfs(int node = 1, int p = -1) {
    sz[node] = 1;
    dp[node] = sz[node];
    for(auto &j : adj[node]) {
        if(j != p) {
            dfs(j, node);
            sz[node] += sz[j];
            dp[node] += dp[j] + sz[j];
        }
    }
}

void dfs2(int node = 1, int p = -1) {
    ans = max(ans, dp[node]);
    for(auto &j : adj[node]) {
        if(j != p) {
            // start with sum at old root ->   dp[node]
            // remove all distances into j’s subtree  ->    sz[j]
            // add all distances from j into the rest of the tree ->     (n - sz[j])
            dp[j] = dp[node] + (n - sz[j]) - sz[j];
            dfs2(j, node);
        }
    }
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 0;
    dfs();
    dfs2();

    cout << ans << "\n";

    return 0;
}