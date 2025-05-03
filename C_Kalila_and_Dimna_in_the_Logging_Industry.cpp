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
    vector<int> a(n), b(n);
    for(int i = 0;i < n; i++) cin >> a[i];
    for(int i = 0;i < n; i++) cin >> b[i];
    



    return 0;
}