#include "bits/stdc++.h"
using namespace std;
#define int long long

class DSU {
public:
    vector<int> par, sz;
    DSU(int n){
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        sz.resize(n + 1, 1);
    }
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
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    DSU ds1(n + 1), ds2(n + 1);

    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(w == 0){
            ds1.merge(u, v);
        }
        else {
            ds2.merge(u, v);
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++){

        int s1 = ds1.sz[ds1.find(i)];
        int s2 = ds2.sz[ds2.find(i)];
        ans += (s1-1)*(s2-1);
        
        if(ds1.par[i] == i){
            int s = ds1.sz[i];
            ans += s*(s-1);
        }
        if(ds2.par[i] == i){
            int s = ds2.sz[i];
            ans += s*(s-1);
        }
    }
    cout<<ans;

    
}