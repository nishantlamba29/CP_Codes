#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 200005;
int n, m, s, a, b, end1, end2, dfsID, vis[N+1], par[N+1];
vector<int> adj[N+1];

void dfs(int node){
    vis[node] = dfsID;
    for(auto &i : adj[node]){
        if(vis[i] && vis[i] != dfsID){
            end1 = i;
            end2 = node;
        }
        else if(!vis[i]){
            par[i] = node;
            dfs(i);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(b != s)
        adj[a].push_back(b);
    }
    dfsID = 1, end1 = -1, end2 = -1;
    for(auto &i : adj[s]){
        if(!vis[i]){
            par[i] = s;
            dfs(i);
            if(end1 != -1) break;
            else dfsID++;
        }
        else{ // found cycle
            end1 = i;
            end2 = s;
            break;
        }
    }
    if(end1 == -1){
        cout<<"Impossible\n";
        return 0;
    }
    cout<<"Possible\n";
    vector<int> path1, path2;

    int temp = end1;
    while(temp != s){
        path1.push_back(temp);
        temp = par[temp];
    }
    path1.push_back(s);
    

    path2.push_back(end1);
    while(end2 != s){
        path2.push_back(end2);
        end2 = par[end2];
    }
    path2.push_back(s);


    reverse(path1.begin(), path1.end());
    reverse(path2.begin(), path2.end());


    cout<<path1.size()<<"\n";
    for(auto i : path1) cout<<i<<" "; cout<<"\n";
    cout<<path2.size()<<"\n";
    for(auto i : path2) cout<<i<<" "; cout<<"\n";

    return 0;
}