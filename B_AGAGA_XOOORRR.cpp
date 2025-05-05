#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> pre(n), v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    pre[0] = v[0];
    for(int i=1;i<n;i++) pre[i] = pre[i-1] ^ v[i];
    if(pre[n-1] == 0) {
        cout << "YES\n";
        return;
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n-1;j++) {
            int ff = pre[i];
            int ss = pre[j] ^ pre[i];
            int tt = pre[n-1] ^ pre[j];
            if(ff == ss && ff == tt) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
    
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