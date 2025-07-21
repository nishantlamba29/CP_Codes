#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int depth[N], ans[N];
pair<int,int> dp[N];

void dfs(int node = 1, int p = 1){
    int m1 = -1, m2 = -1;
    for(auto &j : adj[node]) {
        if(j == p) continue;
        dfs(j, node);
        if(depth[j] > m1) {
            m2 = m1;
            m1 = depth[j];
        }
        else if(depth[j] > m2) {
            m2 = depth[j];
        }
    }
    depth[node] = m1 + 1;
    dp[node] = {m1 + 1, m2 + 1};
}

void dfs2(int node = 1, int p = -1) {
    ans[node] = dp[node].first;
    for (int j : adj[node]) {
        if (j == p) continue;
        int best;
        if(dp[node].first == depth[j] + 1) {
            best = dp[node].second;
            // farthest node is in subtree of j
        }
        else {
            best = dp[node].first;
            // farthest node not in subtree of j
        }
        best++; // bcz re rooting so depth + 1
        int a = dp[j].first, b = dp[j].second;

        int m1 = max({a, b, best});
        int m2 = a + b + best - m1 - min({a, b, best});

        dp[j] = {m1, m2};
        dfs2(j, node);
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
    dfs2();
    for(int i=0;i<n;i++) cout << ans[i+1] << " ";
    cout << "\n";

    return 0;
}