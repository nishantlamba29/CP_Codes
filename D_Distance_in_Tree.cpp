#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
const int K = 505;
vector<int> adj[N];
int dp[N][K], temp[K];
int n, k;

int64_t ans = 0;

void dfs(int node = 1, int p = -1) {
    dp[node][0] = 1;
    for(auto &j : adj[node]) {
        if(j != p) {
            dfs(j, node);
            for(int i=1;i<=k;i++) {
                dp[node][i] += dp[j][i-1];
            }
        }
    }
}

void dfs2(int node = 1, int p = -1) {
    ans += dp[node][k];

    for(auto &j : adj[node]) {
        if(j == p) continue;
        // dp[j][i] += (dp[node][i-1] - dp[j][i-2])

        for(int i=0;i<=k;i++) temp[i] = dp[j][i];

        dp[j][1] += dp[node][0];
        for(int i=2;i<=k;i++) {
            dp[j][i] += dp[node][i-1] - temp[i-2];
        }
        
        dfs2(j, node);
    }

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();
    dfs2();

    cout << ans / 2 << "\n";

    return 0;
}