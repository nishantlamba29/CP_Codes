#include "bits/stdc++.h"
using namespace std;

// DFS function to find the farthest node and the maximum distance
pair<int, int> dfs(int node, int parent, vector<int> adj[]) {
    pair<int, int> farthest = {node, 0}; // {node, distance}
    
    for (auto &neighbor : adj[node]) {
        if (neighbor != parent) {
            pair<int, int> temp = dfs(neighbor, node, adj);
            temp.second += 1; // Increment distance
            
            // Update farthest node if a longer distance is found
            if (temp.second > farthest.second) {
                farthest = temp;
            }
        }
    }
    
    return farthest;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // Adjacency list for the tree
    vector<int> adj[n + 1]; // 1-based indexing
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // First DFS: Find the farthest node from node 1
    pair<int, int> firstDFS = dfs(1, -1, adj);

    // Second DFS: Find the farthest distance from the node found in the first DFS
    pair<int, int> secondDFS = dfs(firstDFS.first, -1, adj);

    // The second DFS gives the diameter of the tree
    cout << secondDFS.second << "\n";

    return 0;
}
