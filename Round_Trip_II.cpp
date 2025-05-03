#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;
int n, m, color[N+1], par[N+1];
vector<int> adj[N+1], cycle;

bool dfs(int node){
    color[node] = 1;
    for(auto &j : adj[node]){
        if(color[j] == 0){
            par[j] = node;
            if(dfs(j)) return 1;
        }
        else if(color[j] == 1){
            cycle.push_back(j);
            int temp = node;
            while(temp != j){
                cycle.push_back(temp);
                temp = par[temp];
            }
            cycle.push_back(temp);
            return 1;
        }
    }
    color[node] = 2;
    return 0;
}


int32_t main() {

    cin>>n>>m;
    for(int i=0;i<=n;i++){
        color[i] = 0;
        par[i] = -1;
    }
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(color[i] == 0){
            if(dfs(i)){
                reverse(cycle.begin(), cycle.end());
                cout<<cycle.size()<<"\n";
                for(auto i : cycle) cout<<i<<" ";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
    
    return 0;
}
