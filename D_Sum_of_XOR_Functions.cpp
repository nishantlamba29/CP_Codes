#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n + 1), pre(n + 1);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        pre[i] = pre[i-1] ^ v[i];
    }

    // first solve
    // https://atcoder.jp/contests/abc365/tasks/abc365_e

    // (p[r] | p[l] - p[r] & p[l]) * (r-l);
    // (p[r]|p[l])*r - (p[r]|p[l])*l - (p[r]&p[l])*r + (p[r]&p[l])*l

    int ans = 0;
    vector<int> l1(31, 0);
    // first sweeping for r
    // calculating (p[r]|p[l])*r - (p[r]&p[l])*r
    for(int r = 1; r <= n; r++) {
        int sum = 0;
        for(int j=0;j<30;j++) {
            if(pre[r] >> j & 1) {
                // ans += (1 << j) * r * r;
                sum = (sum + ((1 << j) * r) % mod) % mod;
                // ans -= (1 << j) * l1[j] * r;
                sum = (sum - ((1 << j) * l1[j]) % mod + mod) % mod;
            }
            else {
                // ans += (1 << j) * l1[j] * r;
                sum = (sum + ((1 << j) * l1[j]) % mod) % mod;
            }
        }
        ans = (ans + (sum * r) % mod) % mod;
        for(int j=0;j<30;j++) {
            if(pre[r] >> j & 1) l1[j]++;
        }
    }

    // then sweeping for l
    // calculating (p[r]|p[l])*l - (p[r]&p[l])*l
    // l*(pre[r] ^ pre[l])
    // a^b = a|b - a&b
    // l * ((p[r] | p[l])   -   (p[r] & p[l]))
    vector<int> l2(30, 0);
    for(int l = n; l >= 0; l--) {
        int sum = 0;
        for(int j=0;j<30;j++) {
            if(pre[l] >> j & 1) {
                // ans -= (1 << j) * (n - l) * l;
                sum = (sum + ((1 << j) * (n - l)) % mod) % mod;
                // ans += (1 << j) * l2[j] * l;
                sum = (sum - ((1 << j) * l2[j]) % mod) % mod;
            }
            else {
                // ans -= (1 << j) * l2[j] * l;
                sum = (sum + ((1 << j) * l2[j]) % mod) % mod;
            }
        }
        ans = (ans - (sum * l) % mod + mod) % mod;
        for(int j=0;j<30;j++) {
            if(pre[l] >> j & 1) l2[j]++;
        }
    }

    cout << ans << "\n";


}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    n_lamba_29();
    return 0;
}