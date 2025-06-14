#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int n, m, q;
const int N = 2501;
vector<int> adj[N];
int dist[N][N][2];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> q;

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            dist[i][j][0] = inf;
            dist[i][j][1] = inf;
        }
    }

    for(int node=1;node<=n;node++) {
        dist[node][node][0] = 0;
        queue<pair<int,int>> q;
        q.push({node, 0});
        while(q.size()) {
            auto [u, p] = q.front();
            q.pop();
            int pp = p ^ 1;
            for(auto &j : adj[u]) {
                if(dist[node][j][pp] > dist[node][u][p] + 1) {
                    dist[node][j][pp] = dist[node][u][p] + 1;
                    q.push({j, pp});
                }
            }
        }
    }

    while(q--) {
        int u, v, x;
        cin >> u >> v >> x;
        int d = dist[u][v][x & 1];
        if(x < d) cout << "NO\n";
        else cout << "YES\n";
    }


    return 0;
}