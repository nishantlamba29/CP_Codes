#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1);
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    vis[1] = 1;
    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();
        cout << node << " ";
        for(auto j : adj[node]) {
            if(!vis[j]) {
                vis[j] = 1;
                pq.push(j);
            }
        }
    }

    return 0;
}