#include "bits/stdc++.h"
using namespace std;

void dfs(int node, int p, vector<int> adj[], vector<vector<int>>& par, int x){
    par[node][0] = p;
    for(int i=1;i<=x;i++){
        if(par[node][i-1] != -1)
            par[node][i] = par[par[node][i-1]][i-1];
        else 
            par[node][i] = -1;
    }
    for(auto &j : adj[node]){
        if(j != p){
            dfs(j, node, adj, par, x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin>>n>>q;
    vector<int> adj[n];
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    int y = ceil(log2(n));
    vector<vector<int>> par(n, vector<int>(y+1, -1));

    dfs(0, -1, adj,par, y);

    while(q--){
        int x,k;
        cin>>x>>k;
        x--;
        int ans = x;
        for(int i=y;i>=0;i--){
            if(k >> i & 1){
                ans = par[ans][i];
                if(ans == -1) break;
            }
        }
        if(ans == -1) cout<<"-1\n";
        else cout<<ans+1<<"\n";
    }

}