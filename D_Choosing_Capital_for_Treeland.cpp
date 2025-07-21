#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n;
vector<pair<int,int>> adj[N];
int dp[N];
int ans;
vector<int> res;

int dfs(int node, int p) {
    int ans = 0;
    for(auto &[v, w] : adj[node]) {
        if(v == p) continue;
        if(w == -1) ans++;
        ans += dfs(v, node);
    }
    return dp[node] = ans;
}

void dfs2(int node, int p) {
    if(dp[node] < ans) {
        ans = dp[node];
        res.clear();
        res.push_back(node);
    }
    else if(dp[node] == ans) {
        res.push_back(node);
    }
    for(auto &[v, w] : adj[node]) {
        if(v == p) continue;
        dp[v] = dp[node] + w;
        dfs2(v, node);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, -1});
    }

    dfs(1, 0);
    ans = n;
    dfs2(1, 0);
    cout << ans << "\n";
    sort(res.begin(), res.end());
    for(auto i : res) cout << i << " ";

    return 0;
}