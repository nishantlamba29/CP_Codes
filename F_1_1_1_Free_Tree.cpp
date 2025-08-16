#include <bits/stdc++.h>
using namespace std;
const int B = 3000;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> adj[n+1];
    vector<int> color(n+1);
    for(int i=0;i<n;i++) cin >> color[i+1];

    int64_t total = 0;
    for(int i=0;i<n-1;i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        if(color[v] != color[u]) total += c;
    }

    vector<bool> isBig(n+1, 0);

    for(int i=1;i<=n;i++) {
        if(adj[i].size() > B) isBig[i] = 1;
    }
    
    vector<map<int,int64_t>> mp(n+1);
    for(int i=1;i<=n;i++) {
        if(isBig[i]) {
            for(auto &[j, c] : adj[i]) {
                mp[i][color[j]] += c;
            }
        }
    }

    vector<pair<int,int>> g[n+1];
    for(int i=1;i<=n;i++) {
        for(auto &j : adj[i]) {
            if(isBig[j.first]) {
                g[i].push_back(j);
            }
        }
    }

    while(q--) {
        int v, x;
        cin >> v >> x;
        if(isBig[v]) {
            total += mp[v][color[v]];
            total -= mp[v][x];
            for(auto &[j, c] : g[v]) {
                mp[j][color[v]] -= c;
                mp[j][x] += c;
            }
        }
        else {
            for(auto &[j, c] : adj[v]) {
                if(color[j] != color[v]) total -= c;
                if(color[j] != x) total += c;
            }
            for(auto &[j, c] : g[v]) {
                mp[j][color[v]] -= c;
                mp[j][x] += c;
            }
        }
        color[v] = x;
        cout << total << "\n";
    }


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}