#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
#define vvec vector<vec>
#define rep(n) for(int i=0;i<n;i++)
#define pb push_back
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
const int inf = 0x3f3f3f3f3f3f3f3fLL;

int n;
vvec adj;
vec color, par, sz;
vector<pii> edges;
int get(int x){
    return (x == par[x] ? x : get(par[x]));
}
bool merge(int u, int v){
    int p1 = get(u), p2 = get(v);
    if(p1 == p2) return 0;
    if(sz[p2] > sz[p1]) swap(p1, p2);
    par[p2] = p1;
    sz[p1] += sz[p2];
    return 1;
}

void solve(){
    cin>>n;
    
    vector<int> adj[n+1];

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        edges.pb({x,y});
        adj[x].pb(y);
        adj[y].pb(x);
    }
    color.resize(n+1);
    for(int i=1;i<=n;i++) cin>>color[i];
    par.resize(n+1);
    iota(all(par), 0);
    sz.resize(n+1, 1);
    for(auto &[u,v] : edges){
        if(color[u] == color[v]){
            merge(u, v);
        }
    }
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(auto &j : adj[i]){
            if(color[i] != color[j])
                sum += sz[get(j)];
            else
                sum += (sz[get(j)] - 1);
        }
        if(sum == n-1){
            cout<<"YES\n";
            cout<<i;
            return;
        }
    }
    cout<<"NO";

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

}