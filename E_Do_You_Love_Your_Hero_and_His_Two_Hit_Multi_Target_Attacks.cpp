#include <bits/stdc++.h>
using namespace std;
#define int long long

int get(int k) {
    int lo = 0, hi = 500, n = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1LL;
        if(mid*(mid-1) / 2 <= k) {
            n = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return n;
}

inline void n_lamba_29() {
    int k;
    cin >> k;
    if(k == 0) {
        cout << "1\n1 1\n";
        return;
    }
    vector<pair<int,int>> ans;
    int nx = 0, ny = 0;
    while(k > 0) {
        int n = get(k);
        for(int i=0;i<n;i++) {
            ans.push_back({nx + i, ny});
        }
        k -= n*(n-1)/2;
        nx += n;
        ny++;
    }
    cout << ans.size() << "\n";
    for(auto &j : ans) {
        cout << j.first << " " << j.second << "\n";
    }


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