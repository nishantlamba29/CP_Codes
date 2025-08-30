// maximum matching
// https://leetcode.com/problems/two-letter-card-game/.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int ans = 0;

int dfs(int node = 0) {
    int unmatched = 1;
    int total = 0;
    int maxi = 0;

    for(auto j : adj[node]) {
        int ch = dfs(j);
        total += ch;
        maxi = max(maxi, ch);
    }

    int pairs = min(total / 2, total - maxi);
    ans += pairs;
    int left = total - 2 * pairs;

    return (unmatched + left);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    dfs();

    cout << ans << "\n";

    return 0;
}