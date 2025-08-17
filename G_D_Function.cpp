#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

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

    int _;
    cin >> _;
    while (_-->0) {
        int l, r, k;
        cin >> l >> r >> k;

        int p = (10 + k - 1) / k;
        int t1 = modpowr(p, l);
        int t2 = (modpowr(p, r - l) - 1 + mod) % mod;
        int ans = (t1 * t2) % mod;
        cout << ans << "\n";
        
    }


    return 0;
}