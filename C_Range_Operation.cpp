#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e17;

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n + 1), pre(n + 1);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        pre[i] = pre[i-1] + v[i];
    }

    int mx = 0;
    int mn = inf;
    for(int i=1;i<=n;i++) {
        int t1 = 1LL*i*i + i - pre[i];
        int t2 = 1LL*i*i - i - pre[i-1];
        mn = min(mn, t2);
        mx = max(mx, t1 - mn);
    }

    int ans = pre[n] + mx;
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