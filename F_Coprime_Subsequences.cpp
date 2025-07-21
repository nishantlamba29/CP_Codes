#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int modpowr(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    int maxi = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }
    vector<int> f(maxi + 1), g(maxi + 1), g2(maxi + 1);

    for(int i=0;i<n;i++) {
        g[v[i]]++;
    }

    for(int i=1;i<=maxi;i++) {
        for(int j=i;j<=maxi;j+=i) {
            g2[i] += g[j];
        }
    }
    
    for(int i=maxi;i>0;i--) {
        f[i] = (modpowr(2, g2[i]) - 1 + mod) % mod;
        for(int j=2*i;j<=maxi;j+=i) {
            f[i] = (f[i] - f[j] + mod) % mod;
        }
    }

    cout << f[1] << "\n";

    return 0;
}