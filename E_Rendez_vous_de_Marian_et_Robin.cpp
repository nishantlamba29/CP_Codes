#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

inline void n_lamba_29() {

    int n, m, h;
    cin >> n >> m >> h;
    vector<pair<int,int>> adj[n+1];
    vector<bool> horse(n+1, false);
    for(int i=0;i<h;i++) {
        int u;
        cin >> u;
        horse[u] = true;
    }

    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto dijkstra = [&](int src) {
        vector<vector<int>> dist(n+1, vector<int>(2, inf));
        dist[src][horse[src]] = 0;
        min_heap<array<int,3>> pq;
        pq.push({0, src, horse[src]});
        while(pq.size()) {
            auto [d, node, flag] = pq.top();
            pq.pop();
            if(dist[node][flag] < d) continue;
            for(auto [v, w] : adj[node]) {
                int wt = (flag ? w / 2 : w);
                int nf = flag | horse[v];
                if(dist[v][nf] > dist[node][flag] + wt) {
                    dist[v][nf] = dist[node][flag] + wt;
                    pq.push({dist[v][nf], v, nf});
                }
            }
        }
        return dist;
    };

    auto d1 = dijkstra(1);
    auto d2 = dijkstra(n);

    int ans = inf;
    for(int i=1;i<=n;i++) {
        ans = min(ans, max(d1[i][0], d2[i][0]));
        ans = min(ans, max(d1[i][0], d2[i][1]));
        ans = min(ans, max(d1[i][1], d2[i][0]));
        ans = min(ans, max(d1[i][1], d2[i][1]));
    }

    if(ans == inf) ans = -1;
    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}