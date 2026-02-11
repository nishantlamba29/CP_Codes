#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

const int N = 1e5 + 5;
vector<int> adj[N];
string s;
int c1, c2, c3;

void dfs(int node, int p) {
    bool leaf = 1;
    for(auto j : adj[node]) if(j != p) {
        leaf = 0;
        dfs(j, node);
    }
    if(leaf) {
        if(s[node] == '0') c1++;
        else if(s[node] == '1') c2++;
        else c3++;
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i=0;i<=n;i++) {
        adj[i].clear();
    }

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> s;

    c1 = 0, c2 = 0, c3 = 0;
    dfs(0, -1);

    int c4 = count(s.begin(), s.end(), '?') - c3 - (s[0] == '?');
    int ans;
    if(s[0] == '1') {
        ans = c1 + (c3 + 1) / 2;
    }
    else if(s[0] == '0') {
        ans = c2 + (c3 + 1) / 2;
    }
    else {
        ans = max(c1, c2) + (c3 + ((c1 == c2) ? (c4 & 1) : 0)) / 2;
    }

    cout << ans << "\n";

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