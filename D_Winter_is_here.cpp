#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = (int)1e9 + 7;

int modpowr(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res % mod;
}

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> v(n);
    int maxi = 0;
    for(int i = 0; i < n; i++ ) {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }

    vector<int> f(maxi + 1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j *j <= v[i]; j++) {
            if (v[i] % j == 0) {
                f[j]++;
                if (j * j != v[i]) f[v[i] / j]++;
            }
        }
    }

    vector<int> dp(maxi + 1);
    int ans = 0;
    for(int i = maxi; i >= 2; i--) {
        dp[i] = (f[i] * modpowr(2, f[i] - 1)) % mod;
        for(int j = 2 * i; j <= maxi; j += i) {
            dp[i] = (dp[i] - dp[j] + mod) % mod;
        }
        // dp[i] => sum of all lengths of all clans whose gcd is i
        ans = (ans + (i * dp[i]) % mod ) % mod;
    }

    cout << ans << "\n";

    return 0;
}