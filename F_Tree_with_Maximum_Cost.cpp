#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2'000'05;
vector<int> adj[N+1];
int value[N+1], dp[N+1], sum[N+1];
int answer;

void dfs(int node, int p) {
    sum[node] = value[node];
    for(auto &j : adj[node]) {
        if(j == p) continue;
        dfs(j, node);
        sum[node] += sum[j];
        dp[node] += sum[j] + dp[j];
    }
}

void dfs2(int node, int p) {
    answer = max(answer, dp[node]);
    for(auto &j : adj[node]) {
        if(j == p) continue;

        int t1 = dp[node] - dp[j] - sum[j];
        int t2 = sum[node] - sum[j];
        
        dp[j] += t1 + t2;
        sum[j] += t2;

        dfs2(j, node);
    }
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> value[i+1];
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    dfs2(1, 0);
    cout << answer << "\n";

    return 0;
}