#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
        vector<int> par, sz;
        DSU(int n) {
            par.resize(n + 1);
            iota(par.begin(), par.end(), 0);
            sz.resize(n + 1, 1);
        }
        int find(int x) {
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

int optimizeAPIRegions(int api_nodes, vector<int> api_from, vector<int> api_to, vector<int> api_weight, int k) {
    int m = api_weight.size();
    vector<vector<int>> edges;

    for (int i = 0; i < m; ++i) {
        edges.push_back({api_weight[i], api_from[i] - 1, api_to[i] - 1});
    }
    sort(edges.begin(), edges.end());

    DSU dsu(api_nodes);
    vector<int> used_edges;

    for (auto &t : edges) {
        int w = t[0], u = t[1], v = t[2];
        if (dsu.merge(u, v)) {
            used_edges.push_back(w);
        }
    }
    int remaining = used_edges.size() - (k - 1);
    if (remaining <= 0) return 0;

    sort(used_edges.begin(), used_edges.end());
    return used_edges[remaining - 1];

}

int main() {
    int api_nodes = 3;
    vector<int> api_from = {1, 2, 3};
    vector<int> api_to = {2, 3, 1};
    vector<int> api_weight = {4, 5, 3};
    int k = 2;

    int result = optimizeAPIRegions(api_nodes, api_from, api_to, api_weight, k);
    cout << result << endl; // Output should be 3
}