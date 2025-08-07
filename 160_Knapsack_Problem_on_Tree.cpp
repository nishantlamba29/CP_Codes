#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e4 + 5;
vector<int> adj[N];
int wt[N], val[N], inTime[N], sz[N];
int timer = 0;
int arr[N];

void dfs(int node) {
    inTime[node] = timer++;
    arr[inTime[node]] = node;
    sz[node] = 1;
    for(auto &j : adj[node]) {
        dfs(j);
        sz[node] += sz[j];
    }
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, W;
    cin >> n >> W;

    vector<int> p(n+1);
    for(int i=0;i<n;i++) {
        cin >> p[i+1];
        if(p[i+1] != 0)
        adj[p[i+1]].push_back(i+1);
    }

    for(int i=0;i<n;i++) cin >> wt[i+1];
    for(int i=0;i<n;i++) cin >> val[i+1];

    for(int i=1;i<=n;i++) {
        if(p[i] == 0) dfs(i);
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<=W;j++) {
            if(j - wt[arr[i]] >= 0)
            dp[i][j] = dp[i+1][j-wt[arr[i]]] + val[arr[i]];
            int hi = inTime[arr[i]] + sz[arr[i]];
            if(hi <= n)
            dp[i][j] = max(dp[i][j], dp[hi][j]);
        }
    }
    
    cout << dp[0][W] << "\n";

    return 0;
}