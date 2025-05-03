#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 1e5 + 5;
vector<int> adj[MAX_N];  // Adjacency list for the tree
vector<int> C(MAX_N);    // Skill values of employees
int dp[MAX_N][2];        // dp[node][0] = max sum if node is not chosen, dp[node][1] = max sum if node is chosen
vector<int> height(MAX_N,0);
void dfs(int node){
     for(auto c:adj[node]){
        height[c]=height[node]+1;
     }
}
int main() {
    int N, M;
    cin >> N >> M;
    int z;
    cin>>z;
    if (N == 0) {
        cout << -1 << endl;
        return 0;
    }

    // Reading the tree edges
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Reading the skill values
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
        if (C[i] <= 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Perform DFS from the root (assumed to be node 1)
    dfs(1, -1);

    // The result will be the maximum of choosing or not choosing the root
    int result = max(dp[1][0], dp[1][1]);
    cout << result << endl;

    return 0;
}