#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

const int inf = 1e9;

const int N = 1e5 + 5;
vector<int> adj[N];

void solve() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> gd(n + 1);
    vector<vector<int>> help(k + 1);
    for(int i=1;i<=n;i++) {
        cin >> gd[i];
        help[gd[i]].push_back(i);
    }

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dist2(k + 1);

    for(int i=1;i<=k;i++) {
        vector<int> dist(n + 1, inf);
        queue<int> q;
        for(auto u : help[i]) {
            q.push(u);
            dist[u] = 0;
        }
        while(q.size()) {
            int node = q.front();
            q.pop();
            for(auto j : adj[node]) {
                if(dist[j] > dist[node] + 1) {
                    dist[j] = dist[node] + 1;
                    q.push(j);
                }
            }
        }
        dist2[i] = dist;
    }

    for(int i=1;i<=n;i++) {
        vector<int> temp;
        for(int j=1;j<=k;j++) {
            temp.push_back(dist2[j][i]);
        }
        sort(temp.begin(), temp.end());
        long long ans = accumulate(temp.begin(), temp.begin() + s, 0LL);
        cout << ans << " ";
    }
    cout << "\n";



}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int _;
    // cin >> _;
    // while (_-->0) {
        solve();
    // }

    return 0;
}