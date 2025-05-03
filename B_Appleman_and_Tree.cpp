#include <bits/stdc++.h>
using namespace std;

const int N = 1e5, mod = 1000000007;
int n, color[N+1];
vector<int> adj[N+1];
int dp[N+1][2];

void dfs(int node = 0){
    dp[node][0] = 1;
    dp[node][1] = 0;

    for(auto &j : adj[node]){
        dfs(j);

        dp[node][1] = (1LL * dp[node][1] * (dp[j][0] + dp[j][1])) % mod;
        dp[node][1] = (dp[node][1] + 1LL * dp[node][0] * dp[j][1]) % mod;
        dp[node][0] = (1LL * dp[node][0] * (dp[j][0] + dp[j][1])) % mod;

    }

    if(color[node]){
        dp[node][1] = dp[node][0];
        dp[node][0] = 0;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
    }

    for(int i=0;i<n;i++) cin>>color[i];

    dfs();

    cout<<dp[0][1];

}