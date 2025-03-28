#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = INT64_MAX;
int dijkstra(int n, vector<vec> adj[], int src, int dest){
    min_heap<vec> pq;
    pq.push({0, src});
    vec dist(n, inf);
    dist[src] = 0;
    while(pq.size()){
        int u = pq.top()[1], len = pq.top()[0];
        pq.pop();
        if(dist[u] < len) continue;
        for(auto & j : adj[u]){
            int v = j[0], wt = j[1];
            if(dist[u] != inf && dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push({dist[v],  v});
            }
        }
    }
    return dist[dest];
}

inline void n_lamba_29(){
    int n,m,L, src, dest;
    cin>>n>>m>>L>>src>>dest;
    vector<vec> adj[n], g[n];
    vector<vector<int>> edges;
    for(int i=0,a,b,c;i<m;i++){
        cin>>a>>b>>c;
        edges.pb({a,b,c});
        if(c != 0){
            g[a].pb({b,c});
            g[b].pb({a,c});
        }
        adj[a].pb({b,(c == 0 ? 1 : c)});
        adj[b].pb({a,(c == 0 ? 1 : c)});
    }
    auto temp= dijkstra(n, g, src, dest);
    if(temp < L){
        cout<<"NO\n";
        return;
    }
    if(temp == L){
        cout<<"YES\n";
        for(auto &i : edges){
            cout<<i[0]<<" "<<i[1]<<" "<<(i[2] == 0 ? L : i[2])<<"\n"; 
        }
        return;
    }
    temp = dijkstra(n, adj, src, dest);
    if(temp > L){
        cout<<"NO\n";
        return;
    }
    if(temp == L){
        cout<<"YES\n";
        for(auto &i : edges){
            cout<<i[0]<<" "<<i[1]<<" "<<(i[2] == 0 ? 1 : i[2])<<"\n";
        }
        return;
    }
    cout<<"YES\n";
    for(auto &i : edges){
        bool flag = 0;
        if(i[2] != 0)  cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
        else{
            if(flag){
                cout<<i[0]<<" "<<i[1]<<" "<<L<<"\n";
            }
            else{
                flag = 1;
                i[2] = 1;
                g[i[0]].pb({i[1],1});
                g[i[1]].pb({i[0],1});
                temp = dijkstra(n, g, src, dest);
                if(temp < L){
                    cout<<i[0]<<" "<<i[1]<<" "<<L+1-temp<<"\n";
                }
                else{
                    cout<<i[0]<<" "<<i[1]<<" 1\n";
                }
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();

    return 0;
}

