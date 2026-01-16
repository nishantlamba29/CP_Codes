#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

// E_Stronger_Takahashi
// D_Wizard_in_maze

template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
// L R D U

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);

    min_heap<array<int, 5>> pq;
    vector<vector<vector<vector<int>>>> dist(n + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(5, vector<int>(5, inf))));

    int ex, ey;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        for(int j=0;j<m;j++) {
            if(v[i][j] == 'S') {
                pq.push({0, i, j, -1, 0});
                dist[i][j][0][0] = 0;
            }
            else if(v[i][j] == 'T') {
                ex = i;
                ey = j;
            }
        }
    }

    while(pq.size()) {
        auto [d, x, y, dir, units] = pq.top();
        pq.pop();
        if(x == ex && y == ey) {
            cout << d << "\n";
            return;
        }
        if(d > dist[x][y][dir + 1][units]) continue;
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(v[nx][ny] == '#') continue;

            if(i == dir) {
                int cost = 1;
                if(units == 3) {
                    cost = 3;
                    units = 1;
                }
                if(dist[nx][ny][i+1][units + 1] > d + cost) {
                    dist[nx][ny][i+1][units + 1] = d + cost;
                    pq.push({dist[nx][ny][i+1][units + 1], nx, ny, i, units + 1});
                }
            }
            else {
                if(dist[nx][ny][i+1][1] > d + 1) {
                    dist[nx][ny][i+1][1] = d + 1;
                    pq.push({dist[nx][ny][i+1][1], nx, ny, i, 1});
                }
            }
        }
    }
    
    cout << -1 << '\n';


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