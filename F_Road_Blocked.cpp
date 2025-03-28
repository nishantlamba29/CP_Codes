/*
⠈⠙⠲⢶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⡀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⣼⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⠟⠓⠉
⠀⠀⠀⠀⠈⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⢀⣧⣶⣦⣇⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠉⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣶⣾⣿⣿⣿⣿⣶⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠛⠛⠛⠛⠛⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠟⠛⠛⠛⠛⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠀⠀⠀
*/
#include<bits/stdc++.h>
using namespace std;
// Consistency doesn't guarantee you will be successful
// but not being consistent will guarantee that you won't reach success.
#define int long long
#define ld long double
#define pii pair<int,int>
#define vec vector<int>
#define vvec vector<vec>
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)
#define gcd __gcd
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e15;
const int ninf = INT64_MIN;
const int mod = 998244353;
void dijkstra(int src, vector<vector<int>> adj[], int n, vector<vec> &dist){
    dist[src][src] = 0;
    min_heap<vec> pq;
    pq.push({0, src});
    while(pq.size()){
        int u = pq.top()[1], len = pq.top()[0];
        pq.pop();
        if(dist[src][u] < len) continue;
        for(auto &j : adj[u]){
            int v = j[0], wt = j[1];
            if(dist[src][v] > dist[src][u] + wt){
                dist[src][v] = dist[src][u] + wt;
                pq.push({dist[src][v], v});
            }
        }
    }
}
inline void n_lamba_29(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vec> adj[n+1], edges;
    for(int i=0,a,b,c;i<m;i++){
        cin>>a>>b>>c;
        edges.pb({a,b,c});
    }
    set<int> st;
    vector<vec> query;
    for(int i=1;i<=q;i++){
        int a;
        cin>>a;
        if(a == 1){
            int b;
            cin>>b;
            query.pb({i, b-1});
            st.insert(b-1);
        }
        else{
            int x,y;
            cin>>x>>y;
            query.pb({i,x,y});
        }
    }
    vector<vec> dist(n+1,vec(n+1, inf));
    for(int i=0;i<m;i++){
        if(st.find(i) == st.end()){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].pb({v, wt});
            adj[v].pb({u, wt});
        }
    }
    vector<int> res;
    
    for(int i=1;i<=n;i++) dijkstra(i, adj, n, dist);
    for(int i=q-1;i>=0;i--){
        auto it = query[i];
        if(it.size() == 3){
            int src = it[1], dest = it[2];
            int ans = dist[src][dest] >= inf ? -1 : dist[src][dest];
            res.pb(ans);
        }
        else{
            auto edge = edges[it[1]];
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].pb({v, wt});
            adj[v].pb({u, wt});
            for(int i=1;i<=n;i++) dijkstra(i, adj, n, dist);
        }
        
    }
    reverse(all(res));
    for(auto &i : res) cout<<i<<"\n";

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();

    return 0;
}
// Nishant ...