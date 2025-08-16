#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> a(n + 2), b(n + 2);
    for(int i=0;i<n;i++) cin >> a[i+1];
    for(int i=0;i<n;i++) cin >> b[i+1];
    
    if(a[n] != b[1]) {
        cout << "NO\n";
        return;
    }
    for(int i=2;i<=n;i++) {
        if(a[i-1] % a[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    for(int i=n-1;i>0;i--) {
        if(b[i+1] % b[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    for(int i=0;i<=n;i++) {
        if(gcd(a[i], b[i+1]) != b[1]) {
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