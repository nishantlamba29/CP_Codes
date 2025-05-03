#include "bits/stdc++.h"
using namespace std;
#define int long long

void dfs(int node, vector<int> adj[], vector<int> &res, vector<int> &vis){
    vis[node] = 1;
    for(auto &j : adj[node]){
        if(!vis[j]) dfs(j, adj, res, vis);
    }
    res.push_back(node);
}

void dfs(int node, vector<int> adj[], vector<int> &vis, int val, vector<int> &node_val, int &sum, vector<int> &people){
    vis[node] = 1;
    node_val[node] = val;
    sum += people[node];
    for(auto &j : adj[node]){
        if(!vis[j]) dfs(j, adj, vis, val, node_val, sum, people);
    }
}

int dfs2(int node, vector<int> adj[], vector<int> &people, vector<int> &dp){
    if(dp[node] != -1) return dp[node];
    int ans = 0;
    for(auto &j : adj[node]){
        ans = max(ans, dfs2(j, adj, people, dp));
    }
    return dp[node] = ans + people[node];
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> people(n), adj[n], radj[n];
    for(int i=0;i<n;i++) cin>>people[i];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--, y--;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }

    vector<int> vis(n, 0);
    vector<int> topo_order;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, adj, topo_order, vis);
        }
    }
    reverse(topo_order.begin(), topo_order.end());
    fill(vis.begin(), vis.end(), 0);
    vector<int> node_val(n);
    vector<int> new_people;
    int val = 0;
    for(auto &node : topo_order){
        if(vis[node]) continue;
        int sum = 0;
        dfs(node, radj, vis, val, node_val, sum, people);
        val++;
        new_people.push_back(sum);
    }

    vector<int> g[val];
    set<pair<int,int>> st;
    for(int i=0;i<n;i++){
        for(auto &j : adj[i]){
            if(node_val[i] != node_val[j] && st.find({node_val[i], node_val[j]}) == st.end()){
                g[node_val[i]].push_back(node_val[j]);
            }
        }
    }

    vector<int> dp(val, -1);
    int ans = 0;
    for(int i=0;i<val;i++){
        ans = max(ans, dfs2(i, g, new_people, dp));
    }

    cout<<ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}