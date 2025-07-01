#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> pre = v, suff = v;
    for(int i=1;i<n;i++) pre[i] = min(pre[i], pre[i-1]);
    for(int i=n-2;i>=0;i--) suff[i] = max(suff[i], suff[i+1]);

    for(int i=0;i<n;i++) {
        if(v[i] == pre[i] || v[i] == suff[i]) cout << 1;
        else cout << 0;
    }
    cout << "\n";

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