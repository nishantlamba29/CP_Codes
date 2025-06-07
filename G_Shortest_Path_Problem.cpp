#include <bits/stdc++.h>
using namespace std;

int basis[30];
int sz = 0;

void insert(int mask) {
    for(int i=29;i>=0;i--) {
        if(!(mask & (1 << i))) continue;
        if(!basis[i]) {
            basis[i] = mask;
            sz++;
            return;
        }
        mask ^= basis[i];
    }
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n+1, -1);
    // store xor from node 1 to any node
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto &[v, w] : adj[node]) {
            if(dist[v] == -1) {
                dist[v] = dist[node] ^ w;
                q.push(v);
            }
            else {
                // insert into Gaussian basis the xor around cycle
                // we will not over write dist[v] as dist[v] ^ w ^ dist[node]
                // bcz we lost original tree path
                // just insert and later will try to minimise the tree xor
                insert(dist[v] ^ w ^  dist[node]);
            }
        }

    }

    int ans = dist[n];
    // basis only contains cycle xors
    for(int i=29;i>=0;i--) {
        if(ans >> i & 1) ans ^= basis[i];
    }

    cout << ans << "\n";

    return 0;
}