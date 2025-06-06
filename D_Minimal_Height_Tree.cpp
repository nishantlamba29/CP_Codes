#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    vector<int> help(n);
    int level = 0;
    for(int i=1;i<n;i++) {
        if(v[i-1] > v[i]) {
            level++;
        }
        help[i] = help[level] + 1;
    }
    cout << help[n-1] << "\n";

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