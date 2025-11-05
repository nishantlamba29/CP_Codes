#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
int powr(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int sz;
int basis[30];
void insert(int mask) {
    for(int i=29;i>=0;i--) {
        if(mask >> i & 1) {
            if(!basis[i]) {
                basis[i] = mask;
                sz++;
                return;
            }
            mask ^= basis[i];
        }
    }
}

inline void n_lamba_29() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    sz = 0;
    memset(basis, 0, sizeof(basis));
    for(int i=0;i<n;i++) {
        cin >> v[i];
        insert(v[i]);
    }

    int total = powr(2, sz);
    int repeat = powr(2, n - sz);

    bool flag = 0;
    int cnt = 0;
    for(int i=0;i<30;i++) {
        if(k >> i & 1) {
            if(basis[i]) cnt++;
            else flag = 1;
        }
    }

    int c1 = (powr(2, cnt) - 1 + mod) % mod;
    int c2 = 0;
    if(!flag) {
        c2 = 1;
    }
    int c3 = (((total - c1 + mod) % mod) - c2 + mod) % mod;
    c1 = (c1 * repeat) % mod;
    c2 = (c2 * repeat) % mod;
    c3 = (c3 * repeat) % mod;

    // ans = ( (c1 + c2)2 + (c2 + c3)2  + (c1 + c3)2  - (c12  + c22 + c32) ) % 1000000007
    int ans = powr((c1 + c2) % mod, 2);
    ans = (ans + powr((c2 + c3) % mod, 2)) % mod;
    ans = (ans + powr((c1 + c3) % mod, 2)) % mod;
    ans = (ans - powr(c1, 2) + mod) % mod;
    ans = (ans - powr(c2, 2) + mod) % mod;
    ans = (ans - powr(c3, 2) + mod) % mod;

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