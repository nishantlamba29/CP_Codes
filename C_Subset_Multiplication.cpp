#include <bits/stdc++.h>
using namespace std;
#define int long long

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    int g = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        g = __gcd(g, v[i]);
    }
    for(int i=0;i<n;i++) v[i] /= g;
    int lc = 1;
    for(int i=0;i<n-1;i++) {
        int gg = __gcd(v[i], v[i+1]);
        lc = lcm(lc, v[i] / gg);
    }
    cout << lc << "\n";

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