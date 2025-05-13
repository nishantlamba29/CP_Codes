#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int a, b, c;
    cin >> a >> b >> c;
    if(c != a + 1) {
        cout << -1 << "\n";
        return;
    }
    int t1 = __lg(a);
    int ht = t1 + 1;
    int rem = (1LL << (t1 + 1)) - 1 - a;
    if(b >= rem) b -= rem;
    else {
        cout << ht << "\n";
        return;
    }
    int val = (b+a) / (a+1);
    cout << ht + val << "\n";



}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}