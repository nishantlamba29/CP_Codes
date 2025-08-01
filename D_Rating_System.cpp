#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int ans = 0, sum = 0, mx = 0, delta = 0;
    for(int i=0;i<n;i++) {
        sum += v[i];
        mx = max(mx, sum);
        if(sum - mx < delta) {
            delta = sum - mx;
            ans = mx;
        }
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