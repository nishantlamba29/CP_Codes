#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful
#define int long long
const int mod = 1e9 + 7;

int modpowr(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    map<int, int> mp;
    for(int i=0;i<n;i++) mp[v[i]]++;

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();

    int ans = 0;
    int curr = 1;   
    for(int i=0;i<n;i++) {
        (curr *= mp[v[i]]) %= mod;
        if(i-m+1 >= 0) {
            if(v[i] - v[i-m+1] == m - 1) (ans += curr) %= mod;
            (curr *= modpowr(mp[v[i-m+1]], mod - 2)) %= mod;
        }
    }

    cout << ans << "\n";

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        solve();
    }

    return 0;
}