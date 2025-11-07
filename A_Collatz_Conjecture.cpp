#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int k, x;
    cin >> k >> x;

    int val = 1;
    for(int i=0;i<k;i++) val *= 2;
    cout << val * x << "\n";


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