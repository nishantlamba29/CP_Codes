#include "bits/stdc++.h"
using namespace std;
#define int long long

const int N = 1e5;
const int mod = 1e9+7;
int par[N+1], sz[N+1];

int powr(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) 
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int find(int x){
    return x == par[x] ? x : find(par[x]);
}

bool merge(int u, int v){
    int p1 = find(u), p2 = find(v);
    if(p1 == p2) return 0;
    if(sz[p1] > sz[p2]) swap(p1, p2);
    par[p1] = p2;
    sz[p2] += sz[p1];
    return 1;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;

    for(int i=0;i<=n;i++) {
        par[i] = i;
        sz[i] = 1;
    }

    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(w == 0) merge(u, v);
    }
    int ans1 = 0;
    for(int i=1;i<=n;i++){
        if(par[i] == i){
            ans1 = (ans1 + sz[i] - powr(sz[i], k) + mod) % mod;
        }
    }
    int ans = (powr(n, k) - n + ans1 + mod) % mod;

    cout<<ans;

}