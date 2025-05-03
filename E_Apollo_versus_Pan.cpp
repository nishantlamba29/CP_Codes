#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9 + 7;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        sum = (sum + v[i]) % mod;
    }
    vector<int> f(61, 0);
    for(int i=0;i<n;i++) {
        int x = v[i];
        for(int j=0;j<60;j++) {
            if(x >> j & 1LL) {
                f[j]++;
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) {
        int sn = 0;
        for(int j=0;j<60;j++) {
            if(v[i] >> j & 1LL)
            sn = (sn + (((1LL << j) % mod) * f[j]) % mod) % mod;
        }

        int temp = ((((n * (v[i] % mod)) % mod + sum - sn + mod ) % mod ) * sn ) % mod;
        ans = (ans + temp) % mod;
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