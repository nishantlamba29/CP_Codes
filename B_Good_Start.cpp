#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    bool flag = 0;
    x1 += a;
    y1 += b;
    if((x2 - x1 >= 0 && (x2 - x1) % a == 0)) flag = 1;
    if((y2 - y1) >= 0 && ((y2 - y1) % b == 0)) flag = 1;

    if(flag) cout << "Yes\n";
    else cout << "No\n";

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