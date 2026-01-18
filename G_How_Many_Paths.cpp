#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

const int N = 4e5 + 5;
vector<int> adj[N], radj[N];
vector<int> g[N];
bool vis[N];
int mark[N];
stack<int> order;

void dfs(int node) {
    vis[node] = 1;
    for(auto j : adj[node]) {
        if(!vis[j]) {
            dfs(j);
        }
    }
    order.push(node);
}

void dfs2(int node, int id, int &cnt) {
    vis[node] = 1;
    mark[node] = id;
    cnt++;
    for(auto j : radj[node]) {
        if(!vis[j]) {
            dfs2(j, id, cnt);
        }
    }

}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<bool> isLoop(n + 1);
    vector<bool> isSelf(n + 1);

    for(int i=0;i<=n;i++) {
        adj[i].clear();
        radj[i].clear();
        g[i].clear();
        vis[i] = 0;
        mark[i] = 0;
    }

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        if(u == v) {
            isSelf[u] = 1;
        }
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    fill(vis, vis + n + 1, 0);

    int id = 1;
    while(order.size()) {
        int node = order.top();
        order.pop();
        if(vis[node]) continue;
        int cnt = 0;
        dfs2(node, id, cnt);
        if(cnt > 1) isLoop[id] = 1;
        id++;
    }

    set<pair<int, int>> st;
    vector<int> indegree(id);
    for(int i=1;i<=n;i++) {
        for(auto j : adj[i]) {
            auto ed = make_pair(mark[i], mark[j]);
            if(mark[i] != mark[j] && st.find(ed) == st.end()) {
                g[mark[i]].push_back(mark[j]);
                st.insert(ed);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        if(isSelf[i]) {
            isLoop[mark[i]] = 1;
        }
    }
    vector<int> dp(id, 0);
    vector<int> reach(id);
    reach[mark[1]] = 1;

    queue<int> q;
    q.push(mark[1]);
    while(q.size()) {
        int node = q.front();
        q.pop();
        for(auto j : g[node]) {
            if(!reach[j]) {
                reach[j] = 1;
                q.push(j);
            }
        }
    }   

    for(int i=1;i<id;i++) {
        for(auto j : g[i]) {
            if(reach[i] && reach[j])
            indegree[j]++;
        }
    }

    for(int i=1;i<id;i++) {
        if(reach[i] && indegree[i] == 0) {
            q.push(i);
            dp[i] = 1;
            if(isLoop[i]) dp[i] = -1;
        }
    }

    while(q.size()) {
        int node = q.front();
        q.pop();
        for(auto j : g[node]) {
            if(!reach[j]) {
                continue;
            }
            if(dp[j] != -1) {
                if(dp[node] == -1) dp[j] = -1;
                else {
                    dp[j] += dp[node];
                    if(dp[j] > 2) dp[j] = 2;
                }
            }
            indegree[j]--;
            if(indegree[j] == 0) {
                if(isLoop[j]) dp[j] = -1;
                q.push(j);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        if(!reach[mark[i]]) dp[mark[i]] = 0;
        cout << dp[mark[i]] << " ";
    }
    cout << "\n";
    

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