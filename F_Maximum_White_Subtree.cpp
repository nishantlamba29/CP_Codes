#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int inf = 1e9;
vector<int> adj[N];
int n;
int color[N], dp[N];

void dfs(int node = 1, int p = -1) {
    dp[node] = color[node];
    for(auto &j : adj[node]) {
        if(j == p) continue;
        dfs(j, node);
        dp[node] += max(0, dp[j]);
        // if dp[j] < 0 we skip that subtree 
        // so if > means we are considering the subtree including node
    }
}

void dfs2(int node = 1, int p = -1) {
    for(auto &j : adj[node]) {
        if(j == p) continue;
        int temp = dp[node] - max(0, dp[j]);
        dp[j] += max(0, temp);
        dfs2(j, node);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> color[i+1];
        if(!color[i+1]) color[i+1] = -1;
    }
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();
    dfs2();

    for(int i=0;i<n;i++) {
        cout << dp[i+1] << " ";
    }

    return 0;
}