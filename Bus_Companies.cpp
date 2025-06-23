#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> price(m);
    for(int i=0;i<m;i++) cin >> price[i];

    vector<pair<int,int>> adj[n+m+1];

    for(int i=0;i<m;i++) {
        int k;
        cin >> k;
        for(int j=0;j<k;j++) {
            int city;
            cin >> city;
            adj[city].push_back({n+i+1, price[i]});
            adj[n+i+1].push_back({city, 0});
        }
    }

    vector<int> dist(n+m+1, inf);
    dist[1] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        d *= -1LL;
        if(dist[u] < d) continue;
        for(auto &[v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }

    for(int i=1;i<=n;i++) cout << dist[i] << " "; 
    cout << "\n";
    


    return 0;
}