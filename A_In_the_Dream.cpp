#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool ans = 1;
    if(a > b) {
        swap(a, b);
        swap(c, d);
    }
    if(2 * a + 2 < b) ans = 0;
    c -= a;
    d -= b;
    if(c > d) swap(c, d);
    if(2 * c + 2 < d) ans = 0;

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