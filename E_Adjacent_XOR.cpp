#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    if(a[n-1] != b[n-1]) {
        cout << "NO\n";
        return;
    }

    for(int i=0;i<n-1;i++) {
        if(a[i] == b[i]) continue;
        if((a[i] ^ a[i+1]) == b[i]) {
            a[i] ^= a[i+1];
        }
    }

    for(int i=n-2;i>=0;i--) {
        if(a[i] == b[i]) continue;
        a[i] ^= a[i+1];
        if(a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

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