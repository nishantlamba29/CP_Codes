#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int dp[N][2];

void dfs(int node = 1, int p = -1) {
    for(auto &j : adj[node]) {
        if(j == p) continue;
        dfs(j, node);
        dp[node][0] += max(dp[j][0], dp[j][1]); // not include 
    }
    for(auto &j : adj[node]) {
        if(j == p) continue;
        dp[node][1] = max(dp[node][1], dp[node][0] - dp[j][1] + dp[j][0] + 1);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}