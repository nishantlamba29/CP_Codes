#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int n;
vector<int> adj[N];
int val[N], dp[N][2]; // even odd
int ans[N];

void dfs(int node = 1, int p = -1) {
    int even = 1, odd = 0;
    for(auto ch : adj[node]) {
        if(ch == p) continue;
        dfs(ch, node);
        int ch_even = dp[ch][0], ch_odd = dp[ch][1];

        int val1 = (even * ch_odd) % mod;
        int val2 = (odd * ch_even) % mod;
        val1 = (val1 * val[node]) % mod;
        val1 = (val1 + mod) % mod;
        val2 = (val2 * val[node]) % mod;
        val2 = (val2 + mod) % mod;
        int val3 = ((val1 - val2) % mod + mod) % mod;
        ans[node] = (ans[node] + val3) % mod;
        
        even += ch_odd;
        odd += ch_even;
    }

    dp[node][0] = even;
    dp[node][1] = odd;
}

int result = 0;
void dfs2(int node = 1, int p = -1) {

    result = (result + ans[node]) % mod;

    for(auto ch : adj[node]) {
        if(ch == p) continue;
        
        int even = dp[node][0] - dp[ch][1];
        int odd = dp[node][1] - dp[ch][0];

        int val1 = (odd * dp[ch][0]) % mod;
        val1 = (val1 * val[ch]) % mod;
        val1 = (val1 + mod) % mod;
        int val2 = (even * dp[ch][1]) % mod;
        val2 = (val2 * val[ch]) % mod;
        val2 = (val2 + mod) % mod;
        int val3 = ((val1 - val2) % mod + mod) % mod;
        ans[ch] = (ans[ch] + val3) % mod;

        dp[ch][0] += odd;
        dp[ch][1] += even;
        dfs2(ch, node);

    }

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> val[i];
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();
    dfs2();
    result = (result * 2) % mod;
    for(int i=1;i<=n;i++) {
        result = ((result + val[i]) % mod + mod) % mod;
    }
    cout << result << "\n";

    return 0;
}