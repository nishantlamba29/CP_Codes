#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n, a, b;
    cin >> n >> a >> b;
    bool ans = 1;
    int p1 = n % 2, p2 = a % 2, p3 = b % 2;
    if(p1 == 1) {
        if(p3 == 0) ans = 0;
        if(p2 != p3 && a > b) ans = 0;
    }
    else {
        if(p3 == 1) ans = 0;
        if(p2 != p3 && a > b) ans = 0;
    }

    cout << (ans ? "YES\n" : "NO\n");

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