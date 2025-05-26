#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> seg(m);
    for(int i=0;i<m;i++) cin >> seg[i].first >> seg[i].second;

    int q;
    cin >> q;
    vector<int> qu(q);
    for(int i=0;i<q;i++) cin >> qu[i];

    auto check = [&](int mid) {
        vector<int> temp(n+1, 0);
        for(int i=0;i<=mid;i++) {
            temp[qu[i]] = 1;
        }
        for(int i=1;i<=n;i++) temp[i] += temp[i-1];
        for(auto &[l, r] : seg) {
            if(2 * (temp[r] - temp[l - 1]) > r - l + 1) {
                return true;
            }
        }
        return false;
    };

    int lo = 0, hi = q - 1, ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1LL;
        if(check(mid)) {
            ans = mid + 1;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << ans << "\n";


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