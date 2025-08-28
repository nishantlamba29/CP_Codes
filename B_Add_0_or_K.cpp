#include <bits/stdc++.h>
using namespace std;
#define int long long

void print(vector<int> &v) {
    for(int i : v) cout << i << " ";
    cout << "\n";
}

int modpowr(int a, int b, int mod) {
    int res = 1;
    while(b > 0) {
        if(b & 1LL) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1LL;
    }
    return res;
}

inline void n_lamba_29() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];


    auto check = [&](int p) {
        for(int i=0;i<n;i++) {
            int lem = ((((-v[i] % p) + p) % p) * modpowr(k, p - 2, p)) % p;
            if(lem > k) return 0;
        }
        for(int i=0;i<n;i++) {
            int lem = ((((-v[i] % p) + p) % p) * modpowr(k, p - 2, p)) % p;
            v[i] += lem * k;
        }
        return 1;
    };

    int p = -1;
    int ele = k + 1;
    for(int i=2;i*i<=ele; i++) {
        if(ele % i == 0) {
            while(ele % i == 0) {
                ele /= i;
            }
            if(check(i)) {
                print(v);
                return;
            }
        }
    }
    if(ele > 1 && check(ele)) print(v);

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