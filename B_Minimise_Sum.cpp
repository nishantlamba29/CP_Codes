#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> pre = v;
    for(int i=1;i<n;i++) pre[i] = min(pre[i], pre[i-1]);

    int curr = accumulate(pre.begin(), pre.end(), 0LL);

    int mini = 2 * n, sum = 0, ans = curr;
    for(int i=0;i<n-1;i++) {
        int m2 = min(mini, v[i] + v[i+1]);
        ans = min(ans, sum + m2);
        mini = min(mini, v[i]);
        sum += mini;
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