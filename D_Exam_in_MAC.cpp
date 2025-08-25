#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    int ans = 0, t1 = 0, t2 = 0;
    for(int i=0;i<n;i++) {
        ans += v[i] / 2 + 1;
        ans += (c - v[i] + 1);
        if(v[i] & 1) t1++;
        else t2++;
    }
    int both = t1 * (t1 + 1) / 2 + t2 * (t2 + 1) / 2;
    ans -= both;

    int res = (c + 1) * (c + 2) / 2 - ans;
    cout << res << "\n";

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