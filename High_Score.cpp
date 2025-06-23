#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m,vector<int>(3));
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges[i][0] = x;
        edges[i][1] = y;
        edges[i][2] = -1LL*z;
    }
    vector<int> dist(n+1,inf);
    dist[1] = 0;
    for(int k=0;k<n;k++){
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(dist[u] != inf && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }
    }
 /*
 
 trapped cycle   ans != -1
 u -> (a->b->c->a)
 from abc we can't escape to any other node , goal was to reach 1 to n but since trapping in abc
 can make inf profit but we can't reach n (so our answer will not be -1 as there is negative cycle)
but it is trapped and does not relax other nodes which are in path from 1 to n





 escapable cycle  ans == -1
 as we escape and make evry other node -inf
 thus we need n-1 more iterations for making every other node -inf
 
 */
    for(int k=0;k<n;k++){
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(dist[u] != inf && dist[v] > dist[u] + w){
                dist[v] = -1LL*inf;
            }
            
        }
    }
 
    if(dist[n] == -1LL*inf){
        cout<<-1;
    }
    else{
        cout<<-1LL*dist[n];
    }



    return 0;
}