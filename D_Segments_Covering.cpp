#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
int modpowr(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1LL) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1LL;
    }
    return res;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> help[m+1];

    int prob = 1;
    for(int i=0;i<n;i++) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;

        int temp = (q - p + mod) % mod;

        prob = (prob * temp) % mod;
        prob = (prob * modpowr(q, mod - 2)) % mod;

        int wt = (p * modpowr(temp, mod - 2)) % mod;
        help[r].push_back({l, wt});

    }

    vector<int> dp(m+1, 0);
    dp[0] = 1;
    for(int i=1;i<=m;i++) {
        int sum = 0;
        for(auto &[l, wt] : help[i]) {
            sum = (sum + dp[l-1] * wt) % mod;
        }
        dp[i] = sum;
    }

    int ans = (prob * dp[m]) % mod;
    cout << ans << "\n";


    return 0;
}