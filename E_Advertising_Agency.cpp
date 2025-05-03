#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = (int)1e9 + 7;

int modpowr(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1LL) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1LL;
    }
    return res;
}

int modnCr(int n, int r) {
    if(n < r) return 0;
    if(r > n - r) r = n - r;
    int num = 1, denom = 1;
    for(int i=0;i<r;i++) {
        num = (num * (n - i)) % mod;
        denom = (denom * (i + 1)) % mod;
    }
    return (num * modpowr(denom, mod - 2)) % mod;
}

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    vector<int> v(n), freq(n+1, 0);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        freq[v[i]]++;
    }

    sort(v.rbegin(), v.rend());

    int a = v[k-1];
    int cnt = count(v.begin(), v.begin() + k, a);
    int total = freq[a];

    int ans = modnCr(total, cnt);

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