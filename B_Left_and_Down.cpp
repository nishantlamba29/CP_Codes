#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int a, b, k;
    cin >> a >> b >> k;
    int g = __gcd(a, b);
    a /= g, b /= g;
    if(a != b) {
        if(a <= k && b <= k) cout << "1\n";
        else cout << "2\n";
    }
    else {
        cout << "1\n";
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