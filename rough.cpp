#include "bits/stdc++.h"
using namespace std;

void dfs(int node, int par, vector<int> adj[], vector<int>& depth, int& ans){
    int m1 = -1, m2 = -1;
    for(auto &j : adj[node]){
        if(j != par){
            dfs(j, node, adj, depth, ans);
            if(depth[j] >= m1){
                m2 = m1;
                m1 = depth[j];
            }
            else if(depth[j] > m2){
                m2 = depth[j];
            }
        }
    }
    depth[node] = m1+1;
    ans = max(ans, m1+m2+2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> adj[n];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> depth(n);
    int diameter = 0;
    dfs(0, -1, adj, depth, diameter);
    cout<<diameter;

}