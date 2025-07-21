#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
vector<int> adj[N];
int n, dp[N], sz[N];

void dfs(int node = 1, int p = 1){
    sz[node] = 1;
    for(auto &j : adj[node]) {
        if(j == p) continue;
        dfs(j, node);
        sz[node] += sz[j];
        dp[node] += dp[j] + sz[j];
    }
}

void dfs2(int node = 1, int p = -1) {
    for(auto &j : adj[node]) {
        if(j == p) continue;
        dp[j] = dp[node] - sz[j] + n - sz[j];
        dfs2(j, node);
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

    dfs();
    dfs2();
    for(int i=0;i<n;i++) cout << dp[i+1] << " ";
    cout << "\n";

    return 0;
}