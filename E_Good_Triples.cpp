#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n;
    cin >> n;
    
    int64_t ans = 1;
    while(n) {
        int r = n % 10;
        ans *= (r+1)*(r+2)/2;
        n /= 10;
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