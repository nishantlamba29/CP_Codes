#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());

    if(n <= 2) {
        cout << 0 << "\n";
        return;
    }
    int ans = (n - 2) * (v[n-1] - v[0]) + (n - 3) * (v[n-2] - v[1]);
    for(int i=2;i<n-2;i++) {
        ans += (v[i] * (2 * i + 1 - n));
    }

    cout << -1LL*ans << "\n";

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