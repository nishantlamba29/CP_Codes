#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> pre(n), suff(n);
    pre[0] = v[0];
    for(int i=1;i<n;i++) pre[i] = max(pre[i-1], v[i] + i);
    suff[n-1] = v[n-1] - (n-1);
    for(int i=n-2;i>=0;i--) {
        suff[i] = max(suff[i+1], v[i] - i);
    }

    int ans = 0;
    for(int i=0;i+2<n;i++) {
        ans = max(ans, pre[i] + suff[i+2] + v[i+1]);
    }

    cout << ans << "\n";

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        solve();
    }

    return 0;
}