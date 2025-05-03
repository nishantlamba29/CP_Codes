#include<bits/stdc++.h>
using namespace std;

#define int long long
int findup(vector<int>&parent,int u){
    if(parent[u]==u){
        return u;
    }
    return parent[u]=findup(parent,parent[u]);
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>g(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    map<pair<int,int>,int> mp;
    vector<pair<int,pair<int,int>>>edges;
    vector<pair<int,int>>v={{0,1},{0,-1},{1,0},{-1,0}};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int val1=i+v[k].first;
                int val2=j+v[k].second;
                if(val1>=0 && val2>=0 && val1<n && val2<m){
                    int parent=i*m +j;
                    int child=val1*m + val2;
                    int wt=abs(g[i][j]-g[val1][val2]);
                    if(mp[{parent,child}]){
                        continue;
                    }
                    edges.push_back({wt,{parent,child}});
                    mp[{parent,child}]=1;
                    mp[{child,parent}]=1;
                }
            }
        }
    }
    // cout<<"size = "<<edges.size()<<"\n\n";
    sort(edges.begin(),edges.end());
    vector<vector<int>>pending(n*m);
    for(int i=0;i<n*m;i++){
        pending[i].push_back(i);
    }
    vector<int>parent(n*m);
    vector<int>size(n*m,1);
    for(int i=0;i<n*m;i++){
        parent[i]=i;
    }
    vector<int>dp(n*m,-1);
    for(int i=0;i<edges.size();i++){
        int wt=edges[i].first;
        int u=edges[i].second.first;
        int v=edges[i].second.second;
        int par1=findup(parent,u);
        int par2=findup(parent,v);
        if(par1==par2){
            continue;
        }
        if(size[par1]<=size[par2]){
            swap(par1,par2);
        }
        parent[par2]=par1;
        size[par1]+=size[par2];
        for(auto it:pending[par2]){
            pending[par1].push_back(it);
        }
        pending[par2].clear();
        if(size[par1]>=k+1){
            for(auto it:pending[par1]){
                if(dp[it]==-1){
                    dp[it]=wt;
                }
            }
            pending[par1].clear();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val=i*m + j;
            cout<<dp[val]<<" ";
        }
        cout<<endl;
    }
}
int32_t main(){
    int t=1;
    while(t--){
        solve();
    }
}