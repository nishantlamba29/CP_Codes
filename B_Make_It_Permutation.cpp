#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    cout << 2 * n - 2 << "\n";
    for(int i=2;i<=n;i++) {
        cout << i << " " << 1 << " " << i << "\n";
    }
    for(int i=1;i<n;i++) {
        cout << i << " " << i + 1 << " " << n << "\n";
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