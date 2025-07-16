#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    int su = 0, mx = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        su += v[i];
        mx = max(mx, v[i]);
    }
    if(su & 1 || 2*mx > su) {
        cout << "-1\n";
        return;
    }

    int ind = -1;
    int pre = 0;
    for(int i=0;i<n;i++) {
        pre += v[i];
        if(pre == su / 2) {
            cout << "1\n";
            for(auto it : v) cout << it << " ";
            cout << "\n";
            return;
        }
        else if(pre > su / 2) {
            ind = i;
            break;
        }
    }
    vector<int> b(n);
    int extra = pre - su / 2;
    /*
    h = s/2
    h + delta initially = pre
    h - delta  was suff
    so we remove 2 delta from pre to make h - delta = h-delta
    
    */
    b[ind] = extra;
    for(int i=0;i<ind;i++) {
        b[i] = min(v[i], extra);
        extra -= b[i];
    }
    cout << "2\n";
    for(auto it : b) cout << it << " "; cout << "\n";
    for(int i=0;i<n;i++) cout << v[i] - b[i] << " "; cout << "\n";
    return;
    
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