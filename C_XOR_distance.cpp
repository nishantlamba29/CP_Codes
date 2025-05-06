#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int a, b, r;
    cin >> a >> b >> r;
    if(a > b) swap(a, b);
    vector<int> pos;
    for(int i=60;i>=0;i--) {
        if((a >> i & 1) != (b >> i & 1)) {
            pos.push_back(i);
        }
    }
    int x = 0;
    for(int i=1;i<pos.size();i++) {
        if(x + (1LL << pos[i]) <= r && (!(a >> pos[i] & 1) )) {
            x += (1LL << pos[i]);
        }
    }
    int ans = (b^x) - (a^x);
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