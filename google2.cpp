#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
vector<vector<int>> adj;
vector<int> w;
vector<int> subtree_sum;

void dfs_subtree_sum(int node, int parent) {
    subtree_sum[node] = w[node];
    for (auto child : adj[node]) {
        if (child == parent) continue;
        dfs_subtree_sum(child, node);
        subtree_sum[node] += subtree_sum[child];
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        adj.clear();
        adj.resize(n + 1);
        w.resize(n + 1);
        subtree_sum.resize(n + 1);
        
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }
        
        int u, v;
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 1: Calculate the subtree sums with an arbitrary root, say node 1
        dfs_subtree_sum(1, -1);
        
        // Step 2: Calculate the initial total sum of the tree
        int total_sum = 0;
        for (int i = 1; i <= n; i++) {
            total_sum += w[i];
        }
        
        // Step 3: Try applying the XOR operation to each node's subtree and find the maximum possible sum
        int max_sum = total_sum; // Initialize with the current total sum
        
        for (int i = 1; i <= n; i++) {
            int new_sum = total_sum - subtree_sum[i] + (subtree_sum[i] ^ k);
            max_sum = max(max_sum, new_sum);
        }
        
        cout << max_sum << '\n';
    }
    return 0;
}
