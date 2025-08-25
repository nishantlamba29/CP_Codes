#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> distrib((int) 1e9, (int) 2e9);
const int m1 = distrib(rng);
const int m2 = distrib(rng);

const int N = 1e5 + 5;
const int inf = 1e18;
vector<pair<int, int>> adj[N];
vector<pair<int, int>> radj[N];
int n, m;

array<vector<int>, 3> dijkstra(int src, vector<pair<int, int>> adj[]) {
    vector<int> dist(n + 1, inf);
    dist[src] = 0;
    priority_queue<array<int, 2>> pq;
    vector<int> dp(n + 1), dp2(n + 1);
    pq.push({0, src});
    dp[src] = 1;
    dp[src] = 1;
    while(!pq.empty()) {
        auto [d, node] = pq.top();
        d *= -1LL;
        pq.pop();
        if(dist[node] < d) continue;

        for(auto [j, w] : adj[node]) {
            if(dist[j] > (dist[node] + w)) {
                dist[j] = dist[node] + w;
                dp[j] = dp[node];
                dp2[j] = dp2[node];
                pq.push({-1LL * dist[j], j});
            }
            else if(dist[j] == (dist[node] + w)) {
                dp[j] = (dp[j] + dp[node]) % m1;
                dp2[j] = (dp2[j] + dp2[node]) % m2;
            }
        }
    }
    return {dist, dp, dp2};
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    vector<array<int, 3>> edges;
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    auto [dist1, dp1, dp11] = dijkstra(1, adj);
    auto [dist2, dp2, dp22] = dijkstra(n, radj);

    set<int> res;
    for(int i=1;i<=n;i++){
        if(dist1[i] + dist2[i] == dist1[n]) {
            int p1 = (dp1[i] * dp2[i]) % m1;
            int p2 = (dp11[i] * dp22[i]) % m2;
            if(p1 == dp1[n] && p2 == dp11[n]) {
                res.insert(i);
            }
        }
        
    }

    cout << res.size() << "\n";
    for(int i : res) cout << i << " "; cout << "\n";

    return 0;
}