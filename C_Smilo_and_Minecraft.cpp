#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) {
        cin >> grid[i];
    }

    vector<vector<int>> pre(n+1, vector<int>(m+1, 0));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            pre[i][j] = (grid[i-1][j-1] == 'g') + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] != '.') continue;
            int x1 = max(0, i - k + 1);
            int y1 = max(0, j - k + 1);
            int x2 = min(n - 1, i + k - 1);
            int y2 = min(m - 1, j + k - 1);
            int gold = pre[x2 + 1][y2 + 1] - pre[x1][y2 + 1] - pre[x2 + 1][y1] + pre[x1][y1];
            ans = max(ans, pre[n][m] - gold);
        }
    }

    cout << ans << "\n";

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