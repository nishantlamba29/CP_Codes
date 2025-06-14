#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> dist(n+1, inf);
    queue<int> q;
    vector<bool> isAnime(n+1, 0);
    vector<int> par(n+1);
    for(int i=0;i<k;i++) {
        int city;
        cin >> city;
        isAnime[city] = 1;
        q.push(city);
        par[city] = city;
        dist[city] = 0;
    }
    vector<int> adj[n+1];
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist2(n+1, inf);

    while(q.size()) {
        int node = q.front();
        q.pop();
        for(auto &j : adj[node]) {
            if(dist[j] > dist[node] + 1) {
                dist[j] = dist[node] + 1;
                par[j] = par[node];
                q.push(j);
            }
            else if(par[j] != par[node]) {
                int d = dist[node] + dist[j] + 1;
                int s1 = par[node], s2 = par[j];
                dist2[s1] = min(dist2[s1], d);
                dist2[s2] = min(dist2[s2], d);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        if(isAnime[i]) {
            if(dist2[i] == inf) dist2[i] = -1;
            cout << dist2[i] << " ";
        }
        else {
            if(dist[i] == inf) dist[i] = -1;
            cout << dist[i] << " ";
        }
    }


    return 0;
}