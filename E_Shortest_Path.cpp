#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int n, m, k;
const int N = 3005;
vector<int> adj[N];
int dist[N][N];
pair<int,int> par[N][N];
set<array<int,3>> bad;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<k;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bad.insert({a, b, c});
    }

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            dist[i][j] = inf;
            par[i][j] = {-1, -1};
        }
    }

    queue<pair<int,int>> q;
    q.push({0, 1});
    dist[0][1] = 0;

    int end_b = -1;
    while(q.size()) {
        auto [u, v] = q.front();
        q.pop();
        if(v == n) {
            end_b = u;
            break;
        }
        for(auto w : adj[v]) {
            if(bad.find({u, v, w}) != bad.end()) continue;
            if(dist[v][w] > dist[u][v] + 1) {
                dist[v][w] = dist[u][v] + 1;
                par[v][w] = {u, v};
                q.push({v, w});
            }
        }
    }

    if(end_b == -1) {
        cout << "-1\n";
        return 0;
    }

    vector<int> path;
    int v = n, u = end_b;
    while(!(u == 0 && v == 1)) {
        path.push_back(v);
        auto temp = par[u][v];
        v = u;
        u = temp.first;
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    cout << path.size() - 1 << "\n";
    for(auto i : path) cout << i << " ";
    cout << "\n";


    return 0;
}