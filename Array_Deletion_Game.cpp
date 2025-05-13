#include <bits/stdc++.h>
using namespace std;
class DSU {
    public:
    vector<int> par;
    DSU(int n){
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        return x == par[x] ? x : find(par[x]);
    }
    void merge(int u, int v) {
        par[v] = u;
    }
};
    
inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(2*n);
    for(int i=0;i<2*n;i++) cin >> v[i];
    DSU ds(n);
    vector<pair<int,int>> job;
    int j = 1;
    for(int i=0;i<2*n;i+=2) {
        job.push_back({v[i], j});
        job.push_back({v[i+1], j++});
    }
    sort(job.begin(), job.end(), [&](const pair<int,int> &a, const pair<int,int> &b) {
        return a.first > b.first;
    });

    int ans = 0;
    for(int i=0;i<2*n;i++) {
        int slot = ds.find(job[i].second);
        if(slot > 0) {
            ans += job[i].first;
            ds.merge(ds.find(slot - 1), slot);
        }
    }
    cout << ans << '\n';

}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}