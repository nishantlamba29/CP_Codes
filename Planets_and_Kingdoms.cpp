#include "bits/stdc++.h"
using namespace std;
void dfs1(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){
    vis[node] = 1;
    for(auto j : adj[node]){
        if(!vis[j]){
            dfs1(j, vis, adj, st);
        }
    }
    st.push(node);
}
void dfs2(int node, vector<int>& vis, vector<int> radj[], vector<int>& temp){
    vis[node] = 1;
    for(auto j : radj[node]){
        if(!vis[j]){
            dfs2(j, vis, radj, temp);
        }
    }
    temp.push_back(node);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1], radj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    stack<int> st;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(i, vis, adj, st);
        }
    }
    fill(vis.begin(), vis.end(), 0);
    vector<int> v(n+1);
    int k = 1;
    while(st.size()){
        int node = st.top();
        st.pop();
        if(vis[node]) continue;
        vector<int> temp;
        dfs2(node, vis, radj, temp);
        for(auto i : temp){
            v[i] = k;
        }
        k++;
    }
    cout<<k-1<<'\n';
    for(int i=1;i<=n;i++) cout<<v[i]<<" ";
    return 0;
}