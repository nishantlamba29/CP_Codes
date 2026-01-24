#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i=0;i<n;i++) cin >> g[i];

    bool ans = 1, row_empty = 0, col_empty = 0;
    for(int i=0;i<n;i++) {
        int seg = 0;
        int sum = 0;
        for(int j=0;j<m;j++) {
            if(g[i][j] == '#') {
                sum++;
            }   
            else {
                if(sum) seg++;
                sum = 0;
            }
        }
        if(sum) seg++;
        if(seg == 0) row_empty = 1;
        else if(seg > 1) ans = 0;
    }
    for(int j=0;j<m;j++) {
        int seg = 0;
        int sum = 0;
        for(int i=0;i<n;i++) {
            if(g[i][j] == '#') {
                sum++;
            }
            else {
                if(sum) seg++;
                sum = 0;
            }
        }
        if(sum) seg++;
        if(seg == 0) col_empty = 1;
        else if(seg > 1) ans = 0;
    }

    if(!ans || (row_empty != col_empty)) {
        cout << "-1\n";
        return;
    }

    int comp = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    function<void(int, int)> dfs = [&](int x, int y) {
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == '#' && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                dfs(nx, ny);
            }
        }
    };

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(g[i][j] == '#' && !vis[i][j]) {
                vis[i][j] = 1;
                comp++;
                dfs(i, j);
            }
        }
    }

    cout << comp << "\n";


}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int _;
    // cin >> _;
    // while (_-->0) {
        solve();
    // }

    return 0;
}