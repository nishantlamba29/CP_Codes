#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> suff(n+1, 0), t(n);
    t[0] = v[0];
    for(int i=1;i<n;i++) {
        t[i] = max(t[i-1], v[i]);
    } 
    suff[n - 1] = v[n - 1];
    for(int i=n-2;i>=0;i--) {
        suff[i] = suff[i+1] + v[i];
    }
    for(int i=n-1;i>=0;i--) {
        cout << suff[i+1] + t[i] << " ";
    }
    cout << "\n";


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