#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, r2--, c1--, c2--;
    vector<pair<int,int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    auto check = [&](int nx, int ny) {
        return nx >= 0 && ny >= 0 && nx < n && ny < m;
    };

    function<bool(int,int)> dfs = [&](int x, int y) {
        if(v[x][y] == 'X') return x == r2 && y == c2;
        v[x][y] = 'X';
        for(auto &[dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if(check(nx, ny)) {
                if(dfs(nx, ny)) return true;
            }
        }
        return false;
    };
    
    v[r1][c1] = '.';
    if(dfs(r1, c1)) cout << "YES";
    else cout << "NO";


    return 0;
}