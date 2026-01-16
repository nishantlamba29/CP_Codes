#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
pair<int, int> val[N];
int dp[N][2];

void dfs(int node = 1, int p = -1) {

    for(auto j : adj[node]) {
        if(j == p) continue;

        dfs(j, node);

        dp[node][0] += max(abs(val[node].first - val[j].first) + dp[j][0], abs(val[node].first - val[j].second) + dp[j][1]);
        
        dp[node][1] += max(abs(val[node].second - val[j].first) + dp[j][0], abs(val[node].second - val[j].second) + dp[j][1]);

    }

}

inline void n_lamba_29() {

    int n;
    cin >> n;
    for(int i=0;i<=n;i++) {
        adj[i].clear();
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    for(int i=1;i<=n;i++) {
        cin >> val[i].first >> val[i].second;
    }
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    cout << max(dp[1][0], dp[1][1]) << "\n";


}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}