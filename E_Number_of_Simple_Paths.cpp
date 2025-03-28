#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> adj[200001];

int dfs(int node, int par, vector<int> &dfsvis){
    dfsvis[node] = 1;
    int ans = 0;
    for(auto &j : adj[node]){
        if(dfsvis[j]) return 0;
        else if(j != par){
            ans += 1 + dfs(j, node, dfsvis);
        }
    }
    dfsvis[node] = 0;
    return ans;
}

inline void n_lamba_29(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> dfsvis(n+1, 0);
    cout<<dfs(1, -1, dfsvis)<<"\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_-->0)
    n_lamba_29();
}