#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    int ans = (n/2) * (n/2) + (n&1);
    if(n%2 == 0) {
        cout << ans + 1 << "\n";
    } else {
        cout << ans + n/2 << "\n";      
    }

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