#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int N = 100;
int n, m, vis[N+1];
vector<int> adj[N+1],radj[N+1], topo;

void dfs(int node){
    vis[node] = 1;
    for(auto &j : adj[node]){
        if(!vis[j]){
            dfs(j);
        }
    }
    topo.push_back(node);
}

void dfs2(int node, vector<int> &temp, int &sum){
    vis[node] = 1;
    sum += node;
    for(auto &j : radj[node]){
        if(!vis[j])
        dfs2(j, temp, sum);
    }
    temp.push_back(node);
}

int main() {
    
    int n, m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    reverse(topo.begin(), topo.end());
    fill(vis, vis+n+1, 0);
    int mini = 1e9;
    vector<int> ans;
    for(auto & node : topo){
        if(vis[node]) continue;
        vector<int> temp;
        int sum = 0;
        dfs2(node, temp, sum);
        if(mini > sum){
            mini = sum;
            ans = temp;
        }
    }

    for(auto i : ans) cout<<i<<" ";
    cout<<"\n";
    
    
    
    return 0;
}
