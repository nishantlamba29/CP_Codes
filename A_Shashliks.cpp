#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    int K = k;
    int ans = 0;
    if(k >= a) {
        int temp = (k - a) / x + 1;
        ans += temp;
        k -= x * temp;
    }
    if(k >= b) {
        int temp = (k - b) / y + 1;
        ans += temp;
    }
    int ans2 = 0;
    k = K;
    if(k >= b) {
        int t = (k - b) / y + 1;
        ans2 += t;
        k -= y * t;
    }
    if(k >= a) {
        int t = (k - a) / x + 1;
        ans2 += t;
    }
    cout << max(ans, ans2) << "\n";

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