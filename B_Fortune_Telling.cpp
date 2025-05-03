#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, x, y;
    cin >> n >> x >> y;
    int xr = 0;
    for(int i=0,a;i<n;i++) {
        cin >> a;
        xr ^= a;
    }
    if(xr % 2 == 0) {
        if(x % 2 == y % 2) cout << "Alice\n";
        else cout << "Bob\n";
    }
    else {
        if(x % 2 != y % 2) cout << "Alice\n";
        else cout << "Bob\n";
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