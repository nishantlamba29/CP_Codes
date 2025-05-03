#include "bits/stdc++.h"
using namespace std;

#define int long long

struct sop2 {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void sop(){
    int n;
    cin>>n;
    vector<int> val(n+1);
    for(int i=0;i<n;i++) cin>>val[i+1];
    unordered_map<int, unordered_map<int,int, sop2>, sop2> g;
    vector<pair<int,int>> edges;
    string ans(n, '0');
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        if(val[u] == val[v]) ans[val[u]-1] = '1';
        else edges.push_back({u,v});
        g[u][val[v]]++;
        g[v][val[u]]++;
    }
    for(auto &[u, v] : edges){
        if(g[v][val[u]] > 1) ans[val[u]-1] = '1';
        if(g[u][val[v]] > 1) ans[val[v]-1] = '1';
    }
    cout<<ans<<"\n";

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--) sop();
    return 0;

}