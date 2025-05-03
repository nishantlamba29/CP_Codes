#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 200005;
const int mod = 1000000007 ;
const int inf = 0x3f3f3f3f3f3f3f3fLL;
int n, a, b, timer, isCycle[N+1], vis[N+1], disc[N+1], low[N+1];
vector<int> adj[N+1];
set<pair<int,int>> bridges;

void dfs(int node = 1, int p = -1){
    disc[node] = low[node] = ++timer;
    vis[node] = 1;
    for(auto &j : adj[node]){
        if(j == p) continue;
        if(vis[j]){
            low[node] = min(low[node], disc[j]);
        }
        else{
            dfs(j, node);
            low[node] = min(low[node], low[j]);
            if(low[j] > disc[node]){
                bridges.insert({j, node});
            }
        }
    }
}

vector<int> bfs(int node){
    vector<int> dist(n+1, inf);
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    while(q.size()){
        int node = q.front();
        q.pop();
        for(auto &j : adj[node]){
            if(dist[j] > dist[node] + 1){
                dist[j] = dist[node] + 1;
                q.push(j);
            }
        }
    }
    return dist;
}

void solve(){
    cin>>n>>a>>b;
    bridges.clear();
    for(int i=0;i<=n;i++){
        adj[i].clear();
        disc[i] = 0;
        vis[i] = 0;
        low[i] = 0;
        isCycle[i] = 0;
    }
    vector<pair<int,int>> edges;
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        edges.push_back({x, y});
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(a == b){
        cout<<"NO\n";
        return;
    }
    timer = 0;
    dfs(1, -1);

    for(auto &[u, v] : edges){
        if(bridges.find({u, v}) == bridges.end() && bridges.find({v, u}) == bridges.end()){
            isCycle[u] = 1;
            isCycle[v] = 1;
        }
    }

    vector<int> d1 = bfs(b), d2;
    int atp = -1;
    for(int i=1;i<=n;i++){
        if(isCycle[i] && (atp == -1 || d1[atp] > d1[i])){
            atp = i;
        }
    }
    if(atp != -1)  d2 = bfs(atp);
    if(d2[b] < d2[a]) cout<<"YES\n";
    else cout<<"NO\n";

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}