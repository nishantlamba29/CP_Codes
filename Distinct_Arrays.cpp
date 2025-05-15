#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 1;
    for(int i=0;i<n;i++) {
        if(v[i] - i > 0)
        ans = (ans * (v[i] - i)) % mod;
        else {
            cout << 0 << '\n';
            return;
        }
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