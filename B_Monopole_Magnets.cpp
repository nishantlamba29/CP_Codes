#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, m;
vector<string> grid;
vector<int> par, sz;

int find(int x){
    return x == par[x] ? x : find(par[x]);
}
bool merge(int u, int v) {
    int p1 = find(u), p2 = find(v);
    if (p1 == p2) return 0;
    if (sz[p1] < sz[p2]) swap(p1, p2);
    par[p2] = p1;
    sz[p1] += sz[p2];
    return 1;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++) cin>>grid[i];

    vector<int> row(n), col(m);
    bool flag = 1;
    for(int i=0;i<n;i++){
        int cnt = 0, st = n, end = -1;
        for(int j=0;j<m;j++){
            if(grid[i][j] == '#'){
                st = min(st, j);
                end = max(end,j);
            }
        }
        if(st != n){
            for(int j = st;j<=end;j++){
                if(grid[i][j] == '#') cnt++;
            }
            if(cnt != end - st + 1){
                flag = 0;
                break;
            }
        }
    }
    for(int j=0;j<m;j++){
        int cnt = 0, st = n, end = -1;
        for(int i=0;i<n;i++){
            if(grid[i][j] == '#'){
                st = min(st, i);
                end = max(end,i);
            }
        }
        if(st != n){
            for(int i = st;i<=end;i++){
                if(grid[i][j] == '#') cnt++;
            }
            if(cnt != end - st + 1){
                flag = 0;
                break;
            }
        }
    }
    if(flag == 0){
        cout<<-1;
        return 0;
    }

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<m;j++) cnt += (grid[i][j] == '.');
        row[i] = cnt;
    }
    for(int j=0;j<m;j++){
        int cnt = 0;
        for(int i=0;i<n;i++) cnt += (grid[i][j] == '.');
        col[j] = cnt;
    }
    int cnt = 0, cnt2 = 0;
    for(int i=0;i<n;i++) cnt += (row[i] == m);
    for(int j=0;j<m;j++) cnt2 += (col[j] == n);

    if((cnt == 0 && cnt2 != 0) || (cnt2 == 0 && cnt != 0)){
        cout<<-1;
        return 0;
    }

    int total = n*m;
    par.resize(total);
    iota(par.begin(), par.end(), 0);
    sz.assign(total, 1);

    for(int i=0;i<total;i++){
        int x = i / m, y = i % m;
        if(grid[x][y] == '.') continue;
        if(x + 1 < n && grid[x+1][y] == '#') merge(i, (x + 1) * m + y);
        if(y + 1 < m && grid[x][y+1] == '#') merge(i, x * m + y + 1);
    }

    int ans = 0;
    for(int i=0;i<total;i++){
        if(grid[i/m][i%m] == '#' && i == par[i]) {
            ans++;
        }
    }

    cout<<ans;

    return 0;
}