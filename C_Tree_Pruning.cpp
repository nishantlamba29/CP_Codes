#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
vector<int> adj[N];
int pre1[N];
int maxd[N];

int dfs(int node = 1, int p = -1, int d = 1) {
    pre1[d]++;
    int maxi = d;
    for(int j : adj[node]) {
        if(j != p) {
            maxi = max(maxi, dfs(j, node, d + 1));
        }
    }
    maxd[maxi]++;
    return maxi;
}

inline void n_lamba_29() {

    int n;
    cin >> n;
    for(int i=0;i<=n;i++) {
        adj[i].clear();
        pre1[i] = 0;
        maxd[i] = 0;
    }
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    for(int i=1;i<=n;i++) {
        pre1[i] += pre1[i - 1];
        maxd[i] += maxd[i- 1];
    }

    int ans = n;

    for(int d = n; d >= 1; d--) {
        int t1 = n - pre1[d];
        int t2 = maxd[d - 1];
        ans = min(ans, t1 + t2);
    }
    cout << ans << "\n";

}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}