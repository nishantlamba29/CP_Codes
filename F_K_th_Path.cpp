#include "bits/stdc++.h"
using namespace std;

#define int long long



void sop(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,pair<int,int>>>edge;
    
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({w,{u,v}});
    }
    sort(edge.begin(),edge.end());

    vector<int>v;
    for(int i=0;i<min(m,k);i++){
        int wt=edge[i].first;
        int u=edge[i].second.first;
        int v1=edge[i].second.second;
        v.push_back(u);
        v.push_back(v1);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int sz1=v.size();
    vector<vector<int>>dist(sz1,vector<int>(sz1,LLONG_MAX));
    for(int i=0;i<sz1;i++){
        dist[i][i]=0;
    }
    for(int i=0;i<min(m,k);i++){
        int wt=edge[i].first;
        int u=edge[i].second.first;
        int v1=edge[i].second.second;
        int x=lower_bound(v.begin(),v.end(),u)-v.begin();
        int y=lower_bound(v.begin(),v.end(),v1)-v.begin();
        dist[x][y]=dist[y][x] = min(wt, dist[x][y]);
    }
    
    int sz=v.size();
    for(int k=0;k<sz;k++){
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX){
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<sz1;i++){
        for(int j=i+1;j<sz1;j++){
            ans.push_back(dist[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    int fans=ans[k-1];
    
    cout<<fans<<endl;

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sop();
    return 0;

}