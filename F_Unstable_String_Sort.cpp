#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n), q(n);
    for(int i=0;i<n;i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int i=0;i<n;i++) {
        cin >> q[i];
        q[i]--;
    }
    vector<vector<int>> adj(n), radj(n);
    for(int i=0;i<n-1;i++) {
        adj[p[i]].push_back(p[i+1]); radj[p[i+1]].push_back(p[i]);
        adj[q[i]].push_back(q[i+1]); radj[q[i+1]].push_back(q[i]);
    }
    vector<bool> vis(n);
    vector<int> order;

    function<void(int)> dfs1 = [&](int node) {
        vis[node] = 1;
        for(auto j : adj[node]) {
            if(!vis[j]) {
                dfs1(j);
            }
        }
        order.push_back(node);
    };
    
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs1(i);
        }
    }

    vector<int> mark(n, -1);
    int id = 0;
    function<void(int)> dfs = [&](int node) {
        mark[node] = id;
        for(auto j : radj[node]) {
            if(mark[j] == -1) {
                dfs(j);
            }
        }
    };

    reverse(order.begin(), order.end());
    for(auto node : order) {
        if(mark[node] == -1) {
            dfs(node);
            id++;
        }
    }

    vector<vector<int>> g(id);
    vector<int> indegree(id);
    set<pair<int, int>> edges;
    for(int i=0;i<n;i++) {
        for(auto j : adj[i]) {
            auto ed = make_pair(mark[i], mark[j]);
            if(mark[i] != mark[j] && edges.find(ed) == edges.end()) {
                g[mark[i]].push_back(mark[j]);
                edges.insert(ed);
                indegree[mark[j]]++;
            }
        }
    }

    vector<int> dp(id);
    queue<int> qq;
    for(int i=0;i<id;i++) {
        if(indegree[i] == 0) {
            qq.push(i);
        }
    }

    while(qq.size()) {
        int node = qq.front();
        qq.pop();
        for(auto j : g[node]) {
            dp[j] = max(dp[j], min(25, dp[node] + 1));
            indegree[j]--;
            if(indegree[j] == 0) {
                qq.push(j);
            }
        }
    }

    int maxi = *max_element(dp.begin(), dp.end());
    if(maxi + 1 < k) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    for(int i=0;i<n;i++) {
        cout << (char)('a' + dp[mark[i]]);
    }

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int _;
    // cin >> _;
    // while (_-->0) {
        solve();
    // }

    return 0;
}