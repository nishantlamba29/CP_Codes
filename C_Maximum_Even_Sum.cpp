#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int a, b;
    cin >> a >> b;
    if(a % 2 == 1 && b % 2 == 1) {
        cout << a * b + 1 << "\n";
    }
    else if(a % 2 == 1 || b % 2 == 1) {
        if(a % 2 == 1) {
            int val = b / 2;
            int res = a * val + 2;
            if(res & 1) cout << "-1\n";
            else cout << res << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    else {
        int val = b / 2;
        cout << a * val + 2 << "\n";
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