#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, x;
    cin >> n >> x;
    int ans = 0, sum = 0;
    for(int i=0;i<=30;i++) {
        if(x >> i & 1) {
            ans += (1 << i);
            sum++;
        }
    }
    if(n == 1 && sum < 1 ) {
        cout << "-1\n";
        return;
    }
    if(sum < n ) {
        if((n-sum) % 2 == 0) {
            ans += (n - sum);
        }
        else {
            ans += (n - sum - 1);
            if(x == 0 || x == 1) ans += 2 * (1 << 1);
            else ans += 2 * (1 << 0);
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