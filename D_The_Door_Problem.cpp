#include "bits/stdc++.h"
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &res, vector<int> &vis){
    vis[node] = 1;
    for(auto &j : adj[node]){
        if(!vis[j]) dfs(j, adj, res, vis);
    }
    res.push_back(node);
}

void dfs(int node, vector<int> adj[], vector<int> &scc, int curr, vector<int> &vis){
    vis[node] = 1;
    scc[node] = curr;
    for(auto &j : adj[node]){
        if(!vis[j]){
            dfs(j, adj, scc, curr, vis);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[2*m+1], radj[2*m+1];
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++) cin>>ans[i];

    vector<vector<int>> room(n+1);
    for(int i=1;i<=m;i++){
        int sz;
        cin>>sz;
        for(int j=0;j<sz;j++){
            int x;
            cin>>x;
            room[x].push_back(i);
        }
    }

    for(int i=1;i<=n;i++){
        int x = room[i][0], y = room[i][1];
        if(ans[i]){// if door is open the switches have same parity
            // both on
            adj[x].push_back(y);
            adj[y].push_back(x);
            // both off
            adj[x+m].push_back(y+m);
            adj[y+m].push_back(x+m);
        } 
        else{// different parity
            adj[x].push_back(y+m);
            adj[y].push_back(x+m);
            adj[x+m].push_back(y);
            adj[y+m].push_back(x);
        } 
    }

    for(int i=1;i<=2*m;i++){
        for(auto &j : adj[i]){
            radj[j].push_back(i);
        }
    }

    vector<int> vis(2*m+1, 0);

    vector<int> topo_order;
    for(int i=1;i<=2*m;i++){
        if(!vis[i]) dfs(i, adj, topo_order, vis);
    }

    reverse(topo_order.begin(), topo_order.end());

    fill(vis.begin(), vis.end(), 0);

    vector<int> scc(2*m+1, -1);

    int curr = 1;
    for(auto &node : topo_order){
        if(vis[node]) continue;
        dfs(node, radj, scc, curr, vis);
        curr++;
    }

    for(int i=1;i<=m;i++){
        if(scc[i] == scc[i+m]){
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}