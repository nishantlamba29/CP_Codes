#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    int ans = 0;
    for (int med = 1; med <= 10; med++) {
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) {
            pre[i] = (v[i] >= med) - (v[i] < med);
        }
        map<int, int> mp;
        int lo = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] += pre[i - 1];
            if (v[i] == med) {
                while(lo < i) {
                    mp[pre[lo++]]++;
                }
            }
            ans += mp[pre[i]];
        }
    }

    int res = n * (n + 1) / 2 - ans;
    cout << res << "\n";

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