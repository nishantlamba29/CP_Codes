#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<pair<int,int>> q, q2;
    q.push_back({0, 0});
    string ans;
    ans += v[0][0];
    for(int i=1;i<2*n-1;i++) {
        int sz = q.size();
        char best = 'Z';
        for(int j=0;j<sz;j++) {
            auto [x, y] = q[j];
            if(x + 1 < n) best = min(best, v[x+1][y]);
            if(y + 1 < n) best = min(best, v[x][y+1]);
        }
        ans.push_back(best);

        for(int j=0;j<sz;j++) {
            auto [x, y] = q[j];
            if(x + 1 < n && !vis[x+1][y] && v[x+1][y] == best) {
                vis[x+1][y] = 1;
                q2.push_back({x+1, y});
            }
            if(y + 1 < n && !vis[x][y+1] && v[x][y+1] == best) {
                vis[x][y+1] = 1;
                q2.push_back({x, y + 1});
            }
        }

        q = q2;
        q2.clear();

    }

    cout << ans << "\n";

    return 0;
}