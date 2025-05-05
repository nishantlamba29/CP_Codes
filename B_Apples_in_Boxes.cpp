#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int sum = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.rbegin(), v.rend());
    v[0]--;
    sort(v.rbegin(), v.rend());
    int mx = v[0], mn = v[n-1]; 
    if(mx - mn > k) {
        cout << "Jerry\n";
        return;
    }
    sum--;
    if(sum % 2 == 0) cout << "Tom\n";
    else cout << "Jerry\n";
    

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