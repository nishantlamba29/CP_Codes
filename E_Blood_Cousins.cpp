#include "bits/stdc++.h"
using namespace std;
#define int long long

const int N = 100000;
int n, q, depth[N+1], par[N+1][20], T = 1, tin[N+1], vis[N+1], sz[N+1];
vector<int> tree[N+1], arr[N+1];

void dfs(int node = 1, int p = 1, int d = 0){
    tin[node] = T;
    par[T][0] = tin[p];
    depth[T] = d;
    vis[node] = 1;
    sz[T] = 1;
    for(int i=1;i<20;i++){
        par[T][i] = par[par[T][i-1]][i-1];
    }
    T++;
    for(auto &j : tree[node]){
        dfs(j, node, d + 1);
        sz[tin[node]] += sz[tin[j]];
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        tree[x].push_back(i+1);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            dfs(i);
        }
    }

    for(int i=1;i<=n;i++){
        arr[depth[i]].push_back(i);
    }

    cin>>q;
    for(int i=0;i<q;i++){
        int v, p;
        cin >> v >> p;
        v = tin[v];
        int dd = depth[v];
        if(dd < p){
            cout<<"0 ";
            continue;
        }
        for(int i=19;i>=0;i--){
            if(p >> i & 1){
                v = par[v][i];
            }
        }

        int cnt = upper_bound(arr[dd].begin(), arr[dd].end(), v + sz[v] - 1) - lower_bound(arr[dd].begin(), arr[dd].end(), v);
        
        cout<<cnt-1<<" ";
    }

    return 0;
}