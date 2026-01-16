#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, x;
    cin >> n >> x;
    if((n & x) != x) {
        cout << "-1\n";
        return;
    }
    int mone = (1LL << 62);
    int mzero = n;
    // n & (n + 1) & (n + 2) .. t = x 
    // for any ith bit finding the smallest t
    for(int i=0;i<63;i++) {
        int bit = (1LL << i);

        // ith bit remains 2^i times 0 and 2^i times 1, repeats in cycle of 2^(i+1)
        // (n / 2^(i+1)) * 2^(i+1)
        int start = (n >> (i+1)) << (i+1);

        int mi; // mi = t
        if(n & bit) {
            mi = start + (1LL << (i + 1));
        }
        else mi = n;
        
        if(x & bit) { // this bit must not be flipped
            mone = min(mone, mi);
        }
        // if this bit is set in n , we have to make it flip we need t >= n satisfying this
        // therefore taking max over all bits
        else mzero = max(mzero, mi);

    }

    if(mzero < mone) cout << mzero << "\n";
    else cout << "-1\n";

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