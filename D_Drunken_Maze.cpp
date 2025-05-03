#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    queue<vector<int>> q;
    vector<string> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
        for(int j=0;j<m;j++){
            if(v[i][j] == 'S') q.push({i, j, 0});
        }
    }

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    int ans = 0;
    while(q.size()){
        int x = q.front()[0], y = q.front()[1], cnt = q.front()[2];
        q.pop();
        if(cnt == 3) continue;
        for(int k=0;k<4;k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(check(nx, ny, n, m ) && v[nx][ny] != '#' && vis[nx][ny] < 2){
                q.push({nx, ny, })
            }
        }
    }
    
    
    
}