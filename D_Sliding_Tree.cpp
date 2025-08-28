#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int par[N];

pair<int, int> dfs(int node, int parent) {
    pair<int, int> farthest = {node, 0};
    par[node] = parent;
    for (auto &neighbor : adj[node]) {
        if (neighbor != parent) {
            pair<int, int> temp = dfs(neighbor, node);
            temp.second += 1;
            if (temp.second > farthest.second) {
                farthest = temp;
            }
        }
    }
    return farthest;
}

inline void n_lamba_29() {

    int n;
    cin >> n;
    for(int i=0;i<=n;i++) {
        adj[i].clear();
        par[i] = -1;
    }

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto [d1, m1] = dfs(1, -1);
    auto [d2, diameter] = dfs(d1, -1);
    if(diameter == n - 1) {
        cout << "-1\n";
        return;
    }

    vector<bool> onPath(n + 1);
    int temp = d2;
    while(temp != -1) {
        onPath[temp] = 1;
        temp = par[temp];
    }

    for(int i=1;i<=n;i++) {
        if(!onPath[i]) continue;
        for(auto j : adj[i]) {
            if(!onPath[j]) continue;
            for(auto c : adj[j]) {
                if(!onPath[c]) {
                    cout << i << " " << j << " " << c << "\n";
                    return;
                }
            }
        }
    }

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