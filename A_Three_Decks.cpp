#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int a, b, c;
    cin >> a >> b >> c; 
    int sum = a + b + c;
    if(sum % 3 != 0) {
        cout << "NO\n";
    }
    else if(a > sum / 3 || b > sum / 3) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
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