#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    vector<int> c1(60, 0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<60;j++) {
            if(v[i] >> j & 1) c1[j]++;
        }
    }
        
    vector<int> g(n);
    // g[1] = v1|v1 + v1|v2 + v1|v3 ...
    for(int i=0;i<n;i++) {
        int sum = 0;
        for(int j=0;j<60;j++) {
            int p = (1LL << j);
            p %= mod;
            if(v[i] >> j & 1) {
                sum = (sum + (n * p) % mod) % mod;
            }
            else {
                sum = (sum + (c1[j] * p) % mod) % mod;
            }
        }
        g[i] = sum;
    }
    
    vector<int> f(n);
    // f[1] = v1&v1 + v1&v2 + v1&v3 ...
    for(int i=0;i<n;i++) {
        int sum = 0;
        for(int j=0;j<60;j++) {
            int p = (1LL << j);
            p %= mod;
            if(v[i] >> j & 1) {
                sum = (sum + (c1[j] * p) % mod) % mod;
            }
        }
        f[i] = sum;
    }
    
    int res = 0;
    for(int i=0;i<n;i++) {
        int prod = (f[i] * g[i]) % mod;
        res = (res + prod) % mod;
    }
    
    cout << res << "\n";
    
    
}
int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
