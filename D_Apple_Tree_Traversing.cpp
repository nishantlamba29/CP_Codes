#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> removed(n+1, 0);
    vector<array<int,3>> ans;
    vector<int> par(n+1, -1);

    function<pair<int,int>(int, int)> dfs = [&](int node, int p) {
        par[node] = p;
        pair<int,int> far = {node, 0};
        for(auto &j : adj[node]) {
            if(j != p && !removed[j]) {
                auto temp = dfs(j, node);
                temp.second += 1;
                if(temp.second > far.second || (temp.second == far.second && temp.first > far.first)) {
                    far = temp;
                }
            }
        }
        return far;
    };

    function<void(int)> Diameter = [&](int node) {
        par.assign(n+1, -1);
        auto [x, dist_x] = dfs(node, -1);
        par.assign(n+1, -1);
        auto [y, dist_y] = dfs(x, -1);
        int d = dist_y;

        vector<int> route;
        int temp = y;
        while(temp != x) {
            route.push_back(temp);
            temp = par[temp];
        }
        route.push_back(temp);

        if(y > x) swap(x, y);
        ans.push_back({d + 1, x, y});

        for(auto &i : route) {
            removed[i] = 1;
        }

        for(auto &i : route) {
            for(auto &j : adj[i]) {
                if(!removed[j]) {
                    Diameter(j);
                }
            }
        }
    };

    Diameter(1);

    sort(ans.rbegin(), ans.rend());

    for(auto &[d, x, y] : ans) {
        cout << d << " " << x << " " << y << " ";
    }
    cout << '\n';

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