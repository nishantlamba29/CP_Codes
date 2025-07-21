#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k;
vector<vector<int>> grid;
int mid;
map<int, int> path[20][20];
int ans;

void dfs(int i, int j, int curr, int steps) {
    if(steps == mid) {
        path[i][j][curr]++;
        return;
    }
    if(i + 1 < n) dfs(i+1, j, curr ^ grid[i+1][j], steps + 1);
    if(j + 1 < m) dfs(i, j+1, curr ^ grid[i][j+1], steps + 1);
}

void dfs2(int i, int j, int curr, int steps) {
    if(steps == n + m - 2 - mid) {
        ans += path[i][j][curr^k^grid[i][j]];
        return;
    }
    if(i - 1 >= 0) dfs2(i-1, j, curr ^ grid[i-1][j], steps + 1);
    if(j - 1 >= 0) dfs2(i, j-1, curr ^ grid[i][j-1], steps + 1);
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    grid.resize(n, vector<int>(m));
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++) cin >> grid[i][j];
    
    mid = (m + m - 2) / 2;

    ans = 0;
    dfs(0, 0, grid[0][0], 0);
    dfs2(n-1, m-1, grid[n-1][m-1], 0);

    cout << ans << "\n";

    return 0;
}