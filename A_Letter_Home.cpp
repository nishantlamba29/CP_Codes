#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    if(s >= v.back()) {
        cout << s - v[0] << "\n";
    }
    else if(s <= v[0]) {
        cout << v[n-1] - s << "\n";
    }
    else {
        int t1 = s - v[0] + v[n-1] - v[0];
        int t2 = v[n-1] - s + v[n-1] - v[0];
        cout << min(t1, t2) << "\n";
    }


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