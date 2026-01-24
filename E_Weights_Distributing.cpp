#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

const int N = 2e5 + 5;
vector<int> adj[N];

vector<int> get_dist(int n, int src) {
    queue<int> q;
    vector<int> dist(n + 1, -1);
    q.push(src);
    dist[src] = 0;
    while(q.size()) {
        int node = q.front();
        q.pop();
        for(auto j : adj[node]) {
            if(dist[j] == -1) {
                dist[j] = dist[node] + 1;
                q.push(j);
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    for(int i=0;i<=n;i++) {
        adj[i].clear();
    }

    vector<int> price(m);
    for(int i=0;i<m;i++) cin >> price[i];

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> da = get_dist(n, a);
    vector<int> db = get_dist(n, b);
    vector<int> dc = get_dist(n, c);
    
    sort(price.begin(), price.end());
    vector<long long> pref(m + 1);
    for(int i=1;i<=m;i++) pref[i] = pref[i-1] + price[i-1];
    long long ans = INT64_MAX;

    for(int i=1;i<=n;i++) {
        int total = da[i] + db[i] + dc[i];
        if(total > m) continue;
        long long cost = pref[db[i]] + pref[total];
        ans = min(ans, cost);
    }

    cout << ans << "\n";

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        solve();
    }

    return 0;
}