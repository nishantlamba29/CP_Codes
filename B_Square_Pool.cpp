#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void n_lamba_29() {

    int n, s;
    cin >> n >> s;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        int a = (dx * x + s) % s;
        int b = (dy * y + s) % s;
        if(a == b) cnt++;
    }
    cout << cnt << "\n";

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