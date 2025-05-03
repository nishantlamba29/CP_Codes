#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> adj[], vector<int> &dp){
    if(dp[node] != -1) return dp[node];
    int ans = 0;
    for(auto i : adj[node]){
        ans = max(ans, dfs(i, adj, dp));
    }
    return dp[node] = 1 + ans; 
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int j=0;j<n;j++) cin>>v[j];

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    auto check = [&](int nx, int ny){
        return (nx >= 0 && nx < n && ny >= 0 && ny < m);
    };

    vector<int> adj[n*m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int nx = i+dx[k], ny = j+ dy[k];
                if(check(nx, ny) && v[nx][ny] > v[i][j]){
                    adj[m*i+j].push_back(m*nx+ny);
                }
            }
        }
    }

    vector<int> dp(n*m, -1);
    int ans = 1;
    for(int i=0;i<n*m;i++){
        if(dp[i] == -1) ans = max(ans, dfs(i, adj, dp));
    }
    cout<<ans-1<<"\n";

    return 0;
}