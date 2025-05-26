#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(2*n);
    for(int i=0;i<2*n;i++) cin >> v[i];

    vector<pair<int,int>> jobs;
    for(int i=0;i<2*n;i++) {
        jobs.push_back({-v[i], (i+1) / 2});
    }

    int64_t total = accumulate(v.begin(), v.end(), 0LL);

    sort(jobs.rbegin(), jobs.rend());
    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);

    function<int(int)> find = [&](int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    };

    auto merge = [&](int u, int v) {
        par[v] = u;
        return;
    };

    int64_t ans = 0;
    for(auto &[value, deadline] : jobs) {
        int slot = find(deadline);
        if(slot > 0) {
            ans += value;
            merge(find(slot - 1), slot);
        }
    }

    cout << total + ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}