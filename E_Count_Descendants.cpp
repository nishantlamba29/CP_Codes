#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
vector<int> help[N];
int depth[N], sz[N], inTime[N];
int timer = 0;

void dfs(int node = 1, int p = -1) {
    inTime[node] = timer++;
    sz[node] = 1;
    help[depth[node]].push_back(inTime[node]);
    for(int j : adj[node]) {
        if(j == p) continue;
        depth[j] = depth[node] + 1;
        dfs(j, node);
        sz[node] += sz[j];
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=2;i<=n;i++) {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    depth[1] = 0;
    dfs();

    for(int i=1;i<=n;i++) {
        sort(help[i].begin(), help[i].end());
    }

    int q;
    cin >> q;
    while(q--) {
        int u, d;
        cin >> u >> d;
        int lo = inTime[u];
        int hi = inTime[u] + sz[u] - 1;
        int ans = upper_bound(help[d].begin(), help[d].end(), hi) -  lower_bound(help[d].begin(), help[d].end(), lo);
        cout << ans << "\n";
    }


    return 0;
}