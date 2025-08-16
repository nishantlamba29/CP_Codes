#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
int val[N], sz[N];
int res = 0;

vector<int> dfs(int node = 1, int p = -1, int xr = val[1]) {
    vector<int> cnt(22);
    for(int i=0;i<22;i++) {
        if(xr >> i & 1) cnt[i] = 1;
    }
    sz[node] = 1;
    res += val[node];
    int total = 1;
    for(auto ch : adj[node]) {
        if(ch == p) continue;
        vector<int> cnt2 = dfs(ch, node, val[ch] ^ xr);
        sz[node] += sz[ch];
        for(int i=0;i<22;i++) {
            int pairs = 0;
            if(val[node] >> i & 1) {
                pairs += cnt[i] * cnt2[i] + (total - cnt[i]) * (sz[ch] - cnt2[i]);
            }
            else {
                pairs += cnt[i] * (sz[ch] - cnt2[i]) + cnt2[i] * (total - cnt[i]);
            }
            res += (1LL << i) * pairs;
            cnt[i] += cnt2[i];
        }
        total += sz[ch];
    }
    return cnt;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) cin >> val[i+1];

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    cout << res;

    return 0;
}