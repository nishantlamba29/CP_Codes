#include <bits/stdc++.h>
using namespace std;
#define int long long

int P[] = {2, 3, 5, 7};

int rec(int n) {
    int res = n;
    for(int mask=1;mask < (1 << 4); mask++) {
        int t1 = 1, cnt = 0;
        for(int i=0;i<4;i++) {
            if(mask >> i & 1) {
                t1 *= P[i];
                cnt++;
            }
        }
        if(cnt & 1) res -= n / t1;
        else res += n / t1;
    }
    return res;
}

inline void n_lamba_29() {

    int l, r;
    cin >> l >> r;
    
    int ans = rec(r);
    ans -= rec(l - 1);

    cout << ans << "\n";

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