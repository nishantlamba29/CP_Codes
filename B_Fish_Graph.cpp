#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n+1);
    vector<int> par(n+1);
    vector<pair<int,int>> ce;

    function<void(int, int)> dfs = [&](int node, int p) {
        vis[node] = 1;
        par[node] = p;
        for(auto &j : adj[node]) {
            if(!vis[j]) {
                dfs(j, node);
            }
            else if(j != p) {
                ce.push_back({node, j});
            }
        }
    };

    
    for(int i = 1; i <=n; i++) {
        if(!vis[i]) {
            dfs(i, i);
        }
    }

    vector<vector<bool>> mp(n+1, vector<bool>(n+1));

    for(auto &[start, end] : ce) {
        if(mp[min(start, end)][max(start, end)]) continue;
        mp[min(start, end)][max(start, end)] = true;

        vector<bool> isPath(n+1);
        vector<int> path, deg(n+1);

        int temp = start;
        int spnode = -1;

        while(temp != end) {
            isPath[temp] = true;
            path.push_back(temp);
            temp = par[temp];
        }

        path.push_back(temp);
        isPath[temp] = true;

        for(int node : path) {
            for(auto & j : adj[node]) {
                if(!isPath[j]) {
                    deg[node]++;
                }
            }
        }
        for(int node : path) {
            if(deg[node] >= 2) {
                spnode = node;
                break;
            }
        }

        if(spnode != -1) {
            cout << "YES\n";
            cout << path.size() + 2 << "\n";
            for(int i=0;i<path.size()-1;i++) {
                cout << path[i] << " " << path[i+1] << "\n";
            }
            cout << end << " " << start << "\n";
            int cnt = 0;
            for(auto &j : adj[spnode]) {
                if(!isPath[j] && cnt < 2) {
                    cout << spnode << " " << j << "\n";
                    cnt++;
                }
            }
            return;
        }
    }

    cout << "NO\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}