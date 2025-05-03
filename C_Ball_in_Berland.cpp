#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k), b(k);
    for(int i=0;i<k;i++) cin >> a[i];
    for(int i=0;i<k;i++) cin >> b[i];

    vector<int> f1(n+1, 0), f2(m+1, 0);
    
    for(int i=0;i<k;i++) {
        f1[a[i]]++;
        f2[b[i]]++;
    }

    int ans = 0;

    for(int i=0;i<k;i++) {
        ans += k - f1[a[i]] - f2[b[i]] + 1;
    }

    cout << ans / 2 << "\n";

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