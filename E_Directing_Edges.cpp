#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<pair<int, int>> edges, e2;
    for(int i=0;i<m;i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1) {
            adj[u].push_back(v);
            indegree[v]++;
            edges.push_back({u, v});
        }
        else {
            e2.push_back({u, v});
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while(q.size()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto j : adj[node]) {
            indegree[j]--;
            if(indegree[j] == 0) {
                q.push(j);
            }
        }
    }

    if(topo.size() != n) {
        cout << "NO\n";
        return;
    }

    vector<int> pos(n + 1, -1);
    for(int i=0;i<n;i++) pos[topo[i]] = i;

    for(auto [u, v] : e2) {
        if(pos[u] > pos[v]) swap(u, v);
        edges.push_back({u, v});
    }

    cout << "YES\n";
    for(auto [u, v] : edges) {
        cout << u << " " << v << "\n";
    }

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