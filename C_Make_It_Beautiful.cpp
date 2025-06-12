#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> need(n, vector<int>(62));

    for(int i=0;i<n;i++) {
        for(int j=0;j<62;j++) {
            if(v[i] >> j & 1) need[i][j] = 0;
            else need[i][j] = (1LL << j);
        }
    }

    for(int bit=0;bit<62;bit++) {
        for(int i=0;i<n;i++) {
            int req = need[i][bit];
            if(req == 0) continue;
            if(k >= req) {
                k -= req;
                v[i] |= req;
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) {
        int cnt = __builtin_popcountll(v[i]);
        ans += cnt;
    }

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