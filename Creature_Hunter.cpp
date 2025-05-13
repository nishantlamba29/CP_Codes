#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, h;
    cin >> n >> h;
    int best1 = 0, best2 = 0;
    for(int i=0;i<n;i++){
        int s, d;
        cin >> s >> d;
        if(s == 1) best1 = max(best1, d);
        else best2 = max(best2, d);
    }
    int ans = INT_MAX;
    if(best1 > 0) {
        ans = (h + best1 - 1) / best1;
    }
    if(best2 > 0) {
        int q = h / best2;
        int rem = h - q * best2;
        int time = 2*q;
        if(rem > 0) {
            if(best1 > 0 && rem <= best1) time++;
            else time += 2;
        }
        ans = min(ans, time);
    }
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