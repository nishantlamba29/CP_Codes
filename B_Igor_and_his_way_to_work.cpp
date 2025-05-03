#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
#define vvec vector<vec>
#define rep(n) for(int i=0;i<n;i++)
const int inf = 0x3f3f3f3f3f3f3f3fLL;

int dir[] = {0,1,2,3};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n,m;
vector<string> v;
vector<vvec> vis;

bool check(int nx, int ny){
    return (nx >= 0 && ny >= 0 && nx < n && ny < m);
}

bool dfs(int x, int y, int dir, int turns){
    if(turns > 2) return 0;
    if(v[x][y] == 'T') return 1;
    bool ans = 0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        int new_turns = turns + (dir != i);
        if(check(nx, ny) && v[nx][ny] != '*' && new_turns < vis[nx][ny][i]) {
            vis[nx][ny][i] = new_turns;
            ans |= dfs(nx, ny, i, new_turns);
        }
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    v.resize(n);
    int x = 0, y = 0;
    vis.resize(n, vvec(m, vec(4, inf)));
    rep(n) {
        cin>>v[i];
        for(int j=0;j<m;j++){
            if(v[i][j] == 'S'){
                x = i;
                y = j;
            }
        }
    }
    bool ans = 0;
    for(int i=0;i<4;i++){
        ans |= dfs(x, y, i, 0);
    }
    if(ans) cout<<"YES";
    else cout<<"NO";

}