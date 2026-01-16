#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, qry;
    cin >> n >> qry;
    vector<int> v(n + 1);

    int LOG = 30;
    vector<vector<int>> dp(n + 1, vector<int>(LOG));

    vector<int> indegree(n + 1), in2(n + 1);
    vector<vector<int>> radj(n + 1);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        dp[i][0] = v[i];
        in2[i]++;
        radj[v[i]].push_back(i);
        indegree[v[i]]++;
    }


    for(int j=1;j<LOG;j++) {
        for(int i=1;i<=n;i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }


    vector<int> vis1(n + 1);
    vector<int> iscyclic(n + 1);
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(indegree[i] == 0) {
            q.push(i);
            vis1[i] = 1;
        }
    }
    vector<int> clen(n + 1);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        int ch = v[node];
        if(!vis1[ch])
        indegree[ch]--;
        if(indegree[ch] == 0) {
            q.push(ch);
            vis1[ch] = 1;
        }
    }

    for(int i=1;i<=n;i++) {
        if(!vis1[i]) {
            iscyclic[i] = 1;
        }
    }

    
    vector<int> vis2(n + 1);
    int id = 1;

    vector<int> depth(n + 1);
    auto bfs = [&](int node) {
        queue<int> q;
        q.push(node);
        depth[node] = 0;
        while(q.size()) {
            int node = q.front();
            vis2[node] = id;
            q.pop();
            for(auto j : radj[node]) {
                if(!vis2[j]) {
                    vis2[j] = id;
                    depth[j] = depth[node] + 1;
                    q.push(j);
                }
            }
        }
    };


    for(int i=1;i<=n;i++) {
        if(iscyclic[i] && vis2[i] == 0) {
            bfs(i);
            clen[id] = depth[v[i]] + 1;
            id++;
        }
    }
    
    id = 1;
    vector<pair<int, int>> d2(n + 1);
    vector<int> vis(n + 1);
    auto bfs1 = [&](int node, int ptr) {
        queue<int> q;
        q.push(node);
        d2[node] = {1, ptr};
        while(q.size()) {
            int node = q.front();
            vis[node] = id;
            q.pop();
            for(auto j : radj[node]) {
                if(!vis[j]) {
                    vis[j] = id;
                    d2[j] = {d2[node].first + 1, ptr};
                    q.push(j);
                }
            }
        }
    };
    
    for(int i=1;i<=n;i++) {
        if(iscyclic[i]) {
            for(auto j : radj[i]) {
                if(!iscyclic[j]) {
                    bfs1(j, i);
                    id++;
                }
            }
        }
    }

    while(qry--) {
        int a, b;
        cin >> a >> b;
        if(!iscyclic[a] && !iscyclic[b]) {
            if(vis[a] == vis[b]) {
                int d = d2[a].first - d2[b].first;
                if(d < 0) cout << "-1\n";
                else {
                    int curr = a;
                    for(int j=LOG-1;j>=0;j--) {
                        if(d >> j & 1) {
                            curr = dp[curr][j];
                        }
                    }
                    if(curr == b) cout << d << "\n";
                    else cout << "-1\n";
                }
            }
            else {
                cout << "-1\n";
            }
        }
        else if(iscyclic[a] && !iscyclic[b]) cout << "-1\n";
        else if(iscyclic[a] && iscyclic[b]) {
            if(vis2[a] != vis2[b]) cout << "-1\n";
            else {
                int ans = depth[a] - depth[b];
                if(depth[b] > depth[a]) {
                    ans = clen[vis2[a]] - (depth[b] - depth[a]);
                }
                cout << ans << "\n";
            }
        }
        else {
            if(vis2[a] != vis2[b]) cout << "-1\n";
            else {
                int ptr = d2[a].second;
                int d = depth[ptr] - depth[b];
                if(depth[b] > depth[ptr]) {
                    d = clen[vis2[ptr]] - (depth[b] - depth[ptr]);
                }
                cout << d2[a].first + d << "\n";
            }
        }
    }


    return 0;
}