#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int maxi = 0;
    for(int i=1;i<n;i++) {
        if(v[i] < v[i-1]) {
            maxi = max(maxi, v[i-1] - v[i]);
            v[i] = v[i-1];
        }
    }

    cout << (maxi ? __lg(maxi) + 1 : 0) << "\n";

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