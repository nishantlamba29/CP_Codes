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
    vector<int>adj[2*m+1], radj[2*m+1];

    for(int i=0;i<n;i++){
        char a,b;
        int x,y;
        cin>>a>>x>>b>>y;
        if(a == '+'){
            if(b == '+') {
                adj[x+m].push_back(y);
                adj[y+m].push_back(x);
                radj[y].push_back(x+m);
                radj[x].push_back(y+m);
            }
            else{
                adj[x+m].push_back(y+m);
                adj[y].push_back(x);
                radj[y+m].push_back(x+m);
                radj[x].push_back(y);
            }
        }
        else{
            if(b == '+') {
                adj[x].push_back(y);
                adj[y+m].push_back(x+m);
                radj[y].push_back(x);
                radj[x+m].push_back(y+m);
            }
            else{
                adj[x].push_back(y+m);
                adj[y].push_back(x+m);
                radj[y+m].push_back(x);
                radj[x+m].push_back(y);
            }
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

    vector<int> ans(m+1);

    for(int i=1;i<=m;i++){
        if(scc[i] == scc[i+m]){
            cout<<"IMPOSSIBLE";
            return;
        }
        ans[i] = scc[i] > scc[i+m];
    }

    for(int i=1;i<=m;i++){
        if(ans[i]) cout<<"+ ";
        else cout<<"- ";
    }


}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}