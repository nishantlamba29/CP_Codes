#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int maxi = *max_element(v.begin(), v.end());
    bool flag = 0;
    for(int i=0;i<n-1;i++) {
        if(v[i] != v[i+1]) flag = 1;
    }
    if(flag == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i=0;i<n;i++) {
        if(v[i] == maxi) cout << 1 <<" ";
        else cout << 2 << " ";
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