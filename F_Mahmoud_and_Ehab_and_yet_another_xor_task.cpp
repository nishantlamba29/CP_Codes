#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1'000'000'007;

int modpowr(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1LL) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1LL;
    }
    return res;
}

const int d = 21;
int basis[d];
int sz;

void insert(int mask) {
    for(int i=d-1;i>=0;i--) {
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

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<array<int,3>> query;
    for(int i=0;i<q;i++) {
        int l, x;
        cin >> l >> x;
        l--;
        query.push_back({l, x, i});
    }
    sort(query.begin(), query.end());
    vector<int> res(q);
    int i = 0;
    for(auto &[l, x, ind] : query) {
        while(i <= l) {
            insert(v[i]);
            i++;
        }
        bool flag = 1;
        for(int j=d-1;j>=0;j--) {
            if(!(x >> j & 1)) continue;
            if(!basis[j]) {
                flag = 0;
                break;
            }
            x ^= basis[j];
        }
        int ans = 0;
        if(flag) ans = modpowr(2, l + 1 - sz);
        res[ind] = ans;
    }

    for(int i=0;i<q;i++) cout << res[i] << '\n';

    return 0;
}