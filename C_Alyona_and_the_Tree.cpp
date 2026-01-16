#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int val[N];
int sz[N];

void dfs(int node = 1) {
    sz[node] = 1;
    for(auto &j : adj[node]) {
        dfs(j.first);
        sz[node] += sz[j.first];
    }
}
int ans = 0;
void dfs2(int node = 1, int sum = 0) {
    for(auto &[ch, wt] : adj[node]) {
        int t1 = max(sum + wt, wt);
        if(t1 > val[ch]) {
            ans += sz[ch];
        }
        else {
            dfs2(ch, t1);
        }
    }
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> val[i];
	
	for(int i=2;i<=n;i++) {
	    int p, c;
	    cin >> p >> c;
	    adj[p].push_back({i, c});
	}
	
    dfs();
    dfs2();
    cout << ans << "\n";
    
}
