#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    string l, r;
    cin >> l >> r;

    int n = l.size();
    int ind = -1;
    for(int i=0;i<n;i++) {
        if(l[i] != r[i]) {
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        cout << 2 * n << "\n";
        return;
    }
    int ans = 2 * ind;
    if(abs(l[ind] - r[ind]) > 1) {
        cout << ans << "\n";
        return;
    }
    int i = ind + 1;
    while(i < n) {
        if(r[i] == '0' && l[i] == '9') {
            ans++;
            i++;
        }
        else break;
    }
    cout << ans + 1 << "\n";

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