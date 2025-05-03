#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pii pair<int,int>
#define vec vector<int>
#define vvec vector<vec>
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
#define pb push_back
#define inf 1e18
#define rep(n) for(int i=0;i<n;i++)
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
int dijkstra(int src, int dest, vector<vector<int>> adj[], int n){
    min_heap<vec> pq;
    pq.push({0, src});
    vector<int> dist(n, inf);
    dist[src] = 0;
    while(pq.size()){
        int u = pq.top()[1], len = pq.top()[0];
        pq.pop();
        if(dist[u] < len) continue;
        for(auto &j : adj[u]){
            int v = j[0], wt = j[1];
            if(dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[dest] == inf ? -1 : dist[dest];

}
inline void n_lamba_29(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj[n];
    rep(m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    int node;
    cin>>node;
    vector<pii> v;
    vector<int> vis(n, 0);
    vis[node] = 1;
    for(auto &i : adj[node]){
        vis[i[0]] = 1;
    }
    sort(all(adj[node]), [](const vec &a, const vec &b){
        return a[1] < b[1];
    });
    int src = adj[node][0][0];
    int dest = -1;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dest = i;
            break;
        }
    }

    int ans = dijkstra(src, dest, adj, n);
    cout<<ans<<"\n";

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    n_lamba_29();
}