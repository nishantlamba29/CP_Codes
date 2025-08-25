#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int dp[N], fact[N], ifact[N];

int modpowr(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int nCr(int n, int r) {
    if(r > n) return 0;
    int num = fact[n];
    num = (num * ifact[r]) % mod;
    num = (num * ifact[n-r]) % mod;
    return num;
}

// rC0 pow(r, n) - rC1 pow(r-1, n) + rC2 pow(r-2, n) - rC3 pow(r-3, n) + ...
int fun(int r, int n) { // r colors in n boxes
    int ans = 0;
    for(int i=0;i<r;i++) {
        int val = (nCr(r, i) * modpowr(r - i, n)) % mod;
        if(i % 2 == 0) ans = (ans + val) % mod;
        else ans = (ans - val + mod) % mod;
    }
    return ans;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fact[0] = 1;
    for(int i=1;i<N;i++) {
        fact[i] = (i * fact[i-1]) % mod;
    }
    ifact[N-1] = modpowr(fact[N-1], mod - 2);
    for(int i=N-2;i>=0;i--) {
        ifact[i] = (ifact[i+1] * (i+1)) % mod;
    }

    int n, m, k;
    cin >> n >> m >> k;

    if(m == 1) {
        cout << modpowr(k, n) << "\n";
        return 0;
    }
    // dp[i]  ->  i colors in n boxes
    for(int i=1;i<=min(n, k);i++) {
        dp[i] = fun(i, n);
    }

    int ans = 0;
    for(int i=1;i<=min(n, k);i++) {
        for(int j=0;j<=i;j++) { // j colors common in 1st and mth column
            int ways = nCr(k, i); // select i out of k
            ways = (ways * nCr(i, j)) % mod; // select j out of i
            ways = (ways * dp[i]) % mod; // 1st column
            ways = (ways * dp[i]) % mod; // mth column
            ways = (ways * nCr(k-i, i-j)) % mod; // j common in 1st and mth so i-j not common so selecting i-j from k-i
            ways = (ways * modpowr(j, n*(m-2))) % mod; // m-2 columns filled with common j colors
            ans = (ans + ways) % mod;
        }
    }

    cout << ans << "\n";




    return 0;
}