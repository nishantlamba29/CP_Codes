#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(c >= d && a >= b) cout << "Gellyfish\n";
    else if(c >= d && a < b) {
        if(a >= d) cout << "Gellyfish\n";
        else cout << "Flower\n";
    }
    else if(c < d) {
        if(a >= b && c >= b) cout << "Gellyfish\n";
        else cout << "Flower\n";
    }
    else cout << "Flower\n";

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