#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool dfs(int node, vector<int> &vis, vector<int> adj[],vector<int>&pathvis){
    vis[node]=1;
    pathvis[node]=1;
    
    for(auto &j : adj[node]){
        if(!vis[j]){
            if(dfs(j,vis,adj,pathvis)){
                return true;
            }
        }
        else if(pathvis[j]){
            return true;
        }
    }
    pathvis[node]=0;
    return false;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    int val=(1LL<<n);
    vector<vector<int>>help(n+1);
    for(int i=0;i<val;i++){
        int val1=__builtin_popcount(i);
        help[val1].push_back(i);
    }
    vector<int>ans;
    for(int pairs=2;pairs<=n;pairs++){
        for(int j=0;j<help[pairs].size();j++){
            int mask=help[pairs][j];
            vector<int>v;
            for(int i=0;i<n;i++){
                if((1LL<<i)&mask){
                    v.push_back(i);
                }
            }
            
            vector<int> vis(n+1, 1);
            vector<int>pathvis(n+1);
            for(auto node : v){
               vis[node]=0;
            }
            if(dfs(v[0],vis,adj, pathvis)){
                if(ans.size()){
                    int sum = accumulate(v.begin(), v.end(), 0);
                    int sum2 = accumulate(ans.begin(), ans.end(), 0);
                    if(sum < sum2){
                        ans = v;
                    }
                }
                else{
                    ans=v;
                }
            }
            
        }
    }
    sort(ans.begin(),ans.end());
    for(auto it:ans) cout<<it+1<<" ";
    cout<<endl;
    return 0;
}
