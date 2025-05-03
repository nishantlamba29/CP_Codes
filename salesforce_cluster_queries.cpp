#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
        vector<int> par, sz;
        DSU(int n){
            par.resize(n + 1);
            iota(par.begin(), par.end(), 0);
            sz.resize(n + 1, 1);
        }
        int find(int x){
            return x == par[x] ? x : find(par[x]);
        }
        bool merge(int u, int v) {
            int p1 = find(u), p2 = find(v);
            if (p1 == p2) return 0;
            if (sz[p1] < sz[p2]) swap(p1, p2);
            par[p2] = p1;
            sz[p1] += sz[p2];
            return 1;
        }
    };

vector<int> getAssignedCluster( int clusters, vector<vector<int>> connections, vector<vector<int>> queries) {

    DSU dsu(clusters);
    for (auto &conn : connections) {
        dsu.merge(conn[0], conn[1]);
    }

    map<int, set<int>> activeClusters;
    vector<int> vis(clusters + 1, 1);
    for (int i = 1; i <= clusters; ++i) {
        int root = dsu.find(i);
        activeClusters[root].insert(i);
    }

    vector<int> result;

    for (auto &query : queries) {
        int type = query[0];
        int id = query[1];
        int root = dsu.find(id);

        if (type == 1) {
            if(vis[id]) result.push_back(id);
            else if(!activeClusters[root].empty()) result.push_back(*activeClusters[root].begin());
            else result.push_back(-1);
        } else if (type == 2) {
            if(vis[id]) {
                vis[id] = 0;
                activeClusters[root].erase(id);
            }
        }
    }

    return result;
}

int main() {
    // Example Input:
    int clusters = 3;
    vector<vector<int>> connections = {{1, 2}, {2, 3}};
    vector<vector<int>> queries = {
        {2, 2},
        {1, 2},
        {2, 1},
        {2, 3},
        {1, 1}
    };

    vector<int> result = getAssignedCluster(clusters, connections, queries);
    cout << "TC 1\n";
    for (int r : result)    {
        cout << r << endl;
    }

    vector<vector<int>> conn = {{1,2}};
    vector<vector<int>> q = {{1, 2}};

    auto res = getAssignedCluster(2, conn, q);
    cout << "TC 2\n";
    for(auto i : res) cout << i << " ";
    cout << "\n";

    return 0;
}