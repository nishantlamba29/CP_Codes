#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, t, k;
    cin >> n >> t >> k;
    int maxi = -1;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }

    t--;
    if(n-2 + (v[t] == maxi) >= n-k) cout << "YES\n";
    else cout << "NO\n";


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